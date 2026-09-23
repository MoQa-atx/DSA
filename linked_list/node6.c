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
	int sum=0;
    int search=0;
    int flag=0;


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

    printf("Which number do you want to search:");
    scanf("%d", &search);
	
	while(current!=NULL){
		
		
		
		printf("%d\n", current->data);
        
        if(search==current->data){
            printf("There is the number you searching for:%d...\n",current->data);
            flag++;
        }
        


		sum=sum+current->data;
		current=current->next;
		counter++;
        


	};

    if(flag<=0){
        printf("The number you are looking for is not at any node.\n");
    }

	printf("Node counter=%d\n", counter);
	printf("Sum=%d\n", sum);

	free(head);
	free(next1);
	free(next2);
	free(next3);




	return 0;
}
