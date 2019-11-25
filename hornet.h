#ifndef HORNET_H
#define HORNET_H
#include <list>
#include <chrono>
#include "hornet_interface.h"

class hornet_item {
  public:
    hornet_item() : m_item(3) {}
    int get_item() const { return m_item; }
    void modify_item(int z);
  private:
    int m_item;
};

class hornet : public hornet_interface {
  public:
    hornet(int c);
    int get_item(int i) { return m_data.back().get_item(); }
    int violate(int z);
    virtual bool set_offset(std::chrono::minutes timeZoneOffset);

  private:
    static constexpr int violator = 666;
    std::list<hornet_item> m_data;
    std::chrono::minutes m_time_offset;
};
#endif // HORNET_H
