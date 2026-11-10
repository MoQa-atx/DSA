        #include <stdio.h>
        #include <stdlib.h>

/*
 * ============================================================================
 * DATA STRUCTURES & ALGORITHMS - LAB ASSIGNMENT: INSERT AT END & DELETE VALUE
 * ============================================================================
 *
 * OVERVIEW & LOGIC:
 *
 * 1. Head & Tail Insertion:
 *    - Prepends newNode (5) at the beginning of 10 -> 20 -> 30 -> 40.
 *    - Traverses to the last node (while current->next != NULL) and appends
 *      poopNode (99) at the end (5 -> 10 -> 20 -> 30 -> 40 -> 99 -> NULL).
 *
 * 2. Delete Node by User-Given Value:
 *    - Reads iwanttodelete from the user.
 *    - Case 1 (Head Match): Advances head = current->next and frees the old head.
 *    - Case 2 (Interior/Tail Match): Walks the list with prev and current
 *      until finding the target, bypasses it via prev->next = current->next,
 *      and frees current (or prints a not-found message if absent).
 *
 * 3. Display & Cleanup:
 *    - Traverses the modified list to print values, compute counter and sum,
 *      and frees all remaining nodes in a loop.
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
            struct Node *newNode=NULL;
            struct Node *poopNode=NULL;
            struct Node *temp=NULL;
            int counter=0;
            int sum=0;
            int iwanttodelete=0;

            printf("Which number do you want to delete?:");
            scanf("%d", &iwanttodelete);


            head= (struct Node*)malloc(sizeof (struct Node));
            next1=malloc(sizeof(struct Node));
            next2=malloc(sizeof(struct Node));
            next3=malloc(sizeof(struct Node));
            newNode=malloc(sizeof(struct Node));
            poopNode=malloc(sizeof(struct Node));
            

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
            
            poopNode->data=99;


            struct Node *current = head;
            struct Node *prev=NULL;


            while(current->next!=NULL){

                current=current->next;

            }

            current->next = poopNode;  
            poopNode->next = NULL;     

            printf("Lastly added node=%d\n", poopNode->data);



            current = head;
            if(current != NULL && current->data==iwanttodelete){

                head=current->next;
                free(current);

            }
            else{

                while(current != NULL && current->data!=iwanttodelete){

                    prev=current;
                    current=current->next;

                }
                
                if(current != NULL){
                    prev->next = current->next;
                    free(current);
                }
                else{
                    printf("The number you have given is not in the list.\n");
                }







            }
















            current = head;
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
