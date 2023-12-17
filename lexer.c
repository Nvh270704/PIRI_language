#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"  

// Function to create a token
Token createToken(const char *value, TokenType type) {
    Token token;
    token.value = strdup(value);
    token.type = type;
    return token;
}

// Helper function to check if a character is alphanumeric
int isAlphaNumeric(char ch) {
    return isalnum((unsigned char)ch) || ch == '_';
}

// Helper function to check if a character is skippable (whitespace)
int isSkippable(char ch) {
    return isspace((unsigned char)ch);
}

// Implementation of the tokenize function
void tokenize(const char *sourceCode, Token **tokens, int *tokenCount) {
    *tokenCount = 0;
    int capacity = 10;
    *tokens = malloc(capacity * sizeof(Token));
    const char *ptr = sourceCode;

    while (*ptr != '\0') {
        if (isSkippable(*ptr)) {
            ptr++;
            continue;
        }

        if (isdigit(*ptr)) {
            const char *start = ptr;
            while (isdigit(*ptr)) ptr++;
            char *num = strndup(start, ptr - start);
            (*tokens)[(*tokenCount)++] = createToken(num, TOKEN_NUMBER);
            free(num);
        } else if (isAlphaNumeric(*ptr)) {
            const char *start = ptr;
            while (isAlphaNumeric(*ptr)) ptr++;
            char *word = strndup(start, ptr - start);

            // Distinguish between keywords and identifiers
            TokenType type = TOKEN_IDENTIFIER;
            if (strcmp(word, "create") == 0 || strcmp(word, "show") == 0 ||
                strcmp(word, "if") == 0 || strcmp(word, "then") == 0 ||
                strcmp(word, "repeat") == 0) {
                type = TOKEN_KEYWORD;
            }

            (*tokens)[(*tokenCount)++] = createToken(word, type);
            free(word);
        } else if (*ptr == '"') {
            // Handle string literals
            ptr++;  
            const char *start = ptr;
            while (*ptr && *ptr != '"') ptr++;
            if (*ptr == '"') {
                char *str = strndup(start, ptr - start);
                (*tokens)[(*tokenCount)++] = createToken(str, TOKEN_STRING);
                free(str);
                ptr++;  
            } else {
                // Handle error: Unclosed string literal
                
            }
        } else if (strncmp(ptr, "--", 2) == 0) {
            // Handle comments by skipping to the end of the line
            while (*ptr && *ptr != '\n') ptr++;
        } else {
            // Handle other symbols (operators, punctuation, etc.)
            
            // Example for handling a single character symbol:
            char symbol[2] = {*ptr, '\0'};
            (*tokens)[(*tokenCount)++] = createToken(symbol, TOKEN_SYMBOL);
            ptr++;
        }

        // Resize tokens array if needed
        if (*tokenCount >= capacity) {
            capacity *= 2;
            *tokens = realloc(*tokens, capacity * sizeof(Token));
        }
    }

    (*tokens)[(*tokenCount)++] = createToken("", TOKEN_EOF); // End-of-file token
}

// Main function for testing the lexer
int main() {
    
    const char *sourceCode = "create number age set to 65\nshow \"Hello, World!\"";
    Token *tokens = NULL;
    int tokenCount = 0;

    tokenize(sourceCode, &tokens, &tokenCount);

    /
    for (int i = 0; i < tokenCount; i++) {
        printf("Token: %s, Type: %d\n", tokens[i].value, tokens[i].type);
    }

    // Free allocated memory
    for (int i = 0; i < tokenCount; i++) {
        free(tokens[i].value);
    }
    free(tokens);

    return 0;
}

