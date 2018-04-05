/* CS261- HW1 - Program3.c*/
/* Name: Henry Coleman
 * Date: April 3, 2018
 * Solution description:
 *    Sorting function uses bubble sort
 *          (I don't really know other algorithms yet)
 *     time library called to seed random
 *     array of numbers is allocated, filled with random numbers (0-999)
 *     Printed, and freed.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n){
	int i, j, tmp;
    /*Sort the array of integers of length n*/
	for(i = 0; i < n-1; i++)
    for(j = 0; j < n-i-1; j++)
        if(number[j] > number[j+1])
        {
          tmp = number[j];
          number[j] = number[j+1];
          number[j+1] = tmp;
        }
}

int main(){
    srand(time(NULL));
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
	 int* array = malloc(n*sizeof(int));
    /*Fill this array with random numbers, using rand().*/
	 int i;
    for(i = 0; i < n; i++)
			array[i] = rand()%1000;
    /*Print the contents of the array.*/
    printf("UNSORTED\n");
	 for(i = 0; i < n; i++)
			printf("%d\n", array[i]);
    /*Pass this array along with n to the sort() function of part a.*/
      sort(array, n);
    /*Print the contents of the array.*/
      printf("SORTED:\n");
      for(i = 0; i < n; i++)
        printf("%d\n", array[i]);

    return 0;
}
