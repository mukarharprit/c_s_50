#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("height:");
    int h = GetInt();
    if (h < 0 || h > 23)
    {
        main();
    }
    else
    {
        int k = 2;
        int ind = h;
        for(int i = h; i > 0; i--)
        {
            for(int j = 1;j < ind; j++)
            {
                printf(" ");
            }
            ind--;
            for(int j = 0; j < k; j++)
            {
                printf("#");
            }
            k++;
            printf("\n");
        }
    }
}
