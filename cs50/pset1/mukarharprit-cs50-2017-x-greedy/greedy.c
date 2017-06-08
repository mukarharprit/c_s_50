#include <stdio.h>
#include <cs50.h>
#include <math.h>

float getChange();

int main(void)
{
    float change = getChange();

    int c = 0;

    float cent = change * 100;

    cent = round(cent);

    while(cent != 0)
    {
        if (cent >= 25)
        {
            cent = cent - 25;
            c++;
        }
        else if (cent >= 10)
        {
            cent = cent - 10;
            c++;
        }
        else if(cent >= 5)
        {
            cent = cent - 5;
            c++;
        }
        else
        {
            cent = cent - 1;
            c++;
        }
    }
    printf("%i\n", c);
}

float getChange()
{
    float change;
    do
    {
        printf("How much change is owed?\n");
        change = GetFloat();
    }while(change < 0);
    return change;
}
