/*
  Program to Store given Array size in fst index
  
  Author: VinayVadla
  Email:- vadlavinay3@gmail.com
*/

#include <stdio.h>

#define NO_OF_BYTES     1

int main()
{
    int a[10] = {1,2,3,4};
    int i=0, len = sizeof(a)/sizeof(a[0]), my_num=0;
    int *p=a;
    while( *(++p) );
    my_num = p-a;
    printf("%d\n",my_num);

    for(i=my_num+1;i>NO_OF_BYTES-1;i--)
    {
        a[i] = a[i-NO_OF_BYTES];
    }
    a[0] = my_num;
    if(NO_OF_BYTES == 2){
        a[1] = my_num+1;
    }
    for(i=0;i<len;i++)
    printf("%d\t",a[i]);
}
