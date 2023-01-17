/*
  Program to return malloc with next block address
  if malloc return address is 0x555555559ac0 it will round of to 0x555555559b00
  
  Author:- VinayVadla
  Email:- vadlavinay3@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>

int *my_malloc(int size)
{
    int *temp = malloc(size);
    int *ptr = &temp;
    printf("ptr = %x\n",*ptr);
    int tmp = (char)*ptr & 0xFF;
    printf("tmp = %x\n",tmp);
    tmp = 0x100 - tmp;
    printf("tmp = %x\n",tmp);
    *ptr += tmp;
    printf("ptr = %x\n",*ptr);
    return *ptr;
}

int main()
{
    int *arr = my_malloc(3*sizeof(int));
    printf("arr = %x\n",arr);
}
