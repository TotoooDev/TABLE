#include "TABLE.hpp"

int main(int argc, char* argv[])
{
    unsigned char bytes[] =
    {
        LITERAL, 0x01,
        LITERAL, 0x01,
        LITERAL, 0x01,
        LITERAL, 0x01,
        LITERAL, 0x00,
        STORE_STR
    };

    const unsigned int size = sizeof(bytes);

    Bytecode bytecode;
    bytecode.Create<size>(bytes);

    Interpreter interpreter;
    interpreter.Interpret(bytecode);

    std::cin.get();
    return 0;
}