/*************************************************************************
	> File Name: asio_test.cpp
	> Author: heshaofu
	> Mail: heshaofu@douyu.tv
	> Created Time: Fri 21 Apr 2017 11:51:04 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
#define BOOST_ASI_DISABLE_STD_CHRONO
#include<boost/asio.hpp>
#include<boost/asio/steady_timer.hpp>
using namespace boost::asio;

void cb()
{
    cout<<"hello world " << endl;
}

int main()
{
    io_service io;
    steady_timer t(io, 500);
    //t.async_wait(cb);
    t.async_wait([](const error_code& ec){ cout<< "hello world"<<endl; });
    io.run();
}
