#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL 0
#define WAY  1


struct Graph
{
    int row;
    int col;
    int map[0];
};

struct Graph *init_Graph(int row, int col);
void release_Graph(struct Graph *p_Graph);
void show_Graph(struct Graph *p_Graph);

struct Graph *init_Graph(int row, int col)
{
    if (row <= 0 && col <= 0)
    {
        printf("Line: %d . Illegal size of graph!\n", __LINE__);
        return NULL;
    }

    struct Graph *p_Graph = (struct Graph *)malloc(sizeof(struct Graph) + sizeof(int)*row*col);

    if(!p_Graph)
    {
        printf("Line: %d . malloc failed\n", __LINE__);
        return NULL;
    }

    p_Graph->row = row;
    p_Graph->col = col;

    srand(time(NULL));

    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            p_Graph->map[i*row + j] =  rand() % 2;// 0 or 1
        }
    }

    p_Graph->map[0] = WAY;

    return p_Graph;
}

void release_Graph(struct Graph *p_Graph)
{
    free(p_Graph);
}

void show_Graph(struct Graph *p_Graph)
{
    if(!p_Graph)
    {
        printf("Line: %d . Empty Graph!\n", __LINE__);
        return ;
    }
    
    int i = 0;
    int j = 0;
    int row = p_Graph->row;
    int col = p_Graph->col;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%2d", p_Graph->map[i*row + j]);
        }
        printf("\n");
    }
}

/*
void walk_out(struct Graph *p_Graph)
{
    if(!p_Graph)
    {
        printf("Line: %d . Empty Graph!\n", __LINE__);
        return NULL;
    }
    
    int i = 0;
    int j = 0;
    int row = p_Graph->row;
    int col = p_Graph->col;
    while(i < row && j < col)
    {
        if(p_Graph->map[i][j] == WALL)
        {
            
        }
        else
        {

        }
    }
}*/

int main()
{
    struct Graph *p_Graph = init_Graph(12,12);

    show_Graph(p_Graph);

    release_Graph(p_Graph);

    return 0;
}
