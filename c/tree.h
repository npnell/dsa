#ifndef TREE_H
#define TREE_H

#include <stdio.h>

typedef struct tnode {
    int val;
    struct tnode* left;
    struct tnode* right;    
} tnode;

typedef struct tree {
    tnode* root;
} tree;

void preorder(const tnode* n)
{
    printf("%d ", n->val);
    if(n->left)  preorder(n->left);
    if(n->right) preorder(n->right);
}

void inorder(const tnode* n)
{
    if(n->left)  inorder(n->left);
    printf("%d ", n->val);
    if(n->right) inorder(n->right);
}

void postorder(const tnode* n)
{
    if(n->left)  postorder(n->left);
    if(n->right) postorder(n->right);
    printf("%d ", n->val);
}

#endif