#include <stdio.h>

int main()
{

    char str[] = "Please reverse this string!";

    printf("%s\n", str);

    str_rev(str);

    printf("%s\n", str);

    return 0;
}

int str_rev(char *string)
{
    if(!string)
    {
        return 0;
    }

    int ins_pos = 0;
    int ch = 0;
    int swap_time = 0;

    int i = 0;
    int j = 0;

    int counter = 0;
    int word    = 0;

    for(i = 0, word = 1; string[i] != '\0'; i++)
    {
        if(string[i] == ' ')
        {
            word++;
        }
    }
    counter = i;

    for(j = 0, swap_time = 0, ins_pos = 0, ch = 0;
        j < word - 1;
        j++)
    {
        for(swap_time = 0; string[counter-1] != ' ';)
        {
            ch = string[counter-1];

            for(i = counter - 1; i > ins_pos; i--)
            {
                string[i] = string[i-1];
            }
            string[ins_pos] = ch;
            swap_time++;
        }

        ins_pos += swap_time;
        ch = string[counter-1];

        for(i = counter - 1; i > ins_pos; i--)
        {
        string[i] = string[i-1];
        }
        string[ins_pos] = ch;
        ins_pos++;
    }

    return 0;
}
