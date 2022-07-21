#pragma once

enum Instructions
{
    NOOP     = 0x00, // Useful if you want to waste a few CPU cycles

    // STACK
    LITERAL  = 0x01, // Push a literal to the stack
    POP      = 0x02, // Pop a literal

    // OPERATIONS
    ADD      = 0x03, // Pop two literals from the stack and push the sum
    SUBTRACT = 0x04, // Pop two literals from the stack and push the subtraction
    MULTIPLY = 0x05, // Pop two literals from the stack and push the multiplication
    DIVIDE   = 0x06, // Pop two literals from the stack and push the division

    // VARIABLES STUFF
    STORE    = 0x07, // Pop two literals to store the first one in the slot indicated by the second one
    GET      = 0x08, // Pop a literal to get the slot and push the value of the variable

    // JUMP AND CONDITIONS
    JUMP     = 0x09, // Pop a literal as the adress of the bytecode to jump to
    JUMP_NZ  = 0x0A  // Pop a literal as the condition and a literal as the adress of the bytecode to jump to
};