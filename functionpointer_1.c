#include<stdio.h>
#include<stdlib.h>
#include <time.h>


//We are going to use a function pointer to call a function. 

int n(int a, int b){ //This is a function that takes two integers as arguments and returns an integer.
        return a + b; //This function returns the sum of the two integers.
    }

int main(){

    int (*p)(int a, int b); //declaring a function pointer. Spot the *. The * tells us that its a pointer

    int (*say) (const char *); //declaring a function pointer. Spot the *. The * tells us that its a pointer

    say = puts; //assigning the address of the function puts to the function pointer say

    say("Hello World"); //calling the function puts using the function pointer say

    p = n; //assigning the address of the function n to the function pointer p

    printf("%d", p(2, 3)); //calling the function n using the function pointer p
    
    return 0; //returning 0
}




