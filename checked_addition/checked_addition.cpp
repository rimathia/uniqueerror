#include <checked_addition/checked_addition.h>

#include <limits>

#include <registry/registry.h>

std::int32_t add(std::int32_t x, std::int32_t y)
{
    std::int64_t sum = x;
    sum += y;
    CHECK(sum <= std::numeric_limits<std::int32_t>::max(), 13);
    return sum;
}