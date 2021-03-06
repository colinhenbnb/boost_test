/*************************************************************************
	> File Name: asio_tcp_server.cpp
	> Author: heshaofu
	> Mail: heshaofu@douyu.tv
	> Created Time: Sat 22 Apr 2017 12:21:33 AM PDT
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
        cout << "server start" <<endl;
        io_service io;
        acceptor_type acceptor(io,
                               endpoint_type(ip::tcp::v4(), 6688));
        cout << acceptor.local_endpoint().address() <<endl;
        for (;;) 
        {
            socket_type sock(io);
            acceptor.accept(sock);
            cout << "client:";
            cout << sock.remote_endpoint().address() <<endl;
            sock.send(buffer("hello asio, welcome connect\n"));
        }
        
    }
    catch (std::exception& e){
        cout << e.what() << endl;

    }
}
