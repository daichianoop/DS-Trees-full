#include<stdlib.h>
#include<stdio.h>

struct node {     //todo Defining a Structure 
    int data;
    struct node *left;
    struct node *right;
};

struct node *createTreeNode(int value){     //todo Creating a function to create new Tree Nodes  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

void inOrderTraversal(struct node *root){     //todo In Order Traversal Function  
    if(!root){
        return;
    }
    inOrderTraversal(root -> left);
    printf("%d ", root -> data);
    inOrderTraversal(root -> right);
}

void preOrderTraversal(struct node *root){     //todo Pre Order Traversal Function  
    if(!root){
        return;
    }
    printf("%d ", root -> data);
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

void postOrderTraversal(struct node *root){     //todo Post Order Traversal Function  
    if(!root){
        return;
    }
    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    printf("%d ", root -> data);
}

int main(){     //todo Main Function  

    //fix Creating Nodes Manually 
    struct node* root = createTreeNode(1);
    struct node* n1 = createTreeNode(2);
    struct node* n2 = createTreeNode(3);
    struct node* n3 = createTreeNode(4);
    struct node* n4 = createTreeNode(5);
    struct node* n5 = createTreeNode(6);
    struct node* n6 = createTreeNode(7);

    //fix Linking Nodes Manually 
    root -> left = n1;
    root -> right = n2;
    n1 -> left = n3;
    n1 -> right = n4;
    n2 -> left = n5;
    n2 -> right = n6;
    
    //fix Printing Nodes 
    printf("Pre Order Traversal :\n");
    preOrderTraversal(root);
        printf("\n");
    printf("Inorder Order Traversal :\n");
    inOrderTraversal(root);
        printf("\n");
    printf("Post Order Traversal :\n");
    postOrderTraversal(root);
        printf("\n");
    
    return 0;
}