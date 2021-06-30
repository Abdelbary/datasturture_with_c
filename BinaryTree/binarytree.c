#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
#define size(x)(sizeof(x)/sizeof(x[0]))


void insert(btree** tree, int v, btree* parent)
{
    if(*tree == NULL)
    {
        //printf("%d ",v);
        *tree = malloc(sizeof(btree));
        (*tree)->left   = NULL;
        (*tree)->right  = NULL;
        (*tree)->parent = parent; 
        (*tree)->data   = v;
        return;
    }
    

    if(v > (*tree)->data)
        insert(&(*tree)->right , v, *tree);
    else
        insert(&(*tree) ->left, v , *tree);
}


btree* deleteNode(btree *tree, int v)
{
    if(tree == NULL)
        return NULL;
    
    if( v == tree->data)
    {
        if(tree->left == NULL)
        {
            btree* temp = tree->right; 
            free(tree);
            tree = NULL;
            return temp;
        }
        else if (tree->right == NULL)
        {
            btree* temp = tree->left;
            free(tree);
            tree = NULL;
            return temp;
        }
        else
        {
            btree* temp = Successor(tree);
            tree->data = temp->data;
            tree->right = deleteNode(tree->right,v);
        }
    }
    else if(v > tree->data) 
        tree->right = deleteNode(tree->right,v);
    else if ( v < tree->data)
        tree->left  = deleteNode(tree->left,v);

    return tree;
}

void  traverse_tree(btree *t)
{
    if(t == NULL)
        return;
    
    traverse_tree(t->left);
    printf("%d ",t->data);
    traverse_tree(t->right);
}

btree * findMax(btree* tree)
{
    if(tree == NULL)
        return NULL;
    while(tree->right != NULL)
        tree = tree->right;
    return tree;
}

btree * findMin(btree* tree)
{
    if(tree == NULL)
        return NULL;

    while(tree->left != NULL)
        tree = tree->left;

    return tree;
}

btree * searchTree(btree *t , int v)
{  
    while(t != NULL)
    {
        if(t->data == v)
            return t;
        
        else if(v > t->data)
            t = t->right;
        else
            t = t->left;
    }

    return NULL;
}


btree* Successor(btree * t)
{
    if(t == NULL || t->right == NULL)
        return NULL;
    
    return findMin(t->right);
}

btree* Predecessor(btree *t)
{
    if(t == NULL || t->left == NULL)
        return NULL;
    
    return findMax(t->left);
}


int main()
{
    int arr[] = {3,4,1,0,5};
    
    btree *t = NULL;
    for(int i = 0 ; i < size(arr) ; i++)
        insert(&t,arr[i],NULL);
    traverse_tree(t);
    btree* ma = findMax(t);
    btree* mi = findMin(t);
    btree* x  = searchTree(t,1);
    btree* xx = deleteNode(t,4);
    traverse_tree(t);
    printf("max :%d , min :%d , x :%d",ma->data,mi->data,x->data);
    return 0;
}