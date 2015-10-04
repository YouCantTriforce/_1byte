#ifndef CPU_H
#define CPU_H

#include "instructions.h"

namespace cpu
{
    class CPU
    {

    private:
        struct Registers
        {
            char A;
            char F;
            char B;
            char C;
            char D;
            char E;
            char H;
            char L;
            char16_t SP;
            char16_t PC;
        };

        struct Flags
        {
            bool Z;
            bool N;
            bool H;
            bool C;
            bool null_0;
            bool null_1;
            bool null_2;
            bool null_3;
        };

    public:
        CPU();
        ~CPU();

    private:
        Registers m_registers;
        Flags m_flags;

    };
}
#endif
