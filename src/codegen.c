#include <stdio.h>
#include "../include/codegen.h"

// this function prints "Assembly-like" instructions
void emit_assignment(char *var, char *val1, char *val2) {
    printf("LOAD %s\n", val1);
    printf("ADD %s\n", val2);
    printf("STORE %s\n", var);
    printf("----------------\n");
}

void emit_print(char *var) {
    printf("PUSH %s\n", var);
    printf("CALL PRINT\n");
    printf("----------------\n");
}