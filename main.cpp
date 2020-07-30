#include <registry/registry.h>
#include <checked_division/checked_division.h>

const auto x = register_error(42);

int main(int argc, char **argv)
{
    if (argc != 1)
    {
        throw_error(42);
    }
    divide(1.0, 0.0);
}
