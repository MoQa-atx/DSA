#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Song {
char name[50];
struct Song* next;
struct Song* prev;
} Song;


void addSongToEnd(Song** head, char* name){

    Song *current = *head;
    Song *newSong = malloc(sizeof(Song));
    if((*head)==NULL){

        *head=newSong;

        return;


    }


if(newSong==NULL){

        return NULL;
    }


    strcpy(newSong->name, name);
    newSong->next=NULL;
    newSong->prev=NULL;

while(current->next!=NULL){
    current=current->next;
}

newSong->prev=current;
current->next=newSong;




}
void removeSong(Song** head, char* name){
    Song *current = *head;
    Song* temp = NULL;

    while (current != NULL && strstr(current->name, name) == NULL) {
    current = current->next;
}
if(current==NULL){
    printf("muzik yok ki listede");
    return;
}
else if(current==(*head)){

*head=(*head)->next;
if(*head!=NULL){
    (*head)->prev = NULL;
}

free(current);
    


}
else if(current->next==NULL){

    current->prev->next=NULL;
    free(current);


}
else{
    current->prev->next=current->next;
    current->next->prev=current->prev;
    free(current);


}

    

}
void playNext(Song** current){




}
void playPrevious(Song** current);
void displayPlaylist(Song* head);



int main (void){

Song *head = malloc(sizeof(Song));


strcpy(head->name, "FUCKING NIGGER");
head->next=NULL;
head->prev=NULL;

 







    return 0;
}