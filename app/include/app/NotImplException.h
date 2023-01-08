#pragma once

#include <stdexcept>

namespace training
{
  class NotImplException : public std::runtime_error
  {
  public:
    NotImplException() : std::runtime_error("Not Implemented") {}
  };
}