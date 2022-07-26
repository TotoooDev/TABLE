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

            #pragma region STACK_INSTRUCTIONS
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
            #pragma endregion STACK_INSTRUCTIONS

            #pragma region OPERATIONS
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
            #pragma endregion OPERATIONS

            #pragma region VARIABLES
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
            #pragma endregion VARIABLES

            #pragma region JUMP_AND_CONDITIONS
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
                for (unsigned int j = i; j < size; j++)
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
            #pragma endregion JUMP_AND_CONDITIONS

            #pragma region INPUT_OUTPUT
            case USER_CHAR:
            {
                unsigned char value;
                std::cin >> value;
                m_Stack.Push(value);
                break;
            }
            case USER_INT:
            {
                unsigned int value;
                std::cin >> value;
                m_Stack.Push(value);
                break;
            }
            case OUTPUT:
            {
                unsigned char value = m_Stack.Pop();
                std::cout << value << std::endl;
                break;
            }
            case OUTPUT_INT:
            {
                unsigned int value = m_Stack.Pop(); // Wat
                std::cout << value << std::endl;
                break;
            }
            #pragma endregion INPUT_OUTPUT

            #pragma region OPERATORS
            case EQUAL:
            {
                unsigned char a = m_Stack.Pop();
                unsigned char b = m_Stack.Pop();
                if (a == b)
                {
                    m_Stack.Push(0x01);
                    break;
                }
                m_Stack.Push(0x00);
                break;
            }
            case NOT:
            {
                unsigned char a = m_Stack.Pop();
                unsigned char b = m_Stack.Pop();
                if (a != b)
                {
                    m_Stack.Push(0x01);
                    break;
                }
                m_Stack.Push(0x00);
                break;
            }
            case LESS:
            {
                unsigned char a = m_Stack.Pop();
                unsigned char b = m_Stack.Pop();
                if (a < b)
                {
                    m_Stack.Push(0x01);
                    break;
                }
                m_Stack.Push(0x00);
                break;
            }
            case MORE:
            {
                unsigned char a = m_Stack.Pop();
                unsigned char b = m_Stack.Pop();
                if (a > b)
                {
                    m_Stack.Push(0x01);
                    break;
                }
                m_Stack.Push(0x00);
                break;
            }
            case LESS_EQ:
            {
                unsigned char a = m_Stack.Pop();
                unsigned char b = m_Stack.Pop();
                if (a <= b)
                {
                    m_Stack.Push(0x01);
                    break;
                }
                m_Stack.Push(0x00);
                break;
            }
            case MORE_EQ:
            {
                unsigned char a = m_Stack.Pop();
                unsigned char b = m_Stack.Pop();
                if (a >= b)
                {
                    m_Stack.Push(0x01);
                    break;
                }
                m_Stack.Push(0x00);
                break;
            }
            #pragma endregion OPERATORS

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