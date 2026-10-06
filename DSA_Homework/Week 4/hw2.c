#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Word {
    char text[50];
    struct Word* next;
} Word;

// adds a new word to top of the stack (push)
void pushWord(Word** top, char* text){
    Word *newWord = malloc(sizeof(Word));
    if(newWord == NULL){
        return;
    }

    strcpy(newWord->text, text);
    
    // new node points to current top, then becomes the new top
    newWord->next = *top;
    *top = newWord;
}

// removes the last added word from the stack (pop / undo)
void popWord(Word** top){
    // nothing to undo if stack is empty
    if(*top == NULL){
        printf("Nothing to undo!\n");
        return;
    }

    // hold the current top, move top to next, then free old node
    Word *temp = *top;
    *top = (*top)->next;
    free(temp);
}

// helper recursive function to print words in correct chronological order
void printWordsInOrder(Word* current){
    if(current == NULL){
        return;
    }

    // go all the way to the bottom first
    printWordsInOrder(current->next);

    // print on the way back up
    printf("%s ", current->text);
}

// prints current text state
void showWords(Word* top){
    if(top == NULL){
        printf("Text is empty.\n");
        return;
    }

    printWordsInOrder(top);
    printf("\n");
}

int main(void){
    Word *top = NULL;
    char command[20];
    char text[50];

    while(1){
        printf("> ");
        if(scanf("%s", command) != 1){
            break;
        }

        if(strcmp(command, "add") == 0){
            // read the word to append
            scanf("%s", text);
            pushWord(&top, text);
        }
        else if(strcmp(command, "undo") == 0){
            popWord(&top);
        }
        else if(strcmp(command, "show") == 0){
            showWords(top);
        }
        else if(strcmp(command, "exit") == 0){
            break;
        }
        else{
            printf("Unknown command. Use: add, undo, show, exit\n");
        }
    }

    return 0;
}