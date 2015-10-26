#include "CPU.h"

#include <iostream>
#include <stdio.h>
#include <cassert>
#include "../utils/utils.h"

namespace cpu
{
    CPU::CPU()
    {
        m_registers.PC = 0x0100;
        m_registers.SP = 0xFFFE;

        m_registers.A = 128;
        setZ(1);
        setC(1);
        setZ(0);
        setZ(0);
        std::cout << "cpu online" << std::endl;
        debugRegisters();
        exec(MainInstructions::ADC_AA, Sets::CB);

        char binary[17];
        bin(AF(), binary, 2, 17);
        printf("%s\n", binary);
    }

    CPU::~CPU()
    {

    }

    void CPU::debugRegisters()
    {
        char binary[15];
        bin(m_registers.A, binary, 2);
        std::cout << "A:  " << binary << std::endl;

        bin(m_registers.F, binary, 2);
        std::cout << "F:  " << binary << std::endl;

        bin(m_registers.B, binary, 2);
        std::cout << "B:  " << binary << std::endl;

        bin(m_registers.C, binary, 2);
        std::cout << "C:  " << binary << std::endl;

        bin(m_registers.D, binary, 2);
        std::cout << "D:  " << binary << std::endl;

        bin(m_registers.E, binary, 2);
        std::cout << "E:  " << binary << std::endl;

        bin(m_registers.H, binary, 2);
        std::cout << "H:  " << binary << std::endl;

        bin(m_registers.L, binary, 2);
        std::cout << "L:  " << binary << std::endl;

        bin(m_registers.SP, binary, 16, 5);
        std::cout << "SP: " << binary << std::endl;

        bin(m_registers.PC, binary, 16, 5);
        std::cout << "PC: " << binary << std::endl;


        std::cout << "Z-flag: " << (int)Z() << std::endl;
        std::cout << "N-flag: " << (int)N() << std::endl;
        std::cout << "H-flag: " << (int)H() << std::endl;
        std::cout << "C-flag: " << (int)C() << std::endl;
    }


    void CPU::exec(MainInstructions instr, Sets set)
    {
        switch(set)
        {
            case Sets::MAIN:
            {
                switch(instr)
                {
                    default:
                        printf("Unimplemented instruction: %#02x\n", instr);
                }
            }
            break;

            case Sets::CB:
            {
                printf("CB set is empty\n");
            }
            break;

            case Sets::DD:
            {
                printf("DD set is empty\n");
            }
            break;
        }
    }

    unsigned char CPU::Z()
    {
        return (m_registers.F >> 7) & 1;
    }

    unsigned char CPU::N()
    {
        return (m_registers.F >> 6) & 1;
    }

    unsigned char CPU::H()
    {
        return (m_registers.F >> 5) & 1;
    }

    unsigned char CPU::C()
    {
        return (m_registers.F >> 4) & 1;
    }

    char16_t CPU::AF()
    {
        char16_t y = 0, x = 0;;
        y = m_registers.A;
        y <<= 8;
        x = m_registers.F;
        y |= x;
        return y;
    }

    char16_t CPU::BC()
    {
        char16_t y = 0, x = 0;;
        y = m_registers.B;
        y <<= 8;
        x = m_registers.C;
        y |= x;
        return y;
    }

    char16_t CPU::DE()
    {
        char16_t y = 0, x = 0;;
        y = m_registers.D;
        y <<= 8;
        x = m_registers.E;
        y |= x;
        return y;
    }

    char16_t CPU::HL()
    {
        char16_t y = 0, x = 0;;
        y = m_registers.H;
        y <<= 8;
        x = m_registers.L;
        y |= x;
        return y;
    }

    void CPU::setZ(char f)
    {
        m_registers.F ^= (-7 ^ m_registers.F) & (f << 7);
    }

    void CPU::setN(char f)
    {
        m_registers.F ^= (-6 ^ m_registers.F) & (f << 6);
    }

    void CPU::setH(char f)
    {
        m_registers.F ^= (-5 ^ m_registers.F) & (f << 5);
    }

    void CPU::setC(char f)
    {
        m_registers.F ^= (-4 ^ m_registers.F) & (f << 4);
    }

}
