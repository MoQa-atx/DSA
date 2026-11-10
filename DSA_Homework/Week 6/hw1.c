#include <stdio.h>
#include <stdlib.h>

/*
 * ============================================================================
 * DATA STRUCTURES & ALGORITHMS - LAB ASSIGNMENT: BST INSERT & INORDER TRAVERSAL
 * ============================================================================
 *
 * OVERVIEW & LOGIC:
 *
 * 1. BST Node Structure:
 *    - Represents a binary tree node with int data and child pointers
 *      left (smaller values) and right (larger values).
 *
 * 2. insert(Node* root, int value):
 *    - Recursively inserts value while maintaining the Binary Search Tree
 *      property:
 *      * Base case (root == NULL): Allocates and returns a new leaf node.
 *      * Recursive step: Inserts into root->left if value < root->data, or
 *        into root->right if value > root->data.
 *
 * 3. inorder(Node* root):
 *    - Performs Left -> Root -> Right depth-first traversal, which outputs all
 *      elements of the BST in ascending sorted order (10 20 30 40 50 60 70).
 * ============================================================================
 */

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* insert(Node* root, int value) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int numbers[] = {40, 20, 60, 10, 30, 50, 70};

    for (int i = 0; i < 7; i++)
        root = insert(root, numbers[i]);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    return 0;
}