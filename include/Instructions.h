#pragma once

enum Instructions
{
    NOOP     = 0x00, // Litteraly nothing
    LITERAL  = 0x01, // Push a literal to the stack

    // OPERATIONS
    ADD      = 0x02, // Pop two literals from the stack and push the sum
    SUBTRACT = 0x03, // Pop two literals from the stack and push the subtraction
    MULTIPLY = 0x04, // Pop two literals from the stack and push the multiplication
    DIVIDE   = 0x05, // Pop two literals from the stack and push the division

    // VARIABLES STUFF
    STORE    = 0x06, // Pop two literals to store the first one in the slot indicated by the second one
    GET      = 0x07  // Pop a literal to get the slot and push the value of the variable
};