#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>

// Enum for token types
typedef enum {
    TOKEN_NUMBER,        // Represents a numeric literal
    TOKEN_IDENTIFIER,    // Represents an identifier
    TOKEN_KEYWORD,       // Represents a keyword
    TOKEN_STRING,        // Represents a string literal
    TOKEN_COMMENT,       // Represents a comment
    TOKEN_EOF,           // Represents the end of the file
    TOKEN_ERROR,         // Represents an error token
    TOKEN_SYMBOL         // Represents a symbol (like +, -, etc.)
} TokenType;

// Token structure
typedef struct {
    char *value;  // The actual string value of the token
    TokenType type;  // The type of the token
} Token;

// Function to create a new token
// value: String value of the token
// type: Type of the token
Token createToken(const char *value, TokenType type);

// Function to tokenize the source code
// sourceCode: The source code to tokenize
// tokens: Output array of tokens
// tokenCount: Number of tokens generated
void tokenize(const char *sourceCode, Token **tokens, int *tokenCount);

#endif // LEXER_H
