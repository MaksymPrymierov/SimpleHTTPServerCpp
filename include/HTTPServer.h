#pragma once

#include <boost/asio.hpp>
#include <string>

namespace SimpleHTTPServer {

    namespace net = boost::asio;
    using tcp = net::ip::tcp;

    class HTTPServer {
    public:
        HTTPServer(const std::string &_ipAddress, const unsigned short _port);

        void start();

    private:
        net::io_context m_ioc{1};
        tcp::acceptor m_acceptor;
    };

}