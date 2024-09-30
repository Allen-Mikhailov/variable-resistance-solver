#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int resistor_types[] = {100, 300, 500, 600};
int RESISTOR_COUNT = 10;

char* generate_binary_masks(int n)
{
    int mask_count = pow(2, n);
    char* masks = (char*) malloc(n * mask_count);
    
    for (int mask = 0; mask < mask_count; mask++)
    {
        for (int i = 0; i < mask_count; i++)
        {
            
        }
    }
}   

int main()
{
    

    return 0;
}