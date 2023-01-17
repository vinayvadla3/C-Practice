/*
  Program to reverse words at same place in given a input string without changing exra characters places
  
/_____________string rev and words rev at same place and without special char___________/
  
  Author:- VinayVadla
  Email:-vadlavinay3@gmail.com
*/
 

#include<stdio.h>   
#include<string.h> 
#include<stdlib.h> 

void my_strrev(char *str, int start, int end) 
{ 
    char temp; 
    while(start<end) 
    { 
        temp = str[start]; 
        str[start] = str[end]; 
        str[end] = temp; 
        start++; 
        end--; 
    } 
} 

int main() 
{ 
    int i=0,j=0; 
    char str[] = "vinay!!!! victory@@@@"; 
    printf("%s\n",str); 
    for(;i<strlen(str);j++) 
    { 
        if(str[j]==' ' || str[j]=='\0' || !isalpha(str[j])) 
        { 
            my_strrev(str,i,j-1); 
            i=j; 
            while(!isalpha(str[i]) && str[j]!='\0') 
            { 
                i++; 
            } 
        } 
    } 
    printf("%s\n",str); 
}
