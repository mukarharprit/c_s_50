/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if num is in array of n key, else false.
 */
bool search(int num, int key[], int n)
{
    // TODO: implement a searching algorithm
    for( int i=0 ; i<n ; i++)
    {
        if( key[i]==num)
        return true;
    }
    
    return false;
}

/**
 * Sorts array of n key.
 */
void sort(int key[], int n)
{
    // TODO: implement a sorting algorithm
     int temp;
    for( int i=0 ; i<n-1 ; i++)
    {
        for ( int j=0 ; j<n-i-1 ; j++)
        {
            if( key[j] > key[j+1] )
            {
                temp = key[j+1];
                key[j+1] = key[j];
                key[j] = temp;
            }
        }
    }
    return;
}
