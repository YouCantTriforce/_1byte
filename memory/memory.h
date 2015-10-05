#ifndef MEMORY_H
#define MEMORY_H

#include "../utils/singleton.h"
#include "memory_locations.h"

namespace memory
{
    class Memory:
        public Singleton<Memory>
    {
    public:
        Memory();
        ~Memory();

    public:
        char readByte(char& address, const char& byte);
        void writeByte(char& address, const char& byte);

    private:
        char m_storage[8192];
    };
}
#endif
