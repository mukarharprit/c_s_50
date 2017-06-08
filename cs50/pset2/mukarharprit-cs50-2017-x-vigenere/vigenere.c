#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int arg, string argu[])
{
   
    if (arg != 2)
    {
        printf("Error\n");
        return 1;
    }
    else
    {
        string k = argu[1];

        int kLength = strlen(k), j = 0;
       
        for(int i = 0 ; i < kLength ; i++)
        {
            if (isalpha(k[i]))
            {
                continue;
            }
            else
            {
                printf("Error\n");
                return 1;
            }
        }
        printf("plaintext: ");
       
        
        string new = GetString();
        printf("ciphertext: ");
        
        for(int i = 0, n = strlen(new); i < n; i++)
        {
            int krot = j % kLength;

            if (isupper(new[i]) && isalpha(new[i]))
            {
                if (isupper(k[krot]))
                {
                    int cipher = (new[i] - 65 + k[krot] - 65) % 26; 

                    printf("%c", cipher + 65);
                }
                else 
                {
                    int cipher = (new[i] - 65 + k[krot] - 97) % 26; 

                    printf("%c", cipher + 65);
                }
                j++;
            }
            else if (islower(new[i]) && isalpha(new[i]))
            {
                if (isupper(k[krot]))
                {
                    int cipher = (new[i] - 97 + k[krot] - 65) % 26; 

                    printf("%c", cipher + 97);
                }
                else 
                {
                    int cipher = (new[i] - 97 + k[krot] - 97) % 26; 

                    printf("%c", cipher + 97);
                }
                j++;
            }
            else
                printf("%c", new[i]);
        }
    }
    printf("\n");
    return 0;
}
