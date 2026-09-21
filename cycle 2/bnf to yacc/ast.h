#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node Types
typedef enum {
    NODE_NUM,
    NODE_ADD,
    NODE_SUB,
    NODE_MUL,
    NODE_DIV
} NodeType;

// AST Node Structure
typedef struct ASTNode {
    NodeType type;
    int val;                  // Used if type == NODE_NUM
    struct ASTNode *left;     // Left subtree
    struct ASTNode *right;    // Right subtree
} ASTNode;

// Function prototypes
ASTNode* make_num_node(int val);
ASTNode* make_op_node(NodeType type, ASTNode *left, ASTNode *right);
void print_ast(ASTNode *node, int level);

#endif