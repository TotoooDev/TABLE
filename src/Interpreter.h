#pragma once

#include <iostream>

#include "Bytecode.h"
#include "Stack.h"
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
            {
                std::cout << "NOOP" << std::endl;
                break;
            }

            case LITERAL:
            {
                unsigned char value = bytes[++i];
                m_Stack.Push(value);
                std::cout << "Literal of value " << (int)value << " pushed to the stack" << std::endl;
                break;
            }

            case ADD:
            {
                unsigned char a = m_Stack.Pop();
                unsigned char b = m_Stack.Pop();
                m_Stack.Push(a + b);
                std::cout << "Added " << (int)a << " and " << (int)b << std::endl;
                break;
            }

            case SUBTRACT:
            {
                unsigned char a = m_Stack.Pop();
                unsigned char b = m_Stack.Pop();
                m_Stack.Push(a - b);
                std::cout << "Subtracted " << (int)a << " to " << (int)b << std::endl;
                break;
            }

            case MULTIPLY:
            {
                unsigned char a = m_Stack.Pop();
                unsigned char b = m_Stack.Pop();
                m_Stack.Push(a * b);
                std::cout << "Multiplied " << (int)a << " and " << (int)b << std::endl;
                break;
            }

            case DIVIDE:
            {
                unsigned char a = m_Stack.Pop();
                unsigned char b = m_Stack.Pop();
                m_Stack.Push(a / b);
                std::cout << "Divided " << (int)a << " by " << (int)b << std::endl;
                break;
            }

            default:
                break;
            }
        }
    }

private:
    Stack m_Stack;
};