#include "parser.h" 

// Function to interpret an AST node
void interpretAST(ASTNode *node) {
    if (node == NULL) return;

    switch (node->type) {
        case AST_VARIABLE_DECLARATION:
            // Handle variable declaration
            break;
        case AST_DISPLAY:
            // Handle display statement
            if (node->data.displayExpression->type == AST_TEXT) {
                printf("%s\n", node->data.displayExpression->data.text);
            }
            
            break;
        
    }


}

int main() {

    return 0;
}
