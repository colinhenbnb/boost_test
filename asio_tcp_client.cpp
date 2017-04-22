/*************************************************************************
	> File Name: asio_tcp_client.cpp
	> Author: heshaofu
	> Mail: heshaofu@douyu.tv
	> Created Time: Sat 22 Apr 2017 12:48:12 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
#include<boost/asio/ip/tcp.hpp>
#include<boost/asio/ip/tcp.hpp>
#include<boost/asio.hpp>
using namespace boost::asio;

int main()
{
    try {
        typedef ip::tcp::acceptor acceptor_type;
        typedef ip::tcp::endpoint endpoint_type;
        typedef ip::tcp::socket socket_type;
        typedef ip::address address_type;

        cout << "client start" <<endl;
        io_service io;
        socket_type sock(io);
        endpoint_type ep(
            address_type::from_string("127.0.0.1"), 6688
            );
        sock.connect(ep);
        cout << sock.available()<<endl;
        vector<char> str(sock.available()+1, 0);
        sock.receive(buffer(str));
        cout << "recv from " << sock.remote_endpoint().address();
        cout<< &str[0] << endl;
        
    }
    catch (std::exception& e){
        cout << e.what() << endl;

    }
}
