#ifndef server_h_
#define server_h_

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <vector>

using boost::asio::ip::tcp;

class session {
public:
    session(tcp::socket& socket);
    ~session();
    void read();
private:
    void handleRead(const boost::system::error_code& error, size_t bytes_transferred);

    tcp::socket socket_;
}

class server {
public:
    server(const int port);
    ~server();

    void run();
private:
    boost::asio::io_service service_;
    tcp::acceptor acceptor_;
    int port_;

    void accept();
    void handleAccept();
};

#endif
