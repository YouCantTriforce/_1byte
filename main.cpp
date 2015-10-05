#include <iostream>
#include "cpu/CPU.h"
#include "memory/memory.h"
#include <cassert>

static bool check_le()
{
    const uint8_t array[4] = { 44, 1, 0, 0 };

    assert(sizeof(array) == sizeof(uint32_t));
    return reinterpret_cast<const uint32_t&>(array[0]) == 300;
}

int main(int argc, char** argv)
{
    if(!check_le())
    {
        std::cout << "Unsupported architecture (big-endian)" << std::endl;
        return 1;
    }

    cpu::CPU::instance();
    memory::Memory::instance();



    return 0;
}
