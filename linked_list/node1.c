#include <stdio.h>
#include <stdlib.h>

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
