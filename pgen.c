/*****************************************************************************/
/*****************************************************************************/
/* Date: 22nd May 2023                                                       */
/* Author: Mohammed Faizuddin                                                */
/* Project: Password Generator                                               */
/* For: Learning Arrays, Pointers, Functions                                 */
/* Language: C                                                               */
/* License: Free to use BU must give the credit.                             */
/* GitHub: https://github.com/F21Z                                           */
/*****************************************************************************/
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAT_COUNT   4                
#define LAST_CAT_I  (CAT_COUNT-1)    


#define PASSWORD_LEN    8            

int n_numbers_sum(int *pArray, int ArrayLen, int ArraySum);


int main()
{
    srand(time(NULL));              //seed random
    
    int counts[CAT_COUNT]={0};       //count array holds count of each character category
    int *pcounts= &counts[0];
    
    //printf("\n");
    n_numbers_sum(pcounts, CAT_COUNT, PASSWORD_LEN);

    
    return 0;                                    
}



int n_numbers_sum(int *pArray, int ArrayLen, int ArraySum)
{
    for(int i=0 ;i<LAST_CAT_I ;i++){    //to assign count of each character category except last category
        int range= ArraySum-ArrayLen+1;  //define range as max remaining charecters so that no. of charecters shouldnt exceed given pwd length
        int r= rand() % range;          //GET a random number in range
        *(pArray+i) = 1+r;                 //each character category to appear once or more than once
        ArrayLen     += r;                   //update ArrayLen so that max remaining characters next time decreases
        printf("%d-",*(pArray+i));         
    }
    *(pArray+LAST_CAT_I) = 1+(ArraySum-ArrayLen);    //last category count should be remaining count**
    printf("%d",*(pArray+LAST_CAT_I));              //printing the count of last
    

    return 0;   
}

/*****************************************************************************/
/********END*OF*CODE**********************************************************/
/*****************************************************************************/
/*     Change Description                                                    */
/*Number:Date:User:Comments***************************************************/
/* 1:22/5/23:F21Z:Initial Version                                            */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/********END*OF*FILE**********************************************************/
