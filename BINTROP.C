#include <stdio.h>
#include <conio.h>
#include<alloc.h>


// Node structure for binary tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to perform an inorder traversal of the binary tree
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to calculate the height of the binary tree
int calculateHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);

        // Return the height of the taller subtree, plus one for the current level
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

// Main function
int main() {
    struct TreeNode* root = NULL;
    // clrscr();
    // Insert nodes into the binary tree
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    // Perform inorder traversal and display the elements
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Calculate and display the height of the binary tree
    int height = calculateHeight(root);
    printf("Height of the Binary Tree: %d\n", height);

    getch(); // Wait for a key press before closing the console window
    return 0;
}
