#include <stdio.h>
#include <stdlib.h>

/*
 * ============================================================================
 * DATA STRUCTURES & ALGORITHMS - LAB ASSIGNMENT: BST SEARCH & MINIMUM VALUE
 * ============================================================================
 *
 * OVERVIEW & LOGIC:
 *
 * 1. BST Construction:
 *    - Uses insert() to populate a Binary Search Tree from the array
 *      {40, 20, 60, 10, 30, 50, 70}.
 *
 * 2. search(Node* root, int value):
 *    - Recursively searches for value in O(h) time (where h is tree height):
 *      * Returns 0 if root == NULL (not found) or 1 if root->data == value.
 *      * Branches left if value < root->data, or right if value > root->data.
 *
 * 3. findMin(Node* root):
 *    - Exploits the BST property by iteratively following root = root->left
 *      until root->left == NULL, returning the leftmost (minimum) key.
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

int search(Node* root, int value) {
    if (root == NULL)
        return 0;

    if (root->data == value)
        return 1;

    if (value < root->data)
        return search(root->left, value);

    return search(root->right, value);
}

int findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;

    return root->data;
}

int main() {
    Node* root = NULL;
    int numbers[] = {40, 20, 60, 10, 30, 50, 70};

    for (int i = 0; i < 7; i++)
        root = insert(root, numbers[i]);

    if (search(root, 30))
        printf("30 was found in the tree.\n");
    else
        printf("30 was not found in the tree.\n");

    if (search(root, 90))
        printf("90 was found in the tree.\n");
    else
        printf("90 was not found in the tree.\n");

    if (root != NULL)
        printf("Minimum element: %d\n", findMin(root));

    return 0;
}