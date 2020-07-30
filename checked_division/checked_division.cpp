#include <checked_division/checked_division.h>

#include <registry/registry.h>

int divide(int x, int y)
{
    CHECK(y != 0, 21);
    return x / y;
}