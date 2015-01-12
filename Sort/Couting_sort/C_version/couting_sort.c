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

int counting_sort(int *num,int array_size)
{
    if(!num)
    {
        return -1;
    }

    int *p_tmp = (int*)malloc(sizeof(int)*array_size);

    if(!p_tmp)
    {
         printf("malloc failed %d\n",__LINE__);
         return 0;
    }

    int i = 0;
    int max_value = 0;
    for(i = 0; i < array_size; i++)
    {
        max_value = max_value > num[i] ?
                    max_value : num[i];

        p_tmp[i] = num[i];
    }

    int counter_size = max_value + 1;

    int *p_counter = (int*)malloc(sizeof(int)*counter_size);

    if(!p_counter)
    {
         printf("malloc failed %d\n",__LINE__);
         return 0;
    }

    //initialization
    for(i = 0; i < counter_size; i++)
    {
        p_counter[i] = 0;
    }

    //counting
    for(i = 0; i < array_size; i++)
    {
        p_counter[num[i]] += 1;
    }

    //caculating
    for(i = 1; i < counter_size; i++)
    {
        p_counter[i] += p_counter[i-1];
    }

    //output from bigger element to smaller element
    for(i = array_size -1;i >= 0; i--)
    {
        num[p_counter[p_tmp[i]] - 1] = p_tmp[i];

        p_counter[p_tmp[i]] -= 1;
    }

    free(p_counter);
    free(p_tmp);

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
