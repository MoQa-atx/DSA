#include <stdio.h>

/*
 * ============================================================================
 * DATA STRUCTURES & ALGORITHMS - LAB ASSIGNMENT: PALINDROME NUMBER CHECK
 * ============================================================================
 *
 * OVERVIEW & LOGIC:
 *
 * 1. Input & State Preservation:
 *    - Reads an integer x from the user, saves a copy of the original number
 *      in y, and initializes result = 0 to hold the reversed digits.
 *
 * 2. Digit Reversal Algorithm (while x != 0):
 *    - Extracts the last digit of x via modulo (x % 10) and shifts result
 *      left by one decimal place (result = result * 10 + x % 10).
 *    - Strips the last digit from x using integer division (x /= 10).
 *
 * 3. Palindrome Verification:
 *    - Compares the preserved original integer y with the reversed result.
 *    - If y == result, prints that the number is a palindrome; otherwise
 *      reports that it is not a palindrome.
 * ============================================================================
 */

int main(void){

    int result = 0;
    int x;
    int y;

    printf("Enter an integer:");
    scanf("%d", &x);

    y=x;
            
    while(x != 0){

        result = result * 10 + x % 10;

        x /= 10;
    

    }
    
    if(y==result){

        printf("%d is a palindrome.\n ", result);


    }
    else{

        printf("%d is not a palindrome.\n" , result);

    }
    



















    return 0;
}