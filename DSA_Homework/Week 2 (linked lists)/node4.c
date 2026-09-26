#include <stdio.h>
#include <stdlib.h>

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
	printf("Node counter=%d", counter);
	
	free(head);
	free(next1);
	free(next2);
	free(next3);




	return 0;
}
