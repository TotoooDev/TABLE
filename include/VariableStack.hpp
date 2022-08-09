#pragma once

template <typename T>
class VariableStack
{
public:
    const static unsigned int MaxVariables = 1024;
    
    void SetSlot(unsigned char slot, T value)
    {
        if (slot < MaxVariables)
        {
            m_Variables[slot] = value;
        }
    }

    T GetValue(unsigned char slot)
    {
        if (slot < MaxVariables)
        {
            return m_Variables[slot];
        }
        return 0x00;
    }
private:
    T m_Variables[MaxVariables];
};