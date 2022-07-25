#pragma once

#include <iostream>

#include "Bytecode.h"
#include "Stack.h"
#include "VariableStack.h"
#include "Instructions.h"
#include "Log.h"

class Interpreter
{
public:
    void Interpret(Bytecode bytecode)
    {
        Preprocess(bytecode);

        unsigned int size = bytecode.GetSize();
        // Loop through every instruction in the bytecode
        for (unsigned int i = 0; i < size; i++)
        {
            if (Logger::Get().HasWarnings())
            {
                for (auto& warning : Logger::Get().GetWarnings())
                {
                    std::cout << warning << std::endl;
                }
            }
            if (Logger::Get().HasErrors())
            {
                for (auto& error : Logger::Get().GetErrors())
                {
                    std::cout << error << std::endl;
                }
                break;
            }

            switch (bytecode[i])
            {
            case LITERAL:
            {
                unsigned char value = bytecode[++i];
                m_Stack.Push(value);
                break;
            }

            case POP:
            {
                m_Stack.Pop();
                break;
            }

            case ADD:
            {
                unsigned char a = m_Stack.Pop();
                unsigned char b = m_Stack.Pop();
                m_Stack.Push(a + b);
                break;
            }

            case SUBTRACT:
            {
                unsigned char a = m_Stack.Pop();
                unsigned char b = m_Stack.Pop();
                m_Stack.Push(a - b);
                break;
            }

            case MULTIPLY:
            {
                unsigned char a = m_Stack.Pop();
                unsigned char b = m_Stack.Pop();
                m_Stack.Push(a * b);
                break;
            }

            case DIVIDE:
            {
                unsigned char a = m_Stack.Pop();
                unsigned char b = m_Stack.Pop();
                m_Stack.Push(a / b);
                break;
            }

            case STORE:
            {
                unsigned char slot = m_Stack.Pop();
                unsigned char value = m_Stack.Pop();
                m_Variables.SetSlot(slot, value);
                break;
            }

            case GET:
            {
                unsigned char slot = m_Stack.Pop();
                unsigned char value = m_Variables.GetValue(slot);
                m_Stack.Push(value);
                break;
            }

            case JUMP:
            {
                unsigned char adress = m_Stack.Pop();
                i = adress;
                break;
            }

            case JUMP_NZ:
            {
                unsigned char condition = m_Stack.Pop();
                unsigned char adress = m_Stack.Pop();
                if (condition != 0)
                {
                    i = adress - 1;
                }
                break;
            }

            case START_IF:
            {
                // Find the closest END_IF to jump to
                unsigned int adress = 0;
                for (int j = i; j < size; j++)
                {
                    if (bytecode[j] == END_IF)
                    {
                        adress = j;
                        break;
                    }
                }

                unsigned char condition = m_Stack.Pop();
                if (!condition)
                {
                    i = adress - 1;
                }
                break;
            }

            case NOOP:
            case END_IF:
            default:
                break;
            }
        }
    }

private:
    void Preprocess(Bytecode bytecode)
    {
        unsigned int size = bytecode.GetSize();
        unsigned int numStartIf = 0;
        unsigned int numEndIf = 0;
        for (unsigned int i = 0; i < size; i++)
        {
            switch (bytecode[i])
            {
            case START_IF:
            {
                numStartIf++;
                break;
            }

            case END_IF:
            {
                numEndIf++;
                break;
            }

            default:
                break;
            }
        }
        if (numStartIf != numEndIf)
        {
            Logger::Get().AddError(NO_MATCHING_END_IF);
        }
    }

    Stack m_Stack;
    VariableStack m_Variables;
};