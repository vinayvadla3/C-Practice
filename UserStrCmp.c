/*
  Program to compare two strings
  
  Author:- VinayVadla
  Email:- vadlavinay3@gmail.com
*/

#include<stdio.h>   
#include<string.h> 
#include<stdlib.h> 

int my_strcmpr(char *str_A, char *str_B) 
{ 
    if(strlen(str_A) != strlen(str_B)) 
        return 0; 
    else 
    { 
        for(; *str_A; str_A++,str_B++) 
        { 
            if(*str_A != *str_B) 
                return 0; 
        } 
        return 1; 
    } 
} 

int main() 
{ 
    char str_A[] = "aabbcc"; 
    char str_B[] = "vinaya"; 

    my_strcmpr(str_A, str_B)?puts("SAME"):puts("DIFFERENT"); 
} 
