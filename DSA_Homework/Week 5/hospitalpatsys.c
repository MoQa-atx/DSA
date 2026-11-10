
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * ============================================================================
 * DATA STRUCTURES & ALGORITHMS - LAB ASSIGNMENT: HOSPITAL PATIENT SYSTEM
 * ============================================================================
 *
 * OVERVIEW & LOGIC:
 *
 * 1. Node Structure:
 *    - Stores patient information such as ID, name, status, and next pointer.
 *
 * 2. Queue (FIFO):
 *    - Stores waiting patients.
 *    - enqueue() adds a patient to the end.
 *    - dequeue() removes the patient at the front.
 *
 * 3. Stack (LIFO):
 *    - Stores patients during examination.
 *    - push() adds a patient to the top.
 *    - pop() removes the patient from the top.
 *
 * 4. History Linked List:
 *    - Stores patients whose examinations are completed.
 *    - New patients are added to the end of the list.
 *
 * 5. Main Logic:
 *    - Creates three patients and adds them to the queue.
 *    - Examines Ahmet and Mehmet, then moves them to the history list.
 *    - Ayse remains in the waiting queue.
 *
 * 6. Memory Cleanup:
 *    - freeAll() releases the memory allocated for all remaining nodes.
 * ============================================================================
 */


typedef struct Node {
    int id;
    char name[50];
    char status[20];
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

typedef struct {
    Node* top;
} Stack;

typedef struct {
    Node* head;
    Node* tail;
} HistoryList;



Node* createNode(int id, const char* name, const char* status){

    Node* node = malloc(sizeof(Node));

    if(node == NULL){

        return NULL;

    }

    node->id=id;
    strcpy(node->name,name);
    strcpy(node->status,status);
    node->next = NULL;
    
    return node;

}


void initQueue(Queue* q){
 
    q->front=NULL;
    q->rear=NULL;

}
void initStack(Stack* s){
    s->top=NULL;
}
void initHistoryList(HistoryList* list){
    list->head=NULL;
    list->tail=NULL;
}




int isQueueEmpty(Queue* q){

    if(q->front!=NULL){
        return 0;
    }
    else{
        return 1;
    }
}
void enqueue(Queue* q, Node* newNode){

    if(q->front == NULL){

        newNode->next=NULL;
        q->front=newNode;
        q->rear=newNode;


    }
    else{

        q->rear->next = newNode; 
        q->rear = newNode;       
        newNode->next = NULL;

    }

}
Node* dequeue(Queue* q){

    if(isQueueEmpty(q)){

        printf("Queue is empty.\n");
        return NULL;
    }
    
    Node* temp = q->front;

    q->front=q->front->next;

    if (q->front == NULL) {
    q->rear = NULL;
}



    temp->next=NULL;
    return temp;



}
void printQueue(Queue* q){

    if(isQueueEmpty(q)){

        printf("No waiting patients.\n");
        return;

    }

Node* first = q->front;

while(first!=NULL){

    printf("ID: %d, Name: %s, Status: %s\n",first->id,first->name,first->status);

    first = first->next;
}


}



int isStackEmpty(Stack* s){
    if(s->top!=NULL){
        return 0;
    }
    else{
        return 1;
    }
}
void push(Stack* s, Node* node){

    node->next=s->top;
    s->top=node;

}
Node* pop(Stack* s){

if (isStackEmpty(s)) {
    return NULL;
}

    Node *temp = s->top;


    s->top=s->top->next;

    temp->next=NULL;
    return temp;


}
void printStack(Stack* s){

    if(isStackEmpty(s)){

        printf("No patients are being examined.\n");
        return;
    }

    Node* current = s->top;

    while(current!=NULL){

        printf("ID: %d, Name: %s, Status: %s\n",current->id,current->name,current->status);

        current = current->next;

    }


}


void addHistory(HistoryList* list, Node* node){

    if (list == NULL || node == NULL) {
        return;
    }


    if(list->head == NULL){

        list->head=node;
        list->tail=node;

    }
    else{

        list->tail->next=node;
        list->tail=node;


    }


}
void printHistory(HistoryList* list){
if(list == NULL || list->head == NULL){


        printf("No completed patients.\n");

        return;
    }

Node* current = list->head;

while(current!=NULL){

    printf("ID: %d, Name: %s, Status: %s\n",current->id,current->name,current->status);

    current = current->next;
}

}




void freeAll(HistoryList* list, Queue* q, Stack* s){

    Node* current = list->head;

    while(current!=NULL){

        list->head=list->head->next;
        free(current);
        current=list->head;


    }
    list->tail = NULL;

    current = q->front;

    while(current!=NULL){

        q->front=q->front->next;
        free(current);
        current=q->front;


    }

    q->rear=NULL;

    current = s->top;

    while(current!=NULL){

        s->top=s->top->next;
        free(current);
        current=s->top;



    }
    s->top = NULL;

}




int main(void){

    Queue q;
    Stack s;
    HistoryList list;


    initQueue(&q);
    initStack(&s);
    initHistoryList(&list);

    Node* pat1 = createNode(1,"Ahmet","Waiting");
    Node* pat2 = createNode(2,"Mehmet","Waiting");
    Node* pat3 = createNode(3,"Ayse","Waiting");

    if (pat1 == NULL || pat2 == NULL || pat3 == NULL) {
        free(pat1);
        free(pat2);
        free(pat3);
        printf("Failed to create patients!\n");
        return 1;
    }

    enqueue(&q, pat1);
    enqueue(&q, pat2);
    enqueue(&q, pat3);

    // Examine Ahmet
    Node* patient = dequeue(&q);

    if(patient != NULL){

        strcpy(patient->status,"Under Examination");
        push(&s,patient);

        patient = pop(&s);

        if(patient!=NULL){

            strcpy(patient->status,"Completed");
            addHistory(&list,patient);


        }



    }

    // Examine Mehmet
    patient = dequeue(&q);

    if(patient != NULL){

        strcpy(patient->status,"Under Examination");
        push(&s,patient);

        patient = pop(&s);

        if(patient!=NULL){

            strcpy(patient->status,"Completed");
            addHistory(&list,patient);


        }



    }

    printf("\n=== WAITING PATIENTS ===\n");
    printQueue(&q);

    printf("\n=== PATIENTS UNDER EXAMINATION ===\n");
    printStack(&s);

    printf("\n=== COMPLETED PATIENTS ===\n");
    printHistory(&list);

    // Release allocated memory
    freeAll(&list, &q, &s);

    return 0;
}
