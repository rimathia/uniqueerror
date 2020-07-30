#include <iostream>

static int global_array[10];

void global_init(int i)
{
    std::cerr << "global_init i =  " << i << "\n";
    global_array[i] = 1;
}

__attribute__((constructor)) void init() { global_init(2); };

int main()
{
    struct Loc
    {
        static void f() __attribute__((constructor)) { global_init(3); };
    };
    std::cerr << "main\n";
}