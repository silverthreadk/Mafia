#ifndef server_h_
#define server_h_

#include <boost/asio.hpp>
#include <boost/bind.hpp>

using boost::asio::ip::tcp;

class Session;

class Server {
public:
    Server(boost::asio::io_service& io_service, short port);

private:
    boost::asio::io_service& service_;
    tcp::acceptor acceptor_;

    void accept();
    void handle_accept(Session* pSession, const boost::system::error_code& error);
};

#endif
