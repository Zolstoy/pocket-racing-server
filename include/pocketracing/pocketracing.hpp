#pragma once

#include "config.hpp"

namespace pocketracing
{

class POCKETRACING_API server
{
  private:
    void *impl_;

  public:
    server(unsigned short port);
    ~server();
};

} // namespace pocketracing
