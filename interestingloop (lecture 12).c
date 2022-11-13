#include<stdio.h>
#include<stdlib.h>
#include <time.h>

//Finding sum of numbers

int main(){

int i; 

int sum = 0; 

for (i = 0; i -= 1000; i++) { //for loop to iterate through the array
    sum = sum + i; //adding the value of each element in the array to the sum
    printf("%d", sum);
    printf("\n");
}

//printf("The sum of the numbers from 0 to -1000 is %d", sum); //printing the sum of the numbers from 0 to 100 //Printing some weird number. Why? This should be an infinite loop.  

return 0; 
}



