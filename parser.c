#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h" 

// Define AST Node Types and Structures
typedef enum {
    AST_VARIABLE_DECLARATION, AST_TEXT, AST_NUMBER, AST_BINARY_OP,
    AST_CONDITIONAL, AST_LOOP, AST_IO_OPERATION, AST_ERROR
    // Add more types as needed
} ASTNodeType;

typedef struct ASTNode {
    ASTNodeType type;

} ASTNode;

// Function declarations for the parser
ASTNode *parse(Token *tokens, int tokenCount);
ASTNode *parseStatement(Token **tokens, int *currentIndex);
ASTNode *parseExpression(Token **tokens, int *currentIndex);
ASTNode *parseVariableDeclaration(Token **tokens, int *currentIndex);
ASTNode *parseDisplayStatement(Token **tokens, int *currentIndex);
ASTNode *parseConditionalStatement(Token **tokens, int *currentIndex);
ASTNode *parseLoopStatement(Token **tokens, int *currentIndex);
ASTNode *parseArithmeticFunction(Token **tokens, int *currentIndex);
ASTNode *parseIOStatement(Token **tokens, int *currentIndex);
void freeAST(ASTNode *node);

// Main parsing function
ASTNode *parse(Token *tokens, int tokenCount) {
    ASTNode *root = malloc(sizeof(ASTNode));
    // Initialize root node
    int currentIndex = 0;
    while (currentIndex < tokenCount && tokens[currentIndex].type != TOKEN_EOF) {
        ASTNode *stmt = parseStatement(&tokens, &currentIndex);
        // Add stmt to the root's children
    }
    return root;
}

// Function to parse individual statements
ASTNode *parseStatement(Token **tokens, int *currentIndex) {
    // Based on the current token, decide which type of statement to parse
    // Example: if the current token is 'create', call parseVariableDeclaration
    
}



// Function to free AST nodes
void freeAST(ASTNode *node) {
 
}

int main() {
    // Example usage of the parser
    return 0;
}
