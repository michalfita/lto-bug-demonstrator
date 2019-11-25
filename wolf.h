#pragma once
#include <vector>

class wolf_item {
  public:
    wolf_item() : m_item(5) {}
    long get_item() const;
  private:
    long m_item;
};

class wolf {
  public:
    wolf(int c);
    virtual bool vmethod(const wolf_item&);
  private:
    std::vector<wolf_item> m_data;
};