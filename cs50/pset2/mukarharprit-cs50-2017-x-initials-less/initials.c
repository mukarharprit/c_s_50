#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (void)
{
    string s = GetString();

    if( s[0] >=97 )
        printf("%c", s[0]-32);

    else
        printf("%c", s[0]);
        
    int t=0;

    for (int i = 0; i < strlen(s); i++)
    {

        if( t == 1 )
        {

            t=0;

            if( s[i] >=97 )
                printf("%c", s[i]-32);
            else
                printf("%c", s[i]);
        }
        
        if( s[i] == ' ')
            t=1;
            
    }
    printf("\n");
}
