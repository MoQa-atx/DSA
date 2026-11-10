#include <stdio.h>

/*
 * ============================================================================
 * DATA STRUCTURES & ALGORITHMS - LAB ASSIGNMENT: ARRAY I/O & BIG-O COMPLEXITY
 * ============================================================================
 *
 * OVERVIEW & LOGIC:
 *
 * 1. Static Array Allocation:
 *    - Declares an integer array numbers[10] to store 10 elements in
 *      contiguous memory (O(n) space complexity where n = 10).
 *
 * 2. Input Loop - O(n) Time Complexity:
 *    - Iterates from i = 0 to 9, prompting the user and reading 10 integers
 *      into numbers[i] using scanf().
 *
 * 3. Output Loop - O(n) Time Complexity:
 *    - Iterates from i = 0 to 9 a second time, printing each element with
 *      its 1-based position (i + 1).
 *
 * 4. Complexity Analysis:
 *    - Total step count function: T(n) = 7n + 7, which simplifies to O(n)
 *      linear time complexity (O(2n) -> O(n)).
 *    - Space usage: S(n) = n + 1 (n array slots + loop counter i).
 * ============================================================================
 */

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