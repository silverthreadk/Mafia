#include "client.cpp"

int main(){
	boost::asio::io_service io_context;
	Client c(io_context, "127.0.0.1", "2580");
	io_context.run();

	return 0;
}
