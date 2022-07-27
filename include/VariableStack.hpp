#pragma once

class VariableStack
{
public:
    const static unsigned int MaxVariables = 1024;

    VariableStack()
    {
        for (unsigned int i = 0; i < MaxVariables; i++)
        {
            m_Variables[i] = 0x00;
        }
    }

    void SetSlot(unsigned char slot, unsigned char value)
    {
        if (slot < MaxVariables)
        {
            m_Variables[slot] = value;
        }
    }

    unsigned char GetValue(unsigned char slot)
    {
        if (slot < MaxVariables)
        {
            return m_Variables[slot];
        }
        return 0x00;
    }
private:
    unsigned char m_Variables[MaxVariables];
};