#pragma once

#include <iostream>

#include "Log.h"

class Stack
{
public:
    const static unsigned int MaxSize = 1024;

    Stack()
    {
        for (unsigned int i = 0; i < MaxSize; i++)
        {
            m_Stack[i] = 0x00;
        }
    }

    void Push(unsigned char byte)
    {
        if (m_Index == MaxSize - 1)
        {
            Logger::Get().AddError(STACK_OVERFLOW);
            return;
        }

        m_Stack[m_Index] = byte;
        m_Index++;
    }

    unsigned char Pop()
    {
        if (m_Index == 0)
        {
            Logger::Get().AddError(STACK_UNDERFLOW);
            return 0xFF;
        }

        m_Index--;
        unsigned char value = m_Stack[m_Index];
        m_Stack[m_Index] = 0x00;
        return value;
    }

private:
    unsigned int m_Index = 0;
    unsigned char m_Stack[1024];
};