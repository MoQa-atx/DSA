#include <stdio.h>
#include <stdlib.h>

/*
 * ============================================================================
 * DATA STRUCTURES & ALGORITHMS - LAB ASSIGNMENT: SUM & COUNT OF NODES
 * ============================================================================
 *
 * OVERVIEW & LOGIC:
 *
 * 1. List Construction:
 *    - Creates a 4-node singly linked list (10 -> 20 -> 30 -> 40 -> NULL).
 *
 * 2. Traversal, Counting & Summation:
 *    - Initializes counter = 0 and sum = 0.
 *    - In a single traversal pass (while current != NULL), prints each
 *      node's value, adds current->data to sum, and increments counter.
 *
 * 3. Output & Memory Cleanup:
 *    - Displays both the total node count and the sum of all node values, then
 *      frees all four nodes from heap memory.
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
	int sum=0;

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
        
		sum=sum+current->data;
		current=current->next;
		counter++;
        


	};


	printf("Node counter=%d\n", counter);
	printf("Sum=%d\n", sum);

	free(head);
	free(next1);
	free(next2);
	free(next3);




	return 0;
}
