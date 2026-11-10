#include <stdio.h>
#include <stdlib.h>

/*
 * ============================================================================
 * DATA STRUCTURES & ALGORITHMS - LAB ASSIGNMENT: LINKED LIST TRAVERSAL
 * ============================================================================
 *
 * OVERVIEW & LOGIC:
 *
 * 1. Node Structure:
 *    - Defines struct Node with int data and struct Node *next.
 *
 * 2. Manual List Construction:
 *    - Allocates three separate nodes (head, next1, next2) on the heap.
 *    - Links them sequentially to form 10 -> 20 -> 30 -> NULL.
 *
 * 3. Sequential Traversal:
 *    - Initializes a traversal pointer current = head.
 *    - Loops while current != NULL, printing current->data and advancing
 *      to the next node via current = current->next.
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
	
		
	head= (struct Node*)malloc(sizeof (struct Node));
	next1=malloc(sizeof(struct Node));
	next2=malloc(sizeof(struct Node));
	
	head->data=10;
	head->next=next1;
 			
	next1->data=20;
	next1->next=next2;
	
	next2->data=30;
	next2->next=NULL;
	struct Node *current = head;
	
	while(current!=NULL){
		
		
		
		printf("%d\n", current->data);
		
		current=current->next;
		
	};
	
	
	
	return 0;
}
