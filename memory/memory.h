#ifndef MEMORY_H
#define MEMORY_H

namespace memory
{
    class Memory
    {
    public:
        Memory();
        ~Memory();

    private:
        char m_storage[8192];
    };
}
#endif
