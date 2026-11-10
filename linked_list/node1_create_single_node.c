#include <stdio.h>
#include <stdlib.h>

/*
 * ============================================================================
 * DATA STRUCTURES & ALGORITHMS - LAB ASSIGNMENT: CREATE SINGLE NODE
 * ============================================================================
 *
 * OVERVIEW & LOGIC:
 *
 * 1. Node Structure:
 *    - Defines struct Node containing an integer payload (data) and a
 *      self-referential pointer (next) to the next node in the list.
 *
 * 2. Dynamic Memory Allocation:
 *    - Initializes head to NULL, then allocates heap memory for a single
 *      node using malloc(sizeof(struct Node)).
 *
 * 3. Node Initialization:
 *    - Assigns head->data = 10 and sets head->next = NULL to indicate that
 *      this single node is also the end of the linked list.
 * ============================================================================
 */

struct Node{

int data;
struct Node *next;
	
	

};	



int main(void){
	
	struct Node *head=NULL;
	
	
	head= (struct Node*)malloc(sizeof (struct Node));

	
	head->data=10;
	head->next=NULL;
 
	
	
	return 0;
}
