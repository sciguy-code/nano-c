#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../include/lexer.h"

// pointer to the source code string
static const char *src;
static int pos = 0;

void init_lexer(const char *source)
{
    src = source;
    pos = 0;
}

Token get_next_token()
{
    Token token;
    token.value[0] = '\0';
    token.type = TOKEN_EOF;

    // skip whitespace (spaces, tabs, newlines)
    while (src[pos] != '\0' && isspace(src[pos]))
    {
        pos++;
    }

    if (src[pos] == '\0')
    {
        return token; // returns EOF
    }

    // handle 'print' keyword or Variable IDs
    if (isalpha(src[pos]))
    {
        int i = 0;
        while (isalnum(src[pos]))
        {
            token.value[i++] = src[pos++];
        }
        token.value[i] = '\0';

        if (strcmp(token.value, "print") == 0)
        {
            token.type = TOKEN_PRINT;
        }
        else
        {
            token.type = TOKEN_ID;
        }
        return token;
    }

    // handle numbers
    if (isdigit(src[pos]))
    {
        int i = 0;
        while (isdigit(src[pos]))
        {
            token.value[i++] = src[pos++];
        }
        token.value[i] = '\0';
        token.type = TOKEN_INT;
        return token;
    }

    // handle symbols
    switch (src[pos])
    {
    case '=':
        token.type = TOKEN_EQUALS;
        break;
    case '+':
        token.type = TOKEN_PLUS;
        break;
    case ';':
        token.type = TOKEN_SEMI;
        break;
    default:
        token.type = TOKEN_UNKNOWN;
        break;
    }

    token.value[0] = src[pos++];
    token.value[1] = '\0';
    return token;
}