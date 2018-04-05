/* CS261- HW1 - Program2.c*/
/* Name: Henry Coleman
 * Date: April 3
 * Solution description:
 *  Allocate:
 *  Uses malloc to allocate space for 10 students on the heap(10*datatype size)
 *  generate:
 *    seeds rand, iterates through array, assigns random data
 *    for each student (random characters for initials, random [0-100] score)
 *  output:
 *    iterates through array and prints all data for each student
 *  summary: uses a min and a max variable to find lowest and highest score
 *    sums and divides scores for average.
 *  deallocate:
 *    If pointer passed in isn't NULL, it is freed
 *  main:sets student to NULL, then calls all functions in same order
 *    as they are declared (allocate-generate-output-summary-deallocate)
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	struct student* s = malloc(10*sizeof(*s));
     /*return the pointer*/
	return s;
}

void generate(struct student* students){
	srand(time(NULL));
	int i;
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z.
	The scores must be between 0 and 100*/
	for(i = 0; i < 10; i++)
		{
			char fname = rand()%26 + 'A';
			char lname = rand()%26 + 'A';
			int score = rand()%100;
			students[i].initials[0] = fname;
			students[i].initials[1] = lname;
			students[i].score = score;
		}
}

void output(struct student* students){
	int i;
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/
	for(i = 0; i < 10; i++)
		{
			printf("%2d. ",i+1); 						 /*Index*/
			printf("%c.",students[i].initials[0]);	 /*First Initial*/
			printf("%c. ",students[i].initials[1]); /*Last Initial*/
			printf("%5d\n\n",students[i].score);	 /*Score*/
		}
}

void summary(struct student* students){
	int i, min, max;
	float ave;
	min = 100; max = 0;
	ave = 0;
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    for(i = 0; i < 10; i++)
		{
			ave += students[i].score;
			if(students[i].score <= min)
				min = students[i].score;
			if(students[i].score >= max)
				max = students[i].score;
		}
		ave = ave/10;
		printf("\nMaximum score:\t%d\n\n",max);
		printf("Minimum score:\t%d\n\n",min);
		printf("Average score:\t%f\n\n",ave);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
		if(stud != NULL)
			free(stud);
}

int main(){
    struct student* stud = NULL;

    /*call allocate*/
   	stud = allocate();
    /*call generate*/
    	generate(stud);
    /*call output*/
    	output(stud);
    /*call summary*/
    	summary(stud);
    /*call deallocate*/
		deallocate(stud);
    return 0;
}
