#include <stdio.h>
#include <stdlib.h>

/*
 * ============================================================================
 * DATA STRUCTURES & ALGORITHMS - LAB ASSIGNMENT: COUNTING LINKED LIST NODES
 * ============================================================================
 *
 * OVERVIEW & LOGIC:
 *
 * 1. List Construction:
 *    - Dynamically allocates four nodes (head, next1, next2, next3)
 *      and links them in order: 10 -> 20 -> 30 -> 40 -> NULL.
 *
 * 2. Traversal & Node Counting:
 *    - Uses current = head and an integer counter = 0.
 *    - Iterates through the list until current == NULL, printing each node's
 *      data and incrementing counter at every visited node.
 *
 * 3. Output:
 *    - Prints the total node count after traversal completes.
 * ============================================================================
 */

struct Node{

int data;
struct Node *next;

	

};	



int main(void){
	
	struct Node *head=NULL;
	struct Node *next1=NULL;
	struct Node *next2=NULL;	
	struct Node *next3=NULL;
		
	int counter=0;
		
	head= (struct Node*)malloc(sizeof (struct Node));
	next1=malloc(sizeof(struct Node));
	next2=malloc(sizeof(struct Node));
	next3=malloc(sizeof(struct Node));
	head->data=10;
	head->next=next1;
 			
	next1->data=20;
	next1->next=next2;
	
	next2->data=30;
	next2->next=next3;
	
	next3->data=40;
	next3->next=NULL;
	
	
	struct Node *current = head;
	
	while(current!=NULL){
		
		
		
		printf("%d\n", current->data);
		
		current=current->next;
		counter++;
	};
	printf("Node sayisi=%d", counter);
	
	
	return 0;
}
