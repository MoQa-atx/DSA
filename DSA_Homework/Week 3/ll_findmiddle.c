#include <stdio.h>
#include <stdlib.h>

/*
 * ============================================================================
 * DATA STRUCTURES & ALGORITHMS - LAB ASSIGNMENT: FIND MIDDLE NODE
 * ============================================================================
 * 
 * OVERVIEW & LOGIC:
 * 
 * 1. Node Structure:
 *    - Represents each singly linked list element containing an integer payload
 *      (`data`) and a reference pointer (`next`) to the subsequent node.
 * 
 * 2. findMiddle(Node* head):
 *    - Implements the Two-Pointer technique (Tortoise and Hare algorithm) to find
 *      the middle element in O(N) time and O(1) space without needing to count
 *      the total number of nodes in advance.
 *    - Uses two traversal pointers initialized at `head`:
 *      * `slow`: Steps forward 1 node per iteration (`slow = slow->next`).
 *      * `fast`: Steps forward 2 nodes per iteration (`fast = fast->next->next`).
 *    - Loop Condition:
 *      * Runs while `fast != NULL && fast->next != NULL`.
 *    - Results:
 *      * Odd-sized list: Loop terminates when `fast->next == NULL`. `slow` points
 *        to the exact middle node.
 *      * Even-sized list: Loop terminates when `fast == NULL`. `slow` points to
 *        the second of the two middle nodes as required.
 *      * Empty list (`head == NULL`): Safely returns NULL immediately.
 * 
 * 3. printList(Node* head):
 *    - Traverses sequentially from head to NULL, printing each node's value.
 * 
 * 4. clear(Node** head):
 *    - Frees every dynamically allocated node one by one while keeping track of
 *      `next` before deallocation, then resets `*head` to NULL.
 * ============================================================================
 */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* findMiddle(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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
    Node *middle = NULL;

    // Test 1: Empty list
    middle = findMiddle(head);
    if (middle == NULL) {
        printf("Empty list test: Middle is NULL\n");
    }

    // Creating nodes manually: 10 -> 20 -> 30 -> 40 -> 50 -> NULL (Odd length)
    Node *n1 = (Node*)malloc(sizeof(Node));
    Node *n2 = (Node*)malloc(sizeof(Node));
    Node *n3 = (Node*)malloc(sizeof(Node));
    Node *n4 = (Node*)malloc(sizeof(Node));
    Node *n5 = (Node*)malloc(sizeof(Node));

    n1->data = 10; n1->next = n2;
    n2->data = 20; n2->next = n3;
    n3->data = 30; n3->next = n4;
    n4->data = 40; n4->next = n5;
    n5->data = 50; n5->next = NULL;

    head = n1;

    printf("\nOdd List: ");
    printList(head);

    middle = findMiddle(head);
    if (middle != NULL) {
        printf("Middle Node Data (Odd): %d\n", middle->data);
    }

    // Adding 6th node to test even length: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> NULL
    Node *n6 = (Node*)malloc(sizeof(Node));
    n6->data = 60;
    n6->next = NULL;
    n5->next = n6;

    printf("\nEven List: ");
    printList(head);

    middle = findMiddle(head);
    if (middle != NULL) {
        printf("Middle Node Data (Even - Second Middle): %d\n", middle->data);
    }

    // Clean up
    clear(&head);
    printf("\nAfter clear: ");
    printList(head);

    return 0;
}