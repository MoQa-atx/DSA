#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PrintJob {
    char fileName[50];
    struct PrintJob* next;
} PrintJob;

typedef struct Queue {
    PrintJob* front;
    PrintJob* rear;
} Queue;

// adds a new print job to the end of the queue (enqueue)
void enqueuePrintJob(Queue* q, char* fileName){
    PrintJob *newJob = malloc(sizeof(PrintJob));
    if(newJob == NULL){
        return;
    }

    strcpy(newJob->fileName, fileName);
    newJob->next = NULL;

    // if queue is empty, both front and rear point to new node
    if(q->rear == NULL){
        q->front = newJob;
        q->rear = newJob;
        printf("Job added to queue: %s\n", fileName);
        return;
    }

    // attach to the end and update rear
    q->rear->next = newJob;
    q->rear = newJob;
    printf("Job added to queue: %s\n", fileName);
}

// prints and removes the first job in line (dequeue)
void processNextJob(Queue* q){
    // check if queue is empty
    if(q->front == NULL){
        printf("No jobs to print! Queue is empty.\n");
        return;
    }

    // hold the front job to free it later
    PrintJob *temp = q->front;
    printf("Printing job: %s\n", temp->fileName);

    // move front to the next job
    q->front = q->front->next;

    // if front became NULL, queue is now completely empty
    if(q->front == NULL){
        q->rear = NULL;
    }

    free(temp);
}

// displays all waiting print jobs from front to rear
void showQueue(Queue q){
    if(q.front == NULL){
        printf("Print queue is empty.\n");
        return;
    }

    PrintJob *current = q.front;
    int index = 1;

    printf("\n=== PRINT QUEUE (FIFO) ===\n");
    while(current != NULL){
        printf("%d. %s\n", index, current->fileName);
        current = current->next;
        index++;
    }
    printf("==========================\n");
}

int main(void){
    // initialize empty queue
    Queue q;
    q.front = NULL;
    q.rear = NULL;

    int choice;
    char fileName[50];

    while(1){
        printf("\n1. Add Print Job\n");
        printf("2. Print Next Job\n");
        printf("3. Show Queue\n");
        printf("4. Exit\n");
        printf("Choice: ");

        if(scanf("%d", &choice) != 1){
            break;
        }
        getchar(); // consume leftover newline

        switch(choice){
            case 1:
                printf("Enter file name: ");
                fgets(fileName, sizeof(fileName), stdin);
                fileName[strcspn(fileName, "\n")] = 0; // trim newline

                enqueuePrintJob(&q, fileName);
                break;

            case 2:
                processNextJob(&q);
                break;

            case 3:
                showQueue(q); // passed by value as in skeleton
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}