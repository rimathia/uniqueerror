#ifndef REGISTRY_H
#define REGISTRY_H

int register_error(int error_number);
[[noreturn]] void throw_error(int error_number);

#define CHECK(condition, code)                                              \
    do                                                                      \
    {                                                                       \
        struct R                                                            \
        {                                                                   \
            void r() __attribute__((constructor)) { register_error(code); } \
        };                                                                  \
        if (!(condition))                                                   \
        {                                                                   \
            throw_error(code);                                              \
        }                                                                   \
    } while (false)

#endif
