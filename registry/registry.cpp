#include <registry/registry.h>

#include <set>

#include <fmt/chrono.h>

auto x = register_error(0);

std::set<int> &get_registered_errors()
{
    static std::set<int> registered_errors;
    return registered_errors;
};

int register_error(int error_number)
{
    auto &registry = get_registered_errors();
    if (registry.find(error_number) != registry.end())
    {
        const auto message = "error " + std::to_string(error_number) + " already registered";
        fmt::print(stderr, message);
        throw std::logic_error(message);
    }
    registry.insert(error_number);
    std::time_t t = std::time(nullptr);
    fmt::print(stderr, "registered error number {} at {:%Y-%m-%d:%H-%M-%S}\n", error_number, fmt::localtime(t));
    return error_number;
}

[[noreturn]] void throw_error(int error_number)
{
    const auto &registry = get_registered_errors();
    if (registry.find(error_number) == registry.end())
    {
        fmt::print(stderr, "error {} isn't registered\n", error_number);
        throw_error(0);
    }
    throw std::logic_error(std::to_string(error_number));
}
