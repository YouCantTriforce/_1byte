#include "memory.h"

#include <iostream>

namespace memory
{
    Memory::Memory()
    {
        std::cout << "memory online" << std::endl;
    }

    Memory::~Memory()
    {
    }

    char Memory::readByte(char& address, const char& byte)
    {
        //TODO implement
    }

    void Memory::writeByte(char& address, const char& byte)
    {
        //TODO implement
    }
}
