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

int main()
{
    int count[CAT_COUNT]={0};       //count array holds count of each character category
    int sum=CAT_COUNT;              //initializing sum since every character should occur atleast once
    srand(time(NULL));              //seed random
    
    for(int i=0 ;i<LAST_CAT_I ;i++){    //to assign count of each character category except last category
        int range= PASSWORD_LEN-sum+1;  //define range as max remaining charecters so that no. of charecters shouldnt exceed given pwd length
        int r= rand() % range;          //GET a random number in range
        count[i] = 1+r;                 //each character category to appear once or more than once
        sum     += r;                   //update sum so that max remaining characters next time decreases
        printf("%d-",count[i]);         
    }
    count[LAST_CAT_I] = 1+(PASSWORD_LEN-sum);    //last category count should be remaining count**
    printf("%d",count[LAST_CAT_I]);              //printing the count of last
    return 0;                                    
}




/*****************************************************************************/
/********END*OF*CODE**********************************************************/
/*****************************************************************************/
/*     Change Description                                                    */
/*Number:Date:User:Comments***************************************************/
/* 1:22/5/23:f21z:Initial Version                                            */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/********END*OF*FILE**********************************************************/
