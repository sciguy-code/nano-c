#include <stdio.h>
#include <stdlib.h>
#include "../include/lexer.h"
#include "../include/parser.h"

// helper to read file into a string buffer
char *read_file(const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *buffer = malloc(length + 1);
    if (!buffer)
    {
        printf("Error: Memory allocation failed\n");
        fclose(f);
        exit(1);
    }

    fread(buffer, 1, length, f);
    buffer[length] = '\0'; // null terminate

    fclose(f);
    return buffer;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    printf("--- Simple Compiler ---\n");
    printf("Compiling file: %s\n\n", argv[1]);

    // 1. read File
    char *source = read_file(argv[1]);

    // 2. initialize Lexer
    init_lexer(source);

    // 3. run Parser (which calls CodeGen)
    parse();

    // cleanup
    free(source);

    printf("\n--- Compilation Complete ---\n");
    return 0;
}