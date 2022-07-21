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
        // Loop through every instruction in the bytecode
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

            case POP:
            {
                m_Stack.Pop();
                std::cout << "Popped a value from the stack" << std::endl;
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
                std::cout << "Subtracted " << (int)b << " to " << (int)a << std::endl;
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

            case JUMP:
            {
                unsigned char adress = m_Stack.Pop();
                i = adress;
                std::cout << "Jumped to adress " << (int)adress << std::endl;
                break;
            }

            case JUMP_NZ:
            {
                unsigned char condition = m_Stack.Pop();
                unsigned char adress = m_Stack.Pop();
                if (condition != 0)
                {
                    i = adress - 1;
                    std::cout << "Jumped to adress " << (int)adress << ", condition was " << (int)condition << std::endl;
                }
                else
                {
                    std::cout << "Did not jump to adress " << (int)adress << ", condition was " << (int)condition << std::endl;
                }
                break;
            }

            case START_IF:
            {
                // Find the closest END_IF to jump to
                int adress = -1;
                for (int j = i; j < size; j++)
                {
                    if (bytecode[j] == END_IF)
                    {
                        adress = j;
                        break;
                    }
                }
                if (adress == -1)
                {
                    std::cout << "No closing END_IF!" << std::endl;
                    break;
                }

                unsigned char condition = m_Stack.Pop();
                if (!condition)
                {
                    i = adress - 1;
                }
                break;
            }

            case END_IF:
            default:
                break;
            }
        }
    }

private:
    Stack m_Stack;
    VariableStack m_Variables;
};