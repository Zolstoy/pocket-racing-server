#include "pocketracing.hpp"

#include <asio/io_context.hpp>
#include <asio/ip/tcp.hpp>
#include <print>

class server_impl
{
  public:
    asio::io_context io_context;
    // asio::ip::tcp::acceptor acceptor;

  public:
    server_impl(unsigned short port)
    {
        std::println("ok");
    }

    ~server_impl()
    {
    }
};

namespace pocketracing
{
server::server(unsigned short port)
{
}

server::~server()
{
}
} // namespace pocketracing
