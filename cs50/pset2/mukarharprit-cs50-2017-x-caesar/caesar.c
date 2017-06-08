


#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int arg, string argv[])
{
    string key = argv[1];
    if (arg != 2)
    {
        printf(" give me a valid key");

        return 1;
    }
    else
    {
       
        int k = atoi(key) % 26;
        
       
        if (k == 0)
        {
            printf("Invalid key.\n");
            return 1;
        }
        printf("plaintext: ");

        string new = GetString();

        printf("ciphertext: ");

        if (new != NULL)
        {
    
           
            for (int i = 0, n = strlen(new); i < n; i++)
            {
                int u = 0;    
                        
                if (isupper(new[i]))
                {
                   
                    u = (((int)new[i] - 65 + k) % 26) + 65;
                    printf("%c", (char) u);
                }

                else if (islower(new[i]))
                {
                    
                    u = (((int)new[i] - 97 + k) % 26) + 97;
                    printf("%c", (char) u);
                }

                else
                {
                    printf("%c", new[i]);
                }
            }
            printf("\n");
            return 0;
        }
    }
}
                
