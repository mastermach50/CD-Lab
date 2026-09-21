// Implementation helper (ast.c or inline within YACC header block)
#include "ast.h"

ASTNode* make_num_node(int val) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_NUM;
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

ASTNode* make_op_node(NodeType type, ASTNode *left, ASTNode *right) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = type;
    node->val = 0;
    node->left = left;
    node->right = right;
    return node;
}

void print_ast(ASTNode *node, int level) {
    if (!node) return;
    for (int i = 0; i < level; i++) printf("  ");

    switch (node->type) {
        case NODE_NUM: printf("NUM: %d\n", node->val); break;
        case NODE_ADD: printf("OP: +\n"); break;
        case NODE_SUB: printf("OP: -\n"); break;
        case NODE_MUL: printf("OP: *\n"); break;
        case NODE_DIV: printf("OP: /\n"); break;
    }
    print_ast(node->left, level + 1);
    print_ast(node->right, level + 1);
}