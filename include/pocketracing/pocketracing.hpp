#pragma once

#include "config.hpp"
#include <chrono>

namespace pocketracing
{

class POCKETRACING_API server
{
  private:
    void *impl_;

  public:
    server(unsigned short port);

  public:
    void run();
    void run_for(std::chrono::duration<std::chrono::steady_clock::rep,
                                       std::chrono::steady_clock::period>
                     duration);
    unsigned short get_port() const;
};

} // namespace pocketracing
