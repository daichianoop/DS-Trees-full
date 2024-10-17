#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>

//todo Defining a Structure  
struct node {  
    int data;  
    struct node *left;  
    struct node *right;  
};  

//todo Creating a function to create new Tree Nodes  
struct node *createTreeNode(int data) {  
    struct node *treeNode = (struct node*)malloc(sizeof(struct node));  
    //fix Edge Case if DMA fails  
    if (!treeNode) {  
        printf("Memory Allocation Failed\n");  
        exit(1);  
    }  
    treeNode->data = data;  
    treeNode->left = NULL;  
    treeNode->right = NULL;  
    return treeNode;  
}  

//todo Creating a function for insertion of Tree Nodes {BINARY SEARCH TREE} 
struct node *insert(struct node *root, int data) {  
    if (root == NULL) {  
        return createTreeNode(data);  
    }  
    if (data < root->data) {  
        root->left = insert(root->left, data);  
    } else {  
        root->right = insert(root->right, data);  
    }  
    return root;  
}  

//todo In Order Traversal Function  
void inOrderTraversal(struct node *root) {  
    if (root == NULL) {  
        return;  
    }  
    inOrderTraversal(root->left);  
    printf("%d ", root->data);  
    inOrderTraversal(root->right);  
}  

//todo Main Function  
int main(){  
    struct node *root = NULL;  
    //fix Inserting Tree Nodes  
    root = insert(root, 1);  
    insert(root, 6);  
    insert(root, 12);  
    insert(root, 45);  
    insert(root, 7);  
    
    printf("In Order Traversal:\n");  
    inOrderTraversal(root);  
    printf("\n");  

    return 0;  
}