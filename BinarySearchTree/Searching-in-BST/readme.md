# README for Binary Search Tree (BST) with Search Functionality

## Overview
This C program implements a Binary Search Tree (BST) data structure that supports insertion of nodes and searching for specific values. The BST maintains properties that allow for efficient searching, insertion, and traversal. This README focuses particularly on the search functionality and provides detailed explanations regarding each part of the code.

## Table of Contents
- [Data Structure](#data-structure)
- [Functions](#functions)
  - [createTreeNode](#createtreenode)
  - [insert](#insert)
  - [inOrderTraversal](#inordertraversal)
  - [search](#search)
- [Example Usage](#example-usage)
- [Output](#output)
- [Compiling and Running](#compiling-and-running)
- [Conclusion](#conclusion)

## Data Structure
The program defines a structure for the nodes of the BST. Each node consists of:
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
This section describes the key functions used in the program.

### `createTreeNode`
This function creates a new tree node and initializes its data. It allocates memory dynamically and checks for allocation failures.

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
This function inserts a new value into the BST, ensuring that the tree remains sorted per the BST properties.

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
This function performs an in-order traversal of the BST, printing the values in sorted order.

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

### `search`
This function searches for a specific element in the BST. It utilizes the properties of the BST for efficient searching by recursively navigating through left and right subtrees.

```c
bool search(struct node *root , int element) {
    // Base case: If the current node is NULL, the element is not found
    if (!root) {
        return false;
    }
    // If the current node's data is greater than the element, search left subtree
    if (root->data > element) {
        return search(root->left, element);
    }
    // If the current node's data matches the element, return true
    else if (root->data == element) {
        return true;
    }
    // If the current node's data is less than the element, search right subtree
    else {
        return search(root->right, element);
    }
}
```
- **Base Case**: If the current node is `NULL`, the element is not found, so the function returns `false`.
- **Comparison**: If the data of the current node is greater than the element being searched, the function recursively calls itself on the left child.
- **Match Found**: If the data matches the element, it returns `true`.
- **Search Right**: If the data of the current node is less than the element, the function recursively searches the right child.

## Example Usage
In the `main` function, the program creates a BST and inserts several nodes. It then displays the tree using in-order traversal and searches for a specific value.

```c
int main(){  
    struct node *root = NULL;  
    // Inserting Tree Nodes  
    root = insert(root, 1);  
    insert(root, 2);  
    insert(root, 4);  
    insert(root, 3);  
    insert(root, 5);  
    
    // Display the BST in order
    printf("Tree(inOrder):\n");  
    inOrderTraversal(root);  
    printf("\n");  

    // Searching for an element
    if(search(root , 20)){
        printf("Element Found in BST\n");
    }
    else{
        printf("Element not Found in BST\n");
    }
    return 0;  
}
```

## Output
When you run the program, you will see an output similar to:

```
Tree(inOrder):
1 2 3 4 5 
Element not Found in BST
```
This output indicates the nodes have been successfully inserted and traversed in sorted order. The search for the number `20` returns false, indicating that the value is not present in the BST.
If we change the element value to the number `2`, the output will change as follows:

```
Tree(inOrder):
1 2 3 4 5 
Element Found in BST
```

## Compiling and Running
To compile and run this program, use the following commands in your terminal:

```bash
gcc -o bst_search bst_search.c
./bst_search
```

Make sure to replace `bst_search.c` with the filename where the code is stored.

## Conclusion
This program demonstrates the creation and use of a Binary Search Tree in C. It highlights efficient node insertion and searching operations, which are crucial for handling sorted data efficiently. The search function leverages the properties of the BST, ensuring that searches can be performed in O(h) time complexity, where h is the height of the tree. Future enhancements can include deleting nodes, balancing the tree, or implementing additional traversal methods.
