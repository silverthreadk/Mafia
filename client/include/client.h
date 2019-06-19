#ifndef client_h_
#define client_h_

#include <boost/asio.hpp>
#include <iostream>
#include <boost/bind.hpp>
#include <unistd.h>

using boost::asio::ip::tcp;

class Client {
public:
    Client(boost::asio::io_service& io_context, const std::string& host, const std::string& port);

    void handle_connect(const boost::system::error_code& e);
    void handle_write(const boost::system::error_code& e);
private:
    tcp::socket socket_;
    char data_[1024];
};

#endif
