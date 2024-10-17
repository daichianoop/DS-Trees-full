# README for Binary Tree Creation

## Overview
This program implements the creation and traversal of a binary tree using C. It defines a binary tree structure, provides functions for creating nodes, and allows for different types of traversals (Pre-Order, In-Order, and Post-Order). The primary focus of this implementation is on creating a tree data structure and managing its nodes effectively.

## Table of Contents
- [Binary Tree Structure](#binary-tree-structure)
- [Node Creation](#node-creation)
- [Traversals](#traversals)
- [Example Usage](#example-usage)
- [Compiling and Running](#compiling-and-running)
- [Conclusion](#conclusion)

## Binary Tree Structure
The binary tree is represented using a structure called `node`, defined in C as follows:

```c
struct node {
    int data;                 // Value stored in the node
    struct node *left;       // Pointer to the left child
    struct node *right;      // Pointer to the right child
};
```

Each node consists of:
- An integer `data` that holds the value.
- Two pointers, `left` and `right`, which point to the left and right children of the node, respectively.

## Node Creation
The program features a function `createTreeNode` for creating new nodes:

```c
struct node *createTreeNode(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node)); // Allocate memory for the new node
    newNode -> data = value;        // Assign the value to the new node
    newNode -> left = NULL;         // Initialize left child as NULL
    newNode -> right = NULL;        // Initialize right child as NULL
    return newNode;                 // Return the created node
}
```

This function:
- Allocates memory for a new node.
- Initializes the node's data with the specified value.
- Sets the left and right child pointers to NULL, indicating that the node has no children upon creation.

## Traversals
This implementation includes three types of tree traversals:
1. **Pre-Order Traversal**: Visits the root first, then recursively visits the left subtree, followed by the right subtree.
2. **In-Order Traversal**: Recursively visits the left subtree first, then visits the root, and finally, traverses the right subtree.
3. **Post-Order Traversal**: Recursively visits both left and right subtrees before visiting the root node.

Each traversal is implemented in its respective function:
- `void preOrderTraversal(struct node *root)`
- `void inOrderTraversal(struct node *root)`
- `void postOrderTraversal(struct node *root)`

## Example Usage
In the `main` function, the binary tree is created manually by instantiating nodes and linking them accordingly. For instance:

```c
int main() {
    struct node* root = createTreeNode(1);
    struct node* n1 = createTreeNode(2);
    struct node* n2 = createTreeNode(3);
    struct node* n3 = createTreeNode(4);
    struct node* n4 = createTreeNode(5);
    struct node* n5 = createTreeNode(6);
    struct node* n6 = createTreeNode(7);

    // Linking Nodes Manually
    root -> left = n1;
    root -> right = n2;
    n1 -> left = n3;
    n1 -> right = n4;
    n2 -> left = n5;
    n2 -> right = n6;
    
    // Performing Traversals
    preOrderTraversal(root);
    inOrderTraversal(root);
    postOrderTraversal(root);
    
    return 0;
}
```

### Output
The program will print the results of each traversal type:
- Pre-Order, In-Order, and Post-Order traversals of the tree show the order in which nodes are visited.

## Compiling and Running
To compile and run this C program, use the following commands in your terminal:

```bash
gcc -o binary_tree binary_tree.c
./binary_tree
```

Be sure to replace `binary_tree.c` with the actual filename where the code is saved.

## Conclusion
This program demonstrates fundamental concepts of binary tree creation in C, including the structure definition, node creation, and various traversal methods. It serves as a practical example for understanding how binary trees work and how to implement them programmatically.
