/***************************************************************
 Code writer : EOF
 Code date   : 2013.05.16
 e-mail      : jasonleaster@gmail.com

 Code description :
     Here is a demo for how to print out the pascal triangle.

*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

void buildup(int S, int *n);
void putout(int S, int *n);

int main()
{
    int row = 0;
    int k = 0, m = 0, x = 0, S = 0;

    printf("Please enter the row number");
    while(!scanf("%d",&S))
    {
         while(getchar() != '\n');
         printf("please enter again!\n");
    }

    int *n = (int *)malloc((S + 1)*(S/2)*sizeof(int));

    if(!n)
    {
        printf("malloc failed!\n");
        return -1;
    }

    buildup(S, n);
    putout(S, n);
    return 0;
}

void buildup(int S, int *n)
{
    int row , k , m , x , y , a , b;
    row = k = m = x = y = a = b =0;
    
    //initialization
    for(m = 0; m < (S+1)*(S/2); m++)
    {
        n[m] = 0;
    }

    for(row = 1; row <= S; row++)
    {
        m = ((row*(row-1))/2);
        n[m] = 1;
    }

    for(row = 1;row <= S; row++)
    {
        m = ((row*(row+1))/2) -1;
        n[m] = 1;
    }

    //key method
    for(k = 2; k <= S-1; k++)
    {
        for(row = (3 + k -2); row <= S; row++)
        {
            m = ((row*(row-1))/2) - 1 + k;
            x = m - row;
            y = m - row + 1;
            a = ((row*(row+1))/2) - row;
            b = ((row*(row+1))/2) - 1;

            if( m != a && m != b)
            {
                n[m] = n[x] + n[y];
            }
            else
            {
                n[m] = 1;
            }
        }
    }

}

void putout(int S, int *n)
{
    int row , blank , rank , num;
    row = blank = rank = num = 0;

    for(row = 1; row <= S; row++)
    {
        if(row == 1)
        {
            for(blank = 1; blank <= 4*(S-row); blank++)
            {
                printf(" ");
            }
        }
        else
        {
            for(blank = 1; blank <= (S-row); blank++)
            {
                printf("    ");
            }
        }

        for(rank = 1; rank <= row; rank++)
        {
            printf("%d     ", n[num]);
            num++;
            if(rank == row)
            {
                printf("\n");
            }
            printf(" ");
        }
    }
}
