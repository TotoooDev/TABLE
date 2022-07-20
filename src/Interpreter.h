#pragma once

#include <iostream>

#include "Bytecode.h"
#include "Stack.h"
#include "VariableStack.h"
#include "Instructions.h"

class Interpreter
{
public:
    void Interpret(Bytecode bytecode)
    {
        unsigned int size = bytecode.GetSize();
        for (unsigned int i = 0; i < size; i++)
        {
            switch (bytecode[i])
            {
            case NOOP:
            {
                std::cout << "NOOP" << std::endl;
                break;
            }

            case LITERAL:
            {
                unsigned char value = bytecode[++i];
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

            case STORE:
            {
                unsigned char slot = m_Stack.Pop();
                unsigned char value = m_Stack.Pop();
                m_Variables.SetSlot(slot, value);
                std::cout << "Stored value " << (int)value << " in slot " << (int)slot << std::endl;
                break;
            }

            case GET:
            {
                unsigned char slot = m_Stack.Pop();
                unsigned char value = m_Variables.GetValue(slot);
                m_Stack.Push(value);
                std::cout << "Got value " << (int)value << " from slot " << (int)slot << std::endl;
                break;
            }

            default:
                break;
            }
        }
    }

private:
    Stack m_Stack;
    VariableStack m_Variables;
};