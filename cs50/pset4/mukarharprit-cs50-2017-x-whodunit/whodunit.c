  
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int a, char* argument[])
{
    
    if (a != 3)
    {
        printf("Usage: ./copy inf outf\n");
        return 1;
    }

    
    char* inf = argument[1];

    char* outf = argument[2];

    
    FILE* in_pointer = fopen(inf, "r");

    if (in_pointer == NULL)
    {
        printf("Could not open file %s.\n", inf);
        return 2;
    }

  
    FILE* out_pointer = fopen(outf, "w");

    if (out_pointer == NULL)
    {
        fclose(in_pointer);
        fprintf(stderr, "Could not create file %s.\n", outf);
        return 3;
    }

    
    dTMAPFILEHEADER a;

    fread(&a, sizeof(dTMAPFILEHEADER), 1, in_pointer);

    
    dTMAPINFOHEADER d;

    fread(&d, sizeof(dTMAPINFOHEADER), 1, in_pointer);

    
    if (a.aType != 0x4d42 || a.aOffdts != 54 || d.dSize != 40 || 
        d.ddtCount != 24 || d.dCompression != 0)
    {
        fclose(out_pointer);

        fclose(in_pointer);

        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

   
    fwrite(&a, sizeof(dTMAPFILEHEADER), 1, out_pointer);

   
    fwrite(&d, sizeof(dTMAPINFOHEADER), 1, out_pointer);

    
    int padd =  (4 - (d.dWidth * sizeof(RGBtrip)) % 4) % 4;

    
    for (int i = 0, dHeight = abs(d.dHeight); i < dHeight; i++)
    {
        
        for (int j = 0; j < d.dWidth; j++)
        {
            
            RGBtriple trip;

           
            fread(&trip, sizeof(RGBtriple), 1, in_pointer);

            trip.rgbtBlue-=1;

            trip.rgbtGreen-=1;

            fwrite(&trip, sizeof(RGBtriple), 1, out_pointer);
        }

        
        fseek(in_pointer, padd, SEEK_CUR);

        
        for (int k = 0; k < padd; k++)
        {
            fputc(0x00, out_pointer);
        }
    }

    
    fclose(in_pointer);

    
    fclose(out_pointer);

    
    return 0;
}
