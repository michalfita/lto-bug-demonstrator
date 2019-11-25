#include "wolf.h"

long wolf_item::get_item() const
{
    return m_item;
}

wolf::wolf(int c) : m_data(c)
{}

bool wolf::vmethod(const wolf_item& item)
{
    m_data[0] = item;
    return true;
}