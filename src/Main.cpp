#include <iostream>
#include "TABLE.h"

int main(int argc, char* argv[])
{
    std::cout << "Hi mom!" << std::endl;

    unsigned char bytes[] = { NOOP, NOOP, NOOP };
    Bytecode bytecode;
    bytecode.Create<3>(bytes);
    Interpreter interpreter;
    interpreter.Interpret(bytecode);

    return 0;
}