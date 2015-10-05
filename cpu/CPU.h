#ifndef CPU_H
#define CPU_H

#include "instructions.h"
#include "../memory/memory.h"
#include "../utils/singleton.h"

namespace cpu
{
    class CPU:
        public Singleton<CPU>
    {

    private:
        struct Registers
        {
            unsigned char A;
            unsigned char F;
            unsigned char B;
            unsigned char C;
            unsigned char D;
            unsigned char E;
            unsigned char H;
            unsigned char L;
            char16_t SP;
            char16_t PC;
        };

    public:
        CPU();
        ~CPU();

        void debugRegisters();

        void exec(MainInstructions instr, Sets set = Sets::MAIN);

    private:
        Registers m_registers;
        unsigned char Z();
        unsigned char N();
        unsigned char H();
        unsigned char C();

        void setZ(char f);
        void setN(char f);
        void setH(char f);
        void setC(char f);
    };
}
#endif
