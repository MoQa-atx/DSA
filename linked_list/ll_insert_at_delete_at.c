#include <stdio.h>
#include <stdlib.h>

/*
 * ============================================================================
 * DATA STRUCTURES & ALGORITHMS - LAB ASSIGNMENT: SINGLY LINKED LIST
 * ============================================================================
 * 
 * OVERVIEW & LOGIC:
 * 
 * 1. Node Structure:
 *    - Each node holds an integer value (`data`) and a pointer (`next`) to the
 *      following node in the sequence.
 * 
 * 2. insertAt(Node** head, int value, int position):
 *    - Traverses the list once to determine the total number of nodes (`counter`).
 *    - Position <= 0 or empty list: The new node is inserted at the front
 *      (`newNode->next = *head; *head = newNode;`).
 *    - Position >= counter: Traverses until reaching the last valid node
 *      (`current->next != NULL`) and appends the new node to the end.
 *    - Intermediate positions (0 < position < counter): Traverses to index
 *      `position - 1` (the node immediately preceding the insertion point).
 *      Updates pointers safely: `newNode->next = current->next`, followed by
 *      `current->next = newNode`.
 * 
 * 3. deleteAt(Node** head, int position):
 *    - Validates bounds: If the list is empty or `position` is outside the
 *      range `[0, counter - 1]`, prints "Invalid position." and exits without modifying.
 *    - Position == 0: Stores the current head in a temporary pointer, advances
 *      `*head` to `(*head)->next`, and frees the old head.
 *    - Any other valid position: Advances `current` to the target node while
 *      maintaining a trailing pointer `temp` at `position - 1`. Re-links
 *      `temp->next = current->next` to bypass the node, then frees `current`.
 * 
 * 4. printList(Node* head):
 *    - Iterates sequentially through the list from head to `NULL`, printing
 *      each node's data in order.
 * 
 * 5. clear(Node** head):
 *    - Frees every dynamically allocated node in the list sequentially to prevent
 *      memory leaks, safely storing `next` before freeing `current`. Finally,
 *      sets `*head = NULL` to eliminate dangling pointers.
 * ============================================================================
 */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insertAt(Node** head, int value, int position) {
    Node *current = *head;
    Node *newNode = (Node*)malloc(sizeof(Node));
    int counter = 0;
    int nodePos = 0;

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    // Count existing elements
    while (current != NULL) {
        counter++;
        current = current->next;
    }
    current = *head;

    // Case 1: Insert at head (non-positive position or empty list)
    if (position <= 0 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    // Case 2: Insert at tail (position exceeds or equals list length)
    else if (position >= counter) {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        return;
    }
    // Case 3: Insert at specified intermediate index
    else {
        while (current != NULL && nodePos < position - 1) {
            current = current->next;
            nodePos++;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteAt(Node** head, int position) {
    Node *current = *head;
    Node *temp = NULL;
    int nodePos = 0;
    int counter = 0;

    // Count existing elements
    while (current != NULL) {
        counter++;
        current = current->next;
    }
    current = *head;

    // Out-of-bounds or empty list check
    if (*head == NULL || position >= counter || position < 0) {
        printf("Invalid position.\n");
        return;
    }

    // Case 1: Delete head
    if (position == 0) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Case 2: Delete at intermediate or tail position
    while (current != NULL && nodePos < position) {
        temp = current;
        current = current->next;
        nodePos++;
    }
    temp->next = current->next;
    free(current);
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void clear(Node** head) {
    Node* current = *head;
    Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *head = NULL;
}

int main(void) {
    Node *head = NULL;

    // Insertion tests
    insertAt(&head, 10, 0);   // List: 10 -> NULL
    insertAt(&head, 20, 1);   // List: 10 -> 20 -> NULL
    insertAt(&head, 5, -1);   // Negative position to head: 5 -> 10 -> 20 -> NULL
    insertAt(&head, 30, 99);  // Out-of-bound to tail: 5 -> 10 -> 20 -> 30 -> NULL
    insertAt(&head, 15, 2);   // Insert at index 2: 5 -> 10 -> 15 -> 20 -> 30 -> NULL

    printf("Initial List:\n");
    printList(head);

    // Deletion tests
    deleteAt(&head, 0);       // Delete head (5): 10 -> 15 -> 20 -> 30 -> NULL
    deleteAt(&head, 1);       // Delete index 1 (15): 10 -> 20 -> 30 -> NULL
    deleteAt(&head, 10);      // Invalid position check

    printf("\nList After Deletions:\n");
    printList(head);

    // Memory clean-up
    clear(&head);
    printf("\nList After Clearing:\n");
    printList(head);

    return 0;
}