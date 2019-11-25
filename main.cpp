#include "wolf.h"
#include "hornet.h"

using namespace std::literals::chrono_literals;

int main(int argc, char* argv[])
{
    wolf w{7};
    hornet h{5};

    wolf_item wi;

    w.vmethod(wi);

    h.violate(13);
    h.set_offset(17min);

    return 0;
}