#include <iostream>
#include "TABLE.h"

int main(int argc, char* argv[])
{
    std::cout << "Hi mom!" << std::endl;

    unsigned char bytes[] = 
    {
        LITERAL, 0x01,
        LITERAL, 0x00,
        STORE,
        LITERAL, 0x00,
        GET
    };
    const unsigned int size = sizeof(bytes);

    Bytecode bytecode;
    bytecode.Create<size>(bytes);

    Interpreter interpreter;
    interpreter.Interpret(bytecode);

    return 0;
}