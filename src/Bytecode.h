#pragma once

#include <iterator>

class Bytecode
{
public:
    template <unsigned int N>
    void Create(unsigned char bytes[N])
    {
        m_Bytes = bytes;
        m_Size = N;
    }

    unsigned char* GetBytes()
    {
        return m_Bytes;
    }

    unsigned int GetSize()
    {
        return m_Size;
    }

    unsigned char operator[](int i) const
    {
        if (i < m_Size)
        {
            return m_Bytes[i];
        }
        return 0x00;
    }

private:
    unsigned char* m_Bytes = nullptr;
    unsigned int m_Size = 0;
};