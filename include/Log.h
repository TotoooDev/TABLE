#pragma once

#include <vector>
#include <bitset>

enum Errors
{
    STACK_OVERFLOW,
    STACK_UNDERFLOW,
    NO_MATCHING_END_IF
};

class Logger
{
public:
    static Logger& Get()
    {
        static Logger instance;
        return instance;
    }

    void AddWarning()
    {
        m_ErrorBits.set(0);
    }

    void AddError(Errors error)
    {
        switch (error)
        {
        case STACK_OVERFLOW:
            m_ErrorMessages.push_back("Error: Stack overflow");
            break;

        case STACK_UNDERFLOW:
            m_ErrorMessages.push_back("Error: Stack underflow");
            break;

        case NO_MATCHING_END_IF:
            m_ErrorMessages.push_back("Error: No matching END_IF");
            break;

        default:
            break;
        }
        m_ErrorBits.set(1);
    }

    bool HasWarnings()
    {
        return m_ErrorBits.test(0);
    }

    bool HasErrors()
    {
        return m_ErrorBits.test(1);
    }

    std::vector<std::string> GetWarnings()
    {
        return m_WarningMessages;
    }

    std::vector<std::string> GetErrors()
    {
        return m_ErrorMessages;
    }

private:
    Logger() {}
    Logger(Logger const&) = delete;
    void operator=(Logger const&) = delete;

    std::vector<std::string> m_WarningMessages;
    std::vector<std::string> m_ErrorMessages;

    std::bitset<2> m_ErrorBits;
};