#include <iostream>
#include "TABLE.h"

int main(int argc, char* argv[])
{
    unsigned char loop5times[] = 
    {
        LITERAL, 0x05, // Value of the variable, we use it as the numbre of time we want to iterate
        LITERAL, 0x00, // Slot of the variable
        STORE,

        LITERAL, 0x05, // Instruction to jump to (this one)
        
        LITERAL, 0x01, // Subtract one every loop
        LITERAL, 0x00, // Slot of the variable
        GET,           
        SUBTRACT,      // Subtract one to the variable
        LITERAL, 0x00, // Slot of the variable
        STORE,         // Store the subtraction
        LITERAL, 0x00,
        GET,           // Get the new variable value

        JUMP_NZ        // Jump to adress 0x05 if the variable is not zero
    };

    unsigned char conditions[] =
    {
        LITERAL, 0x01,
        START_IF,
            LITERAL, 0x69,
            POP,
        END_IF,
        
        LITERAL, 0x00,
        START_IF,
            LITERAL, 0x42,
            POP,
        END_IF
    };

    const unsigned int size = sizeof(conditions);

    Bytecode bytecode;
    bytecode.Create<size>(conditions);

    Interpreter interpreter;
    interpreter.Interpret(bytecode);

    return 0;
}