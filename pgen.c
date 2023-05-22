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
#include <string.h>

#define CAT_COUNT   4                
#define LAST_CAT_I  (CAT_COUNT-1)    


#define PASSWORD_LEN    8            

int n_numbers_sum(int *pArray, int ArrayLen, int ArraySum);
int generate(char* pwd_array, int len_pwd_array, char** str_array, int* cat_count_array, int len_cat_count_array);

int main()
{
    srand(time(NULL));              //seed random
    
    int counts[CAT_COUNT]={0};       //count array holds count of each character category
    int *pcounts= &counts[0];


    //printf("\n");
    n_numbers_sum(pcounts, CAT_COUNT, PASSWORD_LEN);
    
    char* cats[CAT_COUNT];
    cats[0] = "abcdefghijklmnopqrstuvwxyz";
    cats[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cats[2] = "0123456789";
    cats[3] = "!@#$%^&*()~<>,.?;:{}[]=+-_|";

    char pwd[PASSWORD_LEN+1];
    pwd[PASSWORD_LEN] = '\0';  //making sure last character is null
 

    generate(pwd, PASSWORD_LEN, cats, pcounts, CAT_COUNT);
    printf("%s\n", pwd);
    //printf("\n");
    
    return 0;                                    
}



int n_numbers_sum(int *pArray, int ArrayLen, int ArraySum)
{
    for(int i=0 ;i<LAST_CAT_I ;i++){    //to assign count of each character category except last category
        int range= ArraySum-ArrayLen+1;  //define range as max remaining charecters so that no. of charecters shouldnt exceed given pwd length
        int r= rand() % range;          //GET a random number in range
        *(pArray+i) = 1+r;                 //each character category to appear once or more than once
        ArrayLen     += r;                   //update ArrayLen so that max remaining characters next time decreases
        //printf("%d-",*(pArray+i));         
    }
    *(pArray+LAST_CAT_I) = 1+(ArraySum-ArrayLen);    //last category count should be remaining count**
    //printf("%d",*(pArray+LAST_CAT_I));              //printing the count of last
    

    return 0;   
}

int generate(char* pwd_array, int len_pwd_array, char** str_array, int* cat_count_array, int len_cat_count_array)
{
    int pwd_i = 0;
    
    for(int i=0; i<len_cat_count_array; i++)
    {
        int cur_count = *(cat_count_array+i);
        char* cur_str_array = *(str_array+i);
        int cur_len = strlen(cur_str_array);
        
        //printf("%d: %s = %d\n", cur_count, cur_str_array, cur_len);
        
        for (int j=0; j<cur_count; j++)
        {
            int ri = rand()%cur_len;
            pwd_array[pwd_i++] = *( cur_str_array+ri );
            //printf("%c = %c\n", pwd_array[pwd_i-1], *( cur_str_array+ri ));
            
        }
    }
    return 0;
}


/*****************************************************************************/
/********END*OF*CODE**********************************************************/
/*****************************************************************************/
/*     Change Description                                                    */
/*Number:Date:User:Comments***************************************************/
/* 1:22/5/23:F21Z:Initial Version                                            */
/* 2:22/5/23:F21Z:moved the code to new function   n_numbers_sum             */
/* 3:22/5/23:F21Z:added code pick random chars based on count                */
/* 4:22/5/23:F21Z:Moved the randcom chars picking to a new function generate */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/********END*OF*FILE**********************************************************/
