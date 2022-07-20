#pragma once

#include <iostream>

#include "Bytecode.h"
#include "Instructions.h"

class Interpreter
{
public:
    void Interpret(Bytecode bytecode)
    {
        unsigned int size = bytecode.GetSize();
        unsigned char* bytes = bytecode.GetBytes();
        for (unsigned int i = 0; i < size; i++)
        {
            switch (bytes[i])
            {
            case NOOP:
                std::cout << "NOOP" << std::endl;
                break;

            default:
                break;
            }
        }
    }

private:

};