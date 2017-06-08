

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t BYTE;

#define bSIZE 512

int main (void)
{
	FILE* fp = fopen("card.raw", "r");

    if (fp == NULL)
    {
        fprintf(stderr,"Usage: ./recover image\n");
        return 1;
    }
   
    FILE *outf;
    outf = NULL;
    
    int jpg = 0;

    while (1)
    {
          BYTE b[bSIZE] = {};
        
        for (int i = 0; i < bSIZE; i++)
        {
            if (feof(fp))
            {
                fclose(fp);
                
                if (outf != NULL)
                    fclose(outf);
                    
                return 0;
            }
            
           
            fread(&b[i], sizeof (BYTE), 1, fp);
        }
        
          
        if ((b[0] == 0xff) && (b[1] == 0xd8) &&
	 (b[2] == 0xff) && (b[3] == 0xe0 || b[3] == 0xe1))
        {
           
            if (outf != NULL)
            {
                fclose(outf);
            }
            
            char filename[4];

            sprintf(filename, "%03d.jpg", jpg);

            jpg++; 
        
            if ((outf = fopen(filename, "w")) == NULL)
            {
                printf("Could not write image.\n");
                return 1;
            }
 
            
            fwrite(&b[0], bSIZE * sizeof (BYTE), 1, outf);
        }
        
        
        else if (outf != NULL) 
        {
            fwrite(&b[0], bSIZE * sizeof (BYTE), 1, outf);
        }
    }
 
    
    fclose(fp);
    return 0;
}

    
