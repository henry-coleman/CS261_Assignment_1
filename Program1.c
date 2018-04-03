/* CS261- HW1 - Program1.c*/
/* Name: Henry Coleman
 * Date: April 3, 2018
 * Solution description: 
	  foo() takes pointers to two integers (a and b) and an integer (c),
		increments a, decrements b, and subtracts b from a (by pointer)
		and stores & returns the result in c
	  main() declares three random integers, prints their initial value,
		passes them into foo(), and prints their new values.
		
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
    /* Increment a */
	*a += 1;    
    /* Decrement  b */
   *b -= 1; 
    /* Assign a-b to c */
   c = *a - *b; 
    /* Return c */
	return c;
}

int main(){
	srand(time(NULL)); 
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
	int x = rand()%11,
		 y = rand()%11,
		 z = rand()%11;
    /* Print the values of x, y and z */
   printf("X =\t %d \n",x);
   printf("Y =\t %d \n",y);
   printf("Z =\t %d \n",z);
    /* Call foo() appropriately, passing x,y,z as parameters */
	int* a = &x;
	int* b = &y;
	int result = foo(a,b,z);
    /* Print the values of x, y and z */
   printf("X' =\t %d \n",x);
   printf("Y' =\t %d \n",y);
   printf("Z' =\t %d \n",z);
    /* Print the value returned by foo */
 	printf("Foo() returned:\t %d \n",result); 
    /* Is the return value different than the value of z?  Why? */
	printf("Passing z into foo() by value creates a different scope than main()\n");
	printf("and copies the immediate value stored in z to create a new variable local to foo().\n");
	printf("This implies that z remains the same as before the call to foo(),\n");
	printf("which copies the final value of c into the variable labelled result.\n");
	
    return 0;
}
    
    
