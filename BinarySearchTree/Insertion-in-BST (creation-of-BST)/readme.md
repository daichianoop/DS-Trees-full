# README for Binary Search Tree Implementation

## Overview
This C program implements a Binary Search Tree (BST) data structure, allowing for the insertion of nodes and the traversal of those nodes in sorted order. A BST is a hierarchical structure in which each node has at most two children, and the left child contains values less than the parent node while the right child contains values greater than the parent node. 

## Table of Contents
- [Data Structure](#data-structure)
- [Functions](#functions)
  - [createTreeNode](#createtreenode)
  - [insert](#insert)
  - [inOrderTraversal](#inordertraversal)
- [Example Usage](#example-usage)
- [Output](#output)
- [Compiling and Running](#compiling-and-running)
- [Conclusion](#conclusion)

## Data Structure
The program defines a simple structure for the tree nodes, which includes:
- An integer `data` to store the value of the node.
- Pointers to the left and right child nodes.

```c
struct node {  
    int data;  
    struct node *left;  
    struct node *right;  
};  
```

## Functions
### `createTreeNode`
This function allocates memory for a new tree node and initializes its data and child pointers.

```c
struct node *createTreeNode(int data) {  
    struct node *treeNode = (struct node*)malloc(sizeof(struct node));  
    if (!treeNode) {  
        printf("Memory Allocation Failed\n");  
        exit(1);  
    }  
    treeNode->data = data;  
    treeNode->left = NULL;  
    treeNode->right = NULL;  
    return treeNode;  
}
```

### `insert`
This function inserts a new node into the BST. It ensures that the tree remains sorted according to the BST properties.

```c
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
```

### `inOrderTraversal`
This function traverses the BST in in-order sequence (left-root-right), effectively printing the values in sorted order.

```c
void inOrderTraversal(struct node *root) {  
    if (root == NULL) {  
        return;  
    }  
    inOrderTraversal(root->left);  
    printf("%d ", root->data);  
    inOrderTraversal(root->right);  
}
```

## Example Usage
In the `main` function, a BST is created by inserting several nodes. The in-order traversal is then called to display the values in ascending order.

```c
int main() {  
    struct node *root = NULL;  
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
```

## Output
When you run this program, it will produce the following output based on the inserted values:

```
In Order Traversal:
1 6 7 12 45 
```

This output indicates that the nodes have been successfully inserted and traversed in sorted order.

## Compiling and Running
To compile and run this C program, use the following commands in your terminal:

```bash
gcc -o binary_search_tree binary_search_tree.c
./binary_search_tree
```

Make sure to replace `binary_search_tree.c` with the filename where the code is stored.

## Conclusion
This program provides a fundamental understanding of the Binary Search Tree data structure, including how to create nodes, insert them while maintaining the sorted order, and traverse the tree in an in-order manner. This example can be extended and modified to include additional functionalities such as search, delete, and other traversal methods.
