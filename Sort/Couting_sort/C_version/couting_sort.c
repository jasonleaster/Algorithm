/*********************************************************
 Code writer : EOF
 Code date   : 2014.01.11
 Code file   : counting_sort.c
 e-mail      : jasonleaster@gmail.com

 Code description:
   Here is a implementation for counting sort.

   If you find something wrong with my code, please touch
me by e-mail.

*********************************************************/
#include <stdio.h>
#include <stdlib.h>

int counting_sort(int *num,int size)
{
    if(!num)
    {
        return -1;
    }

    int *p_buffer = (int*)malloc(sizeof(int)*size);

    //initialization
    int i = 0;
    for(i = 0; i < size; i++)
    {
        p_buffer[i] = 0;
    }

    //counting
    for(i = 0; i < size; i++)
    {
        p_buffer[num[i]] += 1;
    }

    //output from bigger element to smaller element
    int index = 0;
    for(index = i = size -1;i >= 0; i--)
    {
        num[(size -1) - index] = i;
    }

    free(p_buffer);
    return 0;
}

int main()
{
    int array[] = {1,3,4,3,2,7,4,0};
    int size_array = sizeof(array)/sizeof(array[0]);

    int i = 0;
    printf("Before sorting:array[] = \n");
    for(i = 0; i < size_array; i++)
    {
        printf("\t%d",array[i]);
    }

    printf("\n");
    counting_sort(array,size_array);

    printf("After sorting:array[] = \n");
    for(i = 0; i < size_array; i++)
    {
        printf("\t%d",array[i]);
    }
    printf("\n");

    return 0;
}
