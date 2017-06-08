
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int a, char* argument[])
{
    if (a != 4)
    {
        printf("Usage: ./copy inf outf\n");
        return 1;
    }
    int n = atoi(argument[1]);

    char* inf = argument[2];

    char* outf = argument[3];

    if(n < 1 || n > 100)
    {
        printf("n must be between 1 and 100\n");
        return 1;
    }
    
    FILE* in_pointer = fopen(inf, "r");

    if (in_pointer == NULL)
    {
        printf("Could not open %s.\n", inf);
        return 2;
    }

   
    FILE* out_pointer = fopen(outf, "w");

    if (out_pointer == NULL)
    {
        fclose(in_pointer);

        fprintf(stderr, "Unable to create %s.\n", outf);

        return 3;
    }

    BITMAPFILEHEADER a,an;

    fread(&a, sizeof(BITMAPFILEHEADER), 1, in_pointer);

    an = a;

   
    BITMAPINFOHEADER bi,d;

    fread(&bi, sizeof(BITMAPINFOHEADER), 1, in_pointer);

    d = bi;

   
    if (a.aType != 0x4d42 || a.aOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(out_pointer);

        fclose(in_pointer);
        
        return 4;
    }
    d.biWidth = bi.biWidth * n;

    d.biHeight = bi.biHeight * n;
    
    
    int pad =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    int pad_new = (4 -(d.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    long offset = bi.biWidth * sizeof(RGBTRIPLE);
    
    
    d.biSizeImage = (d.biWidth * sizeof(RGBTRIPLE) + pad_new) * abs(d.biHeight);

    an.aSize = a.aSize - bi.biSizeImage + d.biSizeImage;
    
    
    fwrite(&an, sizeof(BITMAPFILEHEADER), 1, out_pointer);

    
    fwrite(&d, sizeof(BITMAPINFOHEADER), 1, out_pointer);

   
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for(int j = 0; j < n; j++)
        {
            
            for (int k = 0; k < bi.biWidth; k++)
            {
                RGBTRIPLE triple;

                fread(&triple, sizeof(RGBTRIPLE), 1, in_pointer);

               
                for(int l = 0; l < n; l++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, out_pointer);
                }
            }
            for(int l = 0; l < pad_new; l++)
            {
                fputc(0x00,out_pointer);            
            }
            
            if(j < n - 1)
            {
                fseek(in_pointer, -offset, SEEK_CUR);
            }
        }
        
        fseek(in_pointer, pad, SEEK_CUR);
    }
    
    fclose(in_pointer);

    
    fclose(out_pointer);

    
    return 0;
}
