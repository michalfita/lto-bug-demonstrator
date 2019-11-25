#ifndef HORNET_INTERFACE_H
#define HORNET_INTERFACE_H
#include <chrono>

using namespace std::literals::chrono_literals;

class hornet_interface {
  public:
    static constexpr std::chrono::minutes MinOffset = -720min;
    static constexpr std::chrono::minutes MaxOffset = 840min;

    virtual bool set_offset(std::chrono::minutes timeZoneOffset) = 0;
};

#endif // HORNET_INTERFACE_H
