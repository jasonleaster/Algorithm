#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int** num;//定义二级指针
    int count=1,row=0,rank=0,cycle=0;//定义变量 count自增赋值，定义变量row，rank做行列变量,定义变量cycle圈数
    int n,m=0;//定义变量n正方形尺寸的大小，定义变量m做for循环计数变量

    printf("please enter the number of row :");
    //尽量将数字控制在10以内，因为控制台窗口程序当行满时会自动换行，窗口大小有限不能自由拓展

    scanf("%d",&n);
    //-----------------申请开辟一个N*N的内存区域-----------------------------
    num=(int**)malloc(n*sizeof(int*));
    for(m=0;m<n;m++)
    {
    *(num+m)=(int*)malloc(n*sizeof(int));
    }
    //------------------------------------------------------------------------

    if(n%2==0)//当n是偶数时候，为正方形二维数组  "逆时针回旋"  赋值
    {
        for(cycle=0;cycle<(n/2);cycle++)
        {
            for(row=cycle;row<n-cycle;row++,count++)
            {
                num[row][rank]=count;
            }
            count--;//很关键
            row--;//很关键的一步！row++后自增如果减一则会导致数组越界程序无法运行！！

            for(rank=cycle;rank<n-cycle;rank++,count++)
            {
                num[row][rank]=count;
            }
            rank--;
            count--;

            for(;row>=cycle;row--,count++)
            {
                num[row][rank]=count;
            }
            row++;
            count--;

            for(;rank>=cycle+1;rank--,count++)
            {
                num[row][rank]=count;
            }
            rank++;
        }
    }
    else//当n是奇数数时候，为正方形二维数组  "逆时针回旋"  赋值
    {
        for(cycle=0;cycle<(n-1)/2;cycle++)
        {
            for(row=cycle;row<n-cycle;row++,count++)
            {
                num[row][rank]=count;
            }
            row--;
            count--;

            for(rank=cycle;rank<n-cycle;rank++,count++)
            {
                num[row][rank]=count;
            }
            count--;
            rank--;

            for(;row>=cycle;row--,count++)
            {
                num[row][rank]=count;
            }
            count--;
            row++;

            for(;rank>=cycle+1;rank--,count++)
            {
                num[row][rank]=count;
            }
            rank++;

        }

        num[(n-1)/2][(n-1)/2]=count;
    }

    for(row=0;row<n;row++)//打印这个n*n的正方形数阵
    {
        for(rank=0;rank<n;rank++)
        {
            printf("\t%d",num[row][rank]);

            if(rank==(n-1))
                printf("\n\n\n");
        }
    }

    for(m=0;m<n;m++)//释放申请的二级指针内存
    {
        free(num[m]);
    }
    free(num);
    num=NULL;

    return 0;
}

