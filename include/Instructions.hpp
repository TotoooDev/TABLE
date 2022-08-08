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
    STORE_CHAR = 0x07, // Pop two literals to store the first one in the slot indicated by the second one
    STORE_INT  = 0x08, // Pop five literals to store the next four literals one in the slot indicated by the second one
    STORE_FLT  = 0x09, // Pop five literals to store the next four literals one in the slot indicated by the second one
    STORE_STR  = 0x0A, // Pop several literals to store the string in the slot indicated by the second one. All bytes are popped and interpreted as a string until a null byte (0x00)
    GET_CHAR   = 0x0B, // Pop a literal to get the slot and push the value of the variable
    GET_INT    = 0x0C, // Pop a literal to get the slot and push the value of the variable as four literals
    GET_FLT    = 0x0D, // Pop a literal to get the slot and push the value of the variable as four literals
    GET_STR    = 0x0E, // Pop a literal to get the slot and push the value of the variable as several literals including the null terminating byte of the string

    // JUMP AND CONDITIONS
    JUMP       = 0x0F, // Pop a literal as the adress of the bytecode to jump to
    JUMP_NZ    = 0x10, // Pop a literal as the condition and a literal as the adress of the bytecode to jump to
    START_IF   = 0x11, // Pop a literal to get the condition of the if statement
    END_IF     = 0x12, // Does nothing but you need one to know when the if statement is closed

    // INPUT - OUTPUT
    USER_CHAR  = 0x13, // Ask for user input, push result in
    USER_INT   = 0x14, // Ask for user input as an integer, push result in
    OUTPUT     = 0x15, // Pop a value and print it
    OUTPUT_INT = 0x16, // Pop a value and print it as an integer

    // OPERATORS
    EQUAL      = 0x17, // Pop two literals, push 0x01 if they are equal, 0x00 if not
    NOT        = 0x18, // Pop two literals, push 0x01 if they are not equal, 0x00 if they are
    LESS       = 0x19, // Pop two literals, push 0x01 if the first one is smaller, 0x00 if not
    MORE       = 0x1A, // Pop two literals, push 0x01 if the first one is greater, 0x00 if not
    LESS_EQ    = 0x1B, // Pop two literals, push 0x01 if the first one is smaller or equal, 0x00 if not
    MORE_EQ    = 0x1C  // Pop two literals, push 0x01 if the first one is greater or equal, 0x00 if not
};