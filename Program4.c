/* CS261- HW1 - Program4.c*/
/* Name:
 * Date:
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct student{
	char initials[2];
	int score;
} student;



void sort(struct student* students, int n){
    int i,j;
    struct student tmp;
     /*Sort n students based on their initials*/
     for(i = 0; i < n-1; i++)
     {
        for(j = 0; j < n-i-1; j++)
            if(students[j].initials[1] > students[j+1].initials[1])
            {
                tmp = students[j];
                students[j] = students[j+1];
                students[j+1] = tmp;
            }
            if(students[j].initials[1] == students[j+1].initials[1])
            {
              if(students[j].initials[0] > students[j+1].initials[1] )
              {
                tmp = students[j];
                students[j] = students[j+1];
                students[j+1] = tmp;
              }
            }
      }

}

int main(){
    srand(time(NULL));
    /*Declare an integer n and assign it a value.*/
    int n = rand()%25;
    /*Allocate memory for n students using malloc.*/
    student* students = malloc(n*sizeof(struct student));
    /*Generate random IDs and scores for the n students, using rand().*/
    int i;
    for(i = 0; i < n; i++)
    {
        students[i].initials[0] = rand()%26+'A';
        students[i].initials[1] = rand()%26+'A';
        students[i].score = rand()%100;
    }
    /*Print the contents of the array of n students.*/
    printf("UNSORTED\n");
    for(i = 0; i< n; i++)
    {
      printf("Student %d:\n",i+1);
      printf("    ID: %c.",students[i].initials[0]);
      printf("%c.\n", students[i].initials[1]);
      printf("    SCORE: %d\n\n", students[i].score);
    }
    /*Pass this array along with n to the sort() function*/
    sort(students,n);
    /*Print the contents of the array of n students.*/
    printf("SORTED\n");
    for(i = 0; i< n; i++)
    {
      printf("Student %d:\n",i);
      printf("    ID: %c.",students[i].initials[0]);
      printf("%c.\n", students[i].initials[1]);
      printf("    SCORE: %d\n\n", students[i].score);
    }
    return 0;
}
