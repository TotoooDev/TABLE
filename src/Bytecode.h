#pragma once

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

private:
    unsigned char* m_Bytes = nullptr;
    unsigned int m_Size = 0;
};