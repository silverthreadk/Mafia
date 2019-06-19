#include "client.h"

Client::Client(boost::asio::io_service& io_context, const std::string& host, const std::string& port) : socket_(io_context)
{
    boost::asio::ip::tcp::resolver resolver(io_context);
    boost::asio::ip::tcp::resolver::query query(host, port);
    boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

    boost::asio::async_connect(socket_, endpoint_iterator, boost::bind(&Client::handle_connect, this, boost::asio::placeholders::error));
}

void Client::handle_connect(const boost::system::error_code& e) {
    // 서버와 연결되면 호출되는 핸들러
    if (!e) {
        std::string msg = "Hello";
        boost::asio::async_write(socket_, boost::asio::buffer(msg, msg.length()),
            boost::bind(&Client::handle_write, this, boost::asio::placeholders::error));
    } else {
        std::cout << "connect error" << std::endl;
    }
}

void Client::handle_write(const boost::system::error_code& e) {
    // 메세지 보내기가 완료되면 호출되는 핸들러
}
