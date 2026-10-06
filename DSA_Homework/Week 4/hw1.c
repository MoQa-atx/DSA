#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char name[50];
    struct Song* next;
    struct Song* prev;
} Song;

void addSongToEnd(Song** head, char* name){

    // create a new node and allocate memory
    Song *newSong = malloc(sizeof(Song));

    if(newSong == NULL){
        return;
    }

    // copy the name and reset pointers
    strcpy(newSong->name, name);
    newSong->next = NULL;
    newSong->prev = NULL;

    // if playlist is empty, this becomes the first song
    if((*head) == NULL){
        *head = newSong;
        return;
    }

    // traverse until the last node
    Song *current = *head;
    while(current->next != NULL){
        current = current->next;
    }

    // link the new song to the end
    newSong->prev = current;
    current->next = newSong;
}

void removeSong(Song** head, char* name){
    Song *current = *head;

    // look for the song name in the list
    while (current != NULL && strstr(current->name, name) == NULL) {
        current = current->next;
    }

    // not found
    if(current == NULL){
        printf("Song not found in playlist\n");
        return;
    }
    // case 1: removing the first song
    else if(current == (*head)){
        *head = (*head)->next;
        if(*head != NULL){
            (*head)->prev = NULL;
        }
        free(current);
    }
    // case 2: removing the last song
    else if(current->next == NULL){
        current->prev->next = NULL;
        free(current);
    }
    // case 3: removing from middle
    else{
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    }
}

void playNext(Song** current){

    if(*current == NULL){
        printf("Playlist is empty\n");
        return;
    }

    // check if there is a next song before moving
    if ((*current)->next != NULL) {
        *current = (*current)->next;
        printf("Now playing: %s\n", (*current)->name);
    } else {
        printf("Already at the last song!\n");
    }
}

void playPrevious(Song** current){

    if(*current == NULL){
        printf("Playlist is empty\n");
        return;
    }

    // check if there is a previous song before moving back
    if ((*current)->prev != NULL) {
        *current = (*current)->prev;
        printf("Now playing: %s\n", (*current)->name);
    } else {
        printf("Already at the first song!\n");
    }
}

void displayPlaylist(Song* head){
    if(head == NULL){
        printf("Playlist is empty\n");
        return;
    }

    Song *current = head;
    int i = 1;

    // print songs one by one
    printf("\n=== PLAYLIST ===\n");
    while(current != NULL){
        printf("%d. %s\n", i, current->name);
        current = current->next;
        i++;
    }
    printf("================\n");
}


int main (void){

    Song *head = NULL;
    Song *current = NULL; // keeps track of the currently playing song
    int choice;
    char name[50];

    while(1){
        printf("\n1. Add Song\n");
        printf("2. Remove Song\n");
        printf("3. Play Next\n");
        printf("4. Play Previous\n");
        printf("5. Display Playlist\n");
        printf("6. Exit\n");
        printf("Choice: ");
        
        scanf("%d", &choice);
        getchar(); // consume the leftover newline

        switch(choice){
            case 1:
                printf("Song name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // trim newline from input

                addSongToEnd(&head, name);
                
                // if nothing was playing yet, set current to the first song
                if(current == NULL){
                    current = head;
                }
                break;

            case 2:
                printf("Song to remove: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;

                removeSong(&head, name);
                
                // reset playback to head to avoid pointing to a deleted node
                current = head;
                break;

            case 3:
                playNext(&current);
                break;

            case 4:
                playPrevious(&current);
                break;

            case 5:
                displayPlaylist(head);
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}