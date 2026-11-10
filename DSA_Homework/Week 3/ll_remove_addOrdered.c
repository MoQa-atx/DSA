#include <stdio.h>
#include <stdlib.h>

/*
 * ============================================================================
 * DATA STRUCTURES & ALGORITHMS - LAB ASSIGNMENT: ORDERED LINKED LIST
 * ============================================================================
 * 
 * OVERVIEW & LOGIC:
 * 
 * 1. Node Structure:
 *    - Each node represents an element in the singly linked list holding an
 *      integer payload (`data`) and a reference pointer (`next`) to the succeeding node.
 * 
 * 2. addOrdered(Node** head, int value):
 *    - Inserts a new node while preserving ascending numerical order.
 *    - Allocates memory for `newNode` and verifies successful allocation.
 *    - Case 1 (Empty list or smallest value): If the list is empty (`*head == NULL`)
 *      or the given value is smaller than the head's data (`(*head)->data > value`),
 *      the new node is placed at the front, becoming the new head.
 *    - Case 2 (Intermediate or tail insertion): Traverses using a single pointer
 *      `current` while `current->next != NULL` and `current->next->data < value`.
 *      Once the correct spot is found, links `newNode->next = current->next`
 *      and `current->next = newNode`.
 * 
 * 3. removeNode(Node** head, int value):
 *    - Searches for the first occurrence of a node holding `value` and removes it.
 *    - Case 1 (Target is head): If `(*head)->data == value`, advances `*head`
 *      to `(*head)->next` and frees the initial head node.
 *    - Case 2 (Target is inside or at tail): Traverses the list maintaining a
 *      `previous` pointer behind `current`. If matched, bypasses the node via
 *      `previous->next = current->next` and deallocates it.
 *    - If the value is not found after full traversal, an error message is printed.
 * 
 * 4. count(Node* head):
 *    - Iterates through the list sequentially, incrementing a counter variable
 *      until reaching NULL, then returns the total node count.
 * 
 * 5. printList(Node* head):
 *    - Sequentially traverses the list and prints all node values.
 * 
 * 6. clear(Node** head):
 *    - Safely releases all heap-allocated nodes sequentially by storing
 *      `current->next` before freeing `current`, then sets `*head = NULL`.
 * ============================================================================
 */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void addOrdered(Node** head, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    // Case 1: Insert at the beginning (empty list or value is smaller than head)
    if (*head == NULL || (*head)->data > value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Case 2: Traverse to find the proper insertion point
    Node *current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void removeNode(Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty. Value cannot be removed.\n");
        return;
    }

    Node *current = *head;
    Node *previous = NULL;

    // Case 1: The node to be deleted is the head node
    if (current->data == value) {
        *head = current->next;
        free(current);
        return;
    }

    // Case 2: Search for the node to delete
    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    // If node was found
    if (current != NULL) {
        previous->next = current->next;
        free(current);
    } else {
        printf("The number %d is not in the list.\n", value);
    }
}

int count(Node* head) {
    int counter = 0;
    Node *current = head;

    while (current != NULL) {
        current = current->next;
        counter++;
    }

    return counter;
}

void printList(Node* head) {
    Node *current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void clear(Node** head) {
    Node *current = *head;
    Node *temp = NULL;

    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }

    *head = NULL;
}

int main(void) {
    Node *head = NULL;

    printf("--- Ordered Insertion Tests ---\n");
    addOrdered(&head, 30);
    addOrdered(&head, 10);
    addOrdered(&head, 50);
    addOrdered(&head, 20);
    addOrdered(&head, 40);

    printList(head);
    printf("Total elements: %d\n\n", count(head));

    printf("--- Deletion Tests ---\n");
    // Remove head (10)
    removeNode(&head, 10);
    printList(head);

    // Remove middle (30)
    removeNode(&head, 30);
    printList(head);

    // Try to remove a non-existent element (99)
    removeNode(&head, 99);
    printList(head);
    printf("Total elements after deletions: %d\n\n", count(head));

    printf("--- Clearing List ---\n");
    clear(&head);
    printList(head);
    printf("Total elements after clear: %d\n", count(head));

    return 0;
}