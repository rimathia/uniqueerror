#ifndef REGISTRY_H
#define REGISTRY_H

int register_error(int error_number);
[[noreturn]] void throw_error(int error_number);

#endif
