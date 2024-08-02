#ifndef BST_H
#define BST_H

typedef struct bst_node {
    int val;
    struct bst_node* parent;
    struct bst_node* left;
    struct bst_node* right;
} bst_node;

typedef struct bst {
    bst_node* root;
} bst;

void inorder_tree_walk(const bst_node* n)
{
    if(n->left)  inorder_tree_walk(n->left);
    printf("%d ", n->val);
    if(n->right) inorder_tree_walk(n->right);
}

bst_node* tree_search(const bst *T, int k)
{
    bst_node *x = T->root;
    while(x != NULL && x->val != k) {
        if(k < x->val)
            x = x->left;
        else
            x = x->right;
    }
    if(x) return x;
    return NULL;
}

bst_node* tree_minimum(bst_node *x)
{
    while(x->left != NULL)
        x = x->left;
    return x;
}

bst_node* tree_maximum(bst_node *x)
{
    while(x->right != NULL)
        x = x->right;
    return x;
}

void bst_insert(bst *T, bst_node *z)
{
    bst_node *y = NULL;
    bst_node *x = T->root;
    while(x) {
        y = x;
        if(z->val < x->val)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if(!y)
        T->root = z;
    else if(z->val < y->val)
        y->left = z;
    else
        y->right = z;
}

void transplant(bst *T, bst_node *u, bst_node *v)
{
    if(u->parent == NULL)
        T->root = v;
    if(u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if(v != NULL)
        v->parent = u->parent;
}

void bst_delete(bst *T, bst_node *z)
{
    bst_node *y = NULL;
    if(z->left == NULL)
        transplant(T, z, z->right);
    else if(z->right == NULL)
        transplant(T, z, z->left);
    else {
        y = tree_minimum(z->right);
        if(y->parent != z) {
            transplant(T, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(T, z, y);
        y->left = z->left;
        z->left->parent = y;
    }
}

#endif