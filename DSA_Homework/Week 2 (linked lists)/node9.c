#include <stdio.h>
#include <stdlib.h>

/*
 * ============================================================================
 * DATA STRUCTURES & ALGORITHMS - LAB ASSIGNMENT: MODULAR SINGLY LINKED LIST
 * ============================================================================
 *
 * OVERVIEW & LOGIC:
 *
 * 1. Insertion Functions:
 *    - insertBeginning(head, val): Prepends a new node to the front in O(1).
 *    - insertEnd(head, val): Appends a new node at the tail in O(n), safely
 *      handling the empty list (head == NULL) edge case.
 *
 * 2. Search & Deletion Functions:
 *    - search(head, target): Performs linear search and returns a pointer to
 *      the matching node (or NULL if not found).
 *    - deleteNode(head, val): Removes the first node matching val, updating
 *      head if the first node is deleted or relinking prev->next otherwise.
 *
 * 3. Aggregation, Display & Cleanup Functions:
 *    - countNodes(head) & sumNodes(head): Return node count and data sum.
 *    - display(head): Prints the list formatted as val -> ... -> NULL.
 *    - freeList(head): Iteratively deallocates all nodes to prevent leaks.
 * ============================================================================
 */

void display(struct Node *head);

struct Node{
    int data;
    struct Node *next;
};


void freeList(struct Node *head) {
    struct Node *current = head;
    struct Node *temp=NULL;
    while(current!=NULL){
        
        temp=current->next;
        free(current);
        current=temp;

    }
    
}

struct Node* insertBeginning(struct Node *head, int val){
    struct Node *newNode= malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=head;
    return newNode;
}

struct Node* search(struct Node *head,int target){
    struct Node *current = head;
    while(current!=NULL){
        if(current->data==target){
            return current;
        }
        current=current->next;
    }
    return NULL;
}

struct Node* insertEnd(struct Node *head, int val){
    
    struct Node *newNode=malloc(sizeof(struct Node));
    struct Node *current=head;
    newNode->data=val;
    if(head==NULL){
        newNode->next=NULL;
        return newNode;
    }

    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newNode;
    newNode->next=NULL;

    return head;
}



struct Node* deleteNode(struct Node *head, int val){

    struct Node *current=head;
    struct Node *prev=NULL;
    if(current != NULL && current->data==val){
        head=current->next;
        free(current);

    }
    else{

        while(current != NULL && current->data!=val){

            prev=current;
            current=current->next;

        }
        if(current != NULL){
            prev->next = current->next;
            free(current);
        }
        else{
            printf("The number you have given is not in the list.\n");
        }


    }

return head;
}


int countNodes(struct Node *head){
    int counter=0;
    struct Node *current=head;

    while(current!=NULL){
        counter++;
        current=current->next;
    }
    return counter;
}


int sumNodes(struct Node *head){
    int sum=0;
    struct Node *current=head;

    while(current!=NULL){
        sum=sum+current->data;
        current=current->next;
    }

    return sum;
}

int main (void){

    struct Node *head = NULL;

    int deletepls=0;
    
    head = insertBeginning(head, 40); 
    head = insertEnd(head, 10);        
    head = insertEnd(head, 20);        
    head = insertEnd(head, 30);        
    head = insertEnd(head, 40);        

    
    struct Node *found = search(head, 20);

    if(found != NULL){
        printf("Target acquired=%d\n", found->data);
    }
    else{
        printf("Your target is not in the list.\n");
    }

    

    display(head);
    printf("Node counter=%d\n", countNodes(head));
    printf("Node sum=%d\n", sumNodes(head));

    printf("Which number do you want to delete?:\n");
    scanf("%d", &deletepls);

    head=deleteNode(head,deletepls);
    
    printf("NEW LIST SHOWCASE wow!!!!1111!!!\n");
    display(head);
    printf("NEW VALUES WOW\n");
    printf("Node counter=%d\n", countNodes(head));
    printf("Node sum=%d\n", sumNodes(head));

    freeList(head);
    head = NULL;

    return 0;
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}