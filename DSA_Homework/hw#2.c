#include <stdio.h>




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