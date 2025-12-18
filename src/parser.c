#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/lexer.h"
#include "../include/parser.h"
#include "../include/codegen.h"

Token current_token;

// Helper to move to next token
void advance() {
    current_token = get_next_token();
}

// Checks if current token matches expected type
void expect(TokenType type) {
    if (current_token.type == type) {
        advance();
    } else {
        printf("Syntax Error: Unexpected token '%s'\n", current_token.value);
        exit(1);
    }
}

// Simple parser: 
// Statement -> ID = INT + INT ; | print ID ;
void parse() {
    advance(); // Load first token

    while (current_token.type != TOKEN_EOF) {
        if (current_token.type == TOKEN_ID) {
            // Found: x = 10 + 5;
            char varName[100];
            strcpy(varName, current_token.value);
            advance();

            expect(TOKEN_EQUALS);
            
            char val1[100];
            strcpy(val1, current_token.value);
            expect(TOKEN_INT);

            expect(TOKEN_PLUS);

            char val2[100];
            strcpy(val2, current_token.value);
            expect(TOKEN_INT);

            expect(TOKEN_SEMI);

            // Send to Code Generator
            emit_assignment(varName, val1, val2);

        } else if (current_token.type == TOKEN_PRINT) {
            // Found: print x;
            advance();
            
            char varName[100];
            strcpy(varName, current_token.value);
            expect(TOKEN_ID);
            
            expect(TOKEN_SEMI);

            // Send to Code Generator
            emit_print(varName);
        } else {
            // Skip unknown for now
            advance();
        }
    }
}