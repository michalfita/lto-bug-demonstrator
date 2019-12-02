#include "hornet.h"

void hornet_item::modify_item(int z)
{
    m_item = z;
}

hornet::hornet(int c) : m_data(c)
{}

int hornet::violate(int z) 
{
    int m = z + violator;
    m_data.push_back(hornet_item{});
    m_data.front().modify_item(m);
    return m;
}

bool hornet::set_offset(const std::chrono::minutes time_offset)
{
    if (time_offset > hornet_interface::MaxOffset || time_offset < hornet_interface::MinOffset)
        return false;

    m_time_offset = time_offset;
    return true;
}

const std::chrono::minutes hornet_interface::MinOffset;
const std::chrono::minutes hornet_interface::MaxOffset;
