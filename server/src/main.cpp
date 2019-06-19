#include "server.h"
#include <unistd.h>

int main(){
	boost::asio::io_service io_service;
	Server server(io_service, 2580);
	io_service.run();

	return 0;
}
