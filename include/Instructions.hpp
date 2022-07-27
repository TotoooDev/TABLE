#pragma once

enum Instructions
{
    NOOP     = 0x00, // Useful if you want to waste a few CPU cycles

    // STACK INSTRUCTIONS
    LITERAL    = 0x01, // Push a literal to the stack
    POP        = 0x02, // Pop a literal

    // OPERATIONS
    ADD        = 0x03, // Pop two literals from the stack and push the sum
    SUBTRACT   = 0x04, // Pop two literals from the stack and push the subtraction
    MULTIPLY   = 0x05, // Pop two literals from the stack and push the multiplication
    DIVIDE     = 0x06, // Pop two literals from the stack and push the division

    // VARIABLES
    STORE      = 0x07, // Pop two literals to store the first one in the slot indicated by the second one
    GET        = 0x08, // Pop a literal to get the slot and push the value of the variable

    // JUMP AND CONDITIONS
    JUMP       = 0x09, // Pop a literal as the adress of the bytecode to jump to
    JUMP_NZ    = 0x0A, // Pop a literal as the condition and a literal as the adress of the bytecode to jump to
    START_IF   = 0x0B, // Pop a literal to get the condition of the if statement
    END_IF     = 0x0C, // Does nothing but you need one to know when the if statement is closed

    // INPUT - OUTPUT
    USER_CHAR  = 0x0D, // Ask for user input, push result in
    USER_INT   = 0x0E, // Ask for user input as an integer, push result in
    OUTPUT     = 0x0F, // Pop a value and print it
    OUTPUT_INT = 0x10, // Pop a value and print it as an integer

    // OPERATORS
    EQUAL      = 0x11, // Pop two literals, push 0x01 if they are equal, 0x00 if not
    NOT        = 0x12, // Pop two literals, push 0x01 if they are not equal, 0x00 if they are
    LESS       = 0x13, // Pop two literals, push 0x01 if the first one is smaller, 0x00 if not
    MORE       = 0x14, // Pop two literals, push 0x01 if the first one is greater, 0x00 if not
    LESS_EQ    = 0x15, // Pop two literals, push 0x01 if the first one is smaller or equal, 0x00 if not
    MORE_EQ    = 0x16  // Pop two literals, push 0x01 if the first one is greater or equal, 0x00 if not
};