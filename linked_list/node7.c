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
	struct Node *newNode=NULL;
    struct Node *temp=NULL;
	int counter=0;
	int sum=0;
    


	head= (struct Node*)malloc(sizeof (struct Node));
	next1=malloc(sizeof(struct Node));
	next2=malloc(sizeof(struct Node));
	next3=malloc(sizeof(struct Node));
    newNode=malloc(sizeof(struct Node));
    
    

	head->data=10;
	head->next=next1;
 			
	next1->data=20;
	next1->next=next2;
	
	next2->data=30;
	next2->next=next3;
	
	next3->data=40;
	next3->next=NULL;
	
    newNode->data=5;
    newNode->next=head;
    head=newNode;
    
	struct Node *current = head;
    
    
	
	while(current!=NULL){
		
		
		
		printf("%d\n", current->data);
        
      
        


		sum=sum+current->data;
		current=current->next;
		counter++;
        

        
	};

    current = head; 
    while(current!=NULL){

        temp=current->next;
        free(current);
        current=temp;

    }


	printf("Node counter=%d\n", counter);
	printf("Sum=%d\n", sum);





	
    



	return 0;
}
