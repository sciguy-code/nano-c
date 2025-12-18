#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>

// different types of tokens our language understands
typedef enum
{
    TOKEN_ID,     // variables like x, y
    TOKEN_INT,    // numbers like 10, 20
    TOKEN_EQUALS, // =
    TOKEN_PLUS,   // +
    TOKEN_SEMI,   // ;
    TOKEN_PRINT,  // print keyword
    TOKEN_EOF,    // end of file
    TOKEN_UNKNOWN
} TokenType;

// structure to represent a single token
typedef struct
{
    TokenType type;
    char value[100]; // stores the text (e.g., "x" or "10")
} Token;

// function prototypes
void init_lexer(const char *source);
Token get_next_token();

#endif