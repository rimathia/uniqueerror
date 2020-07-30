#include <checked_division/checked_division.h>

#include <registry/registry.h>

static auto r = register_error(21);

double divide(double x, double y)
{
    if (y == 0.0)
    {
        throw_error(21);
    }
    return x / y;
}