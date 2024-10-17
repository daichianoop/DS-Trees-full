# README for Binary Tree Traversal Methods

## Overview
This program implements a binary tree in C and provides various traversal methods: Pre-Order, In-Order, and Post-Order. Each traversal method explores the nodes of the tree in a unique order, which is crucial for various operations such as searching, sorting, and evaluating expressions.

## Tree to be Implemented
        1
       / \
      2   3
     / \ / \
    4  5 6  7

## Table of Contents
- [Binary Tree Structure](#binary-tree-structure)
- [Traversal Methods](#traversal-methods)
  - [Pre-Order Traversal](#pre-order-traversal)
  - [In-Order Traversal](#in-order-traversal)
  - [Post-Order Traversal](#post-order-traversal)
- [Example Usage](#example-usage)
- [Compiling and Running](#compiling-and-running)
- [Conclusion](#conclusion)

## Binary Tree Structure
The program defines a binary tree using a structure called `node`, which has the following components:

```c
struct node {
    int data;                 // Value stored in the node
    struct node *left;       // Pointer to the left child
    struct node *right;      // Pointer to the right child
};
```

Each `node` contains:
- An integer value (`data`).
- Pointers to the left and right child nodes.

## Traversal Methods
### Pre-Order Traversal
In Pre-Order Traversal, the current node is processed before its child nodes. The order of traversal is:
1. Visit the root node.
2. Traverse the left subtree.
3. Traverse the right subtree.

```c
void preOrderTraversal(struct node *root) {
    if(!root){
        return;
    }
    printf("%d ", root -> data); // Visit the root
    preOrderTraversal(root -> left); // Traverse left
    preOrderTraversal(root -> right); // Traverse right
}
```
**Output Example**: For a root node with value `1` followed by child nodes, the Pre-Order traversal would display: `1, 2, 4, 5, 3, 6, 7`.

### In-Order Traversal
In-Order Traversal processes the nodes in a left-root-right order:
1. Traverse the left subtree.
2. Visit the root node.
3. Traverse the right subtree.

```c
void inOrderTraversal(struct node *root) {
    if(!root){
        return;
    }
    inOrderTraversal(root -> left); // Traverse left
    printf("%d ", root -> data); // Visit the root
    inOrderTraversal(root -> right); // Traverse right
}
```
**Output Example**: Given the same tree, the In-Order traversal would yield: `4, 2, 5, 1, 6, 3, 7`.

### Post-Order Traversal
In Post-Order Traversal, the nodes are processed in a left-right-root order:
1. Traverse the left subtree.
2. Traverse the right subtree.
3. Visit the root node.

```c
void postOrderTraversal(struct node *root) {
    if(!root){
        return;
    }
    postOrderTraversal(root -> left); // Traverse left
    postOrderTraversal(root -> right); // Traverse right
    printf("%d ", root -> data); // Visit the root
}
```
**Output Example**: For the tree, the Post-Order traversal outputs: `4, 5, 2, 6, 7, 3, 1`.

## Example Usage
In the `main` function, a binary tree is created manually, and each traversal method is called to print the values in different orders.

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
    printf("Pre Order Traversal :\n");
    preOrderTraversal(root);
    printf("\n");

    printf("In Order Traversal :\n");
    inOrderTraversal(root);
    printf("\n");

    printf("Post Order Traversal :\n");
    postOrderTraversal(root);
    printf("\n");
    
    return 0;
}
```

## Compiling and Running
To compile and run this C program, use the following commands in your terminal:

```bash
gcc -o binary_tree_traversal binary_tree_traversal.c
./binary_tree_traversal
```

Make sure to replace `binary_tree_traversal.c` with the filename where the code is stored.

## Conclusion
This program serves as an educational tool for understanding binary tree traversal methods in C. Each traversal technique can be applied to different problems, such as expression evaluation, syntax tree parsing, and more. By exploring these methods, you gain a deeper insight into tree data structures and their applications.

