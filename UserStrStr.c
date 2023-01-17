/*

Strstr function implementation 

This function is very easy to use in c language. It has two arguments as char strings. First string contents base string in which we want to search sub-string. The Second argument is sub-string that need to be searched in base string. 

If it founds substring in the base string, it returns 1. Otherwise, it returns 0. 

  Author:- VinayVadla
  Email:- vadlavinay3@gmail.com
  
*/

#include <stdio.h> 
#include <string.h> 

int fstrstr(char *str, char *sub) 
{ 
    int str_len = strlen(str); 
    int sub_len = strlen(sub); 
    char i=0,j=0,index=0; 

    for(i=0;i<str_len;i++) 
    { 
        index = i; 
        for(j=0;j<sub_len;j++) 
        { 
            if(str[index] == sub[j]) 
            { 
                if(j==sub_len-1) 
                { 
                    return 1; 
                } 
                index++; 
            } 
            else 
            { 
                break; 
            } 
        } 
    } 
    return 0; 
}

int main() 
{ 
    char str[] = "vinay"; 
    char sub[] = "ht"; 

    fstrstr(str, sub)?puts("found"):puts("not found"); 

    return 0; 

} 
