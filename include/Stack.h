#pragma once

#include <iostream>

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
            std::cout << "Stack is full!" << std::endl;
            return;
        }

        m_Stack[m_Index] = byte;
        m_Index++;
    }

    unsigned char Pop()
    {
        if (m_Index == 0)
        {
            std::cout << "Stack is empty!" << std::endl;
            return 0x00;
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