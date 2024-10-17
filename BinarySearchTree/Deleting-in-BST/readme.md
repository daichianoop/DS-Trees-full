# Binary Search Tree Node Deletion: C Implementation

## Overview

This README provides a detailed explanation of how node deletion works in a Binary Search Tree (BST) through a C implementation. The provided code includes defining a binary search tree, inserting nodes, and specifically focusing on deleting nodes while maintaining the properties of the BST.

## Table of Contents

- [Introduction to Binary Search Trees](#introduction-to-binary-search-trees)
- [Node Deletion Overview](#node-deletion-overview)
- [Implementation Details](#implementation-details)
  - [Base Case](#base-case)
  - [Node to Delete](#node-to-delete)
  - [Node with Two Children](#node-with-two-children)
- [Usage](#usage)
- [Conclusion](#conclusion)

## Introduction to Binary Search Trees

A Binary Search Tree is a binary tree where each node has at most two children. For each node:
- All values in the left subtree are less than the node's value.
- All values in the right subtree are greater than the node's value.

The BST allows for efficient searching, insertion, and deletion of nodes.

## Node Deletion Overview

Deleting a node in a BST requires ensuring that the integrity of the tree is maintained. There are three possible scenarios when deleting a node:
1. **Node to delete is a leaf (no children).**
2. **Node to delete has one child.**
3. **Node to delete has two children.**

When a node is deleted, the tree may need to be restructured to maintain its properties.

## Implementation Details

The provided code implement the `deleteNode` function, which takes the root of the tree and the key of the node to be deleted.

### Base Case

The base case checks if the node we are evaluating is NULL. If the node is NULL, it means that the key to delete does not exist in the tree, and the function returns NULL.

```c
if (root == NULL) {  
    return root;  
}
```

### Node to Delete

To find the node we need to delete, the function recursively traverses the tree:
- If the key is less than the root's value, it goes to the left subtree.
- If the key is greater than the root's value, it goes to the right subtree.

```c
if (key < root->data) {  
    root->left = deleteNode(root->left, key);  
} else if (key > root->data) {  
    root->right = deleteNode(root->right, key);  
} else {  
    // Node found to delete
}
```

### Node with Two Children

If the node has two children, the function conducts the following:
1. **Find the Inorder Successor:** The inorder successor is the smallest node in the right subtree. This node will replace the value of the node to be deleted.
2. **Copy the Inorder Successor's Value:** The successor's value is copied to the node to be deleted.
3. **Delete the Inorder Successor:** Since the successor can only have at most one child, we can delete it using the same `deleteNode` function recursively.

```c
struct node *temp = minValueNode(root->right);  
root->data = temp->data;  
root->right = deleteNode(root->right, temp->data);  
```

#### Node with One Child or No Child

This case is simpler:
- If the node to be deleted has no children, just free the memory and set the pointer to NULL.
- If the node has one child, bypass the node and connect its parent directly to its child.

```c
if (root->left == NULL) {  
    struct node *temp = root->right;  
    free(root);  
    return temp;  
} else if (root->right == NULL) {  
    struct node *temp = root->left;  
    free(root);  
    return temp;  
}  
```

## Usage

To utilize the provided implementation:
1. Compile the code in a C environment.
2. Run the executable.
3. The program will create a BST, perform an in-order traversal, delete a specified node, and display the tree again after deletion.

To delete a different node, change the value of `key` in the `main` function.

## Conclusion

The deletion of nodes in a Binary Search Tree is a fundamental operation that ensures the tree's properties remain intact. The provided C implementation robustly handles all deletion cases while maintaining efficiency, ensuring that the BST structure is preserved after modifications. This ensures that the BST can continue to operate optimally for subsequent operations.
