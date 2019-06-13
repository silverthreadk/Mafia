#include "server.h"
//*************************************
// session
//*************************************
session::session(tcp::socket& socket)
    : socket_(socket)
{}

session::~session() {
}

void session::read() {
}

void session::handleRead(const boost::system::error_code& error, size_t bytes_transferred) {
}

//*************************************
// server
//*************************************
server::server(const int port) {
    acceptor_(serviece_, tcp::endpoint(tcp::v4(), port));
}

server::~server() {
}

void server::run() {
    accept();
}

void server::accept() {
    tcp::socket socket(service_);
    sockets_.push_back(socket);
    acceptor_.async_accept(socket, boost::bind(&server::handleAccept, this, boost::asio::placeholders::error));
}

void server::handleAccept(const boost::system::error_code& error) {
    if (error) {
        // connect 실패
        return;
    }

    tcp::socket(service_);
    session* pSession = new session(socket);
    pSession->read();
}

#endif
