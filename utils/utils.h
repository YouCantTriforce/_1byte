#ifndef UTILS_H
#define UTILS_H

#include <cassert>

static void bin(int value, char* result, int base, int length = 9) //remember about space for null character
{
    assert(base <= 16 && base >= 2);

    int ptr = length - 2;

    result[length - 1] = '\0';
    int res;
    do
    {
        res = value % base;
        switch(res)
        {
            case 10:
                result[ptr] = 'A';
                break;

            case 11:
                result[ptr] = 'B';
                break;

            case 12:
                result[ptr] = 'C';
                break;
            case 13:
                result[ptr] = 'D';
                break;
            case 14:
                result[ptr] = 'E';
                break;

            case 15:
                result[ptr] = 'F';
                break;

            default:
                result[ptr] = res + 48;
                break;
        }

        value /= base;
        ptr--;
    }
    while(value > 0 && ptr >= 0);

    while(ptr >= 0)
    {
        result[ptr] = 48;
        ptr--;
    }
}

#endif
