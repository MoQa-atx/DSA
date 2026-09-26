#include <stdio.h>



int main (void){
    
    int numbers[10]; // 1 time 

    
 

    for(int i =0;i<10;i++){ // first loop =  O(n)
        // int i = 0 -> 1 time
        // i < 10    -> n+1 time 
        // i++       -> n time

        printf("Enter number %d:", i+1); // n time
        scanf("%d", &numbers[i]); // n time
    }
     printf("--------------------\n"); // 1 time

    
    for(int i =0;i<10;i++){ // second loop = O(n)
        // int i = 0 -> 1 time
        // i < 10    -> n+1 time 
        // i++       -> n time

        printf("Number %d : %d\n", i+1,numbers[i]); // n time


    }

    

    return 0; // 1 time

    // S(n) -> numbers using 10 (n) space and there is int i = 0 in 2 loops and that int i = 0 using 1 space so its S(n) = n + 1
    
    // first + second loop = O(2n) 
    // Big O notation = O(n)

    // T(n) = 7n + 7
}