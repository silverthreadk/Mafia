#include "server.h"
#include <iostream>

class Session {
public:
    Session(boost::asio::io_service& io_service)
     :socket_(io_service)
    {
    }

    tcp::socket& socket() {
        return socket_;
    }

    void start() {
        socket_.async_read_some(boost::asio::buffer(data_, 1024),
            boost::bind(&Session::handle_read, this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
    }
private:
    void handle_read(const boost::system::error_code& error, size_t bytes_transferred) {
        // 메세지가 도착하면 호출되는 핸들러
        if (error) {
            delete this;
        } else {
            std::cout << data_ << std::endl;
        }
    }

    tcp::socket socket_;
    char data_[1024];
};

Server::Server(boost::asio::io_service& io_service, short port)
: service_(io_service),
  acceptor_(io_service, tcp::endpoint(tcp::v4(), port))
{
    accept();
}

void Server::accept() {
    Session* pSession = new Session(service_);
    acceptor_.async_accept(pSession->socket(), boost::bind(&Server::handle_accept, this, pSession, boost::asio::placeholders::error));
}

void Server::handle_accept(Session* pSession, const boost::system::error_code& error) {
    // client가 접속하면 호출되는 핸들러
    if (error) {
        delete pSession;
    } else {
        pSession->start();
    }
    accept();
}

