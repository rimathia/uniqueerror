#include <registry/registry.h>
#include <checked_division/checked_division.h>
#include <checked_addition/checked_addition.h>

#include <iostream>
#include <limits>

int main(int argc, char **argv)
{
    std::cerr << "main\n";
    CHECK(argc == 1, 42);
    divide(1, 0);
    add(std::numeric_limits<std::int32_t>::max(), std::numeric_limits<std::int32_t>::max());
}
