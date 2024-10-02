#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int resistor_types[] = {100, 300, 500, 600};
int RESISTOR_COUNT = 10;

struct binary_masks
{
    char* masks;
    int count;
    int size;
};

struct binary_masks* generate_binary_masks(int n)
{
    int mask_count = pow(2, n);
    char* masks = (char*) malloc(n * mask_count);
    char* mask_pointer = masks;
    
    for (int mask = 0; mask < mask_count; mask++)
    {
        for (int i = 0; i < n; i++)
        {
            *mask_pointer = (mask >> (n-i-1)) & 0x1;
            mask_pointer++;
        }
    }

    struct binary_masks masks_struct;
    masks_struct.count = mask_count;
    masks_struct.size = n;
    masks_struct.masks = masks;
    return &masks_struct;
}   

struct resistor_types 
{
    int resistor_count;
    double* resistors;
};

struct resister_configs
{
    int configuration_count;
    int resistor_count;
    struct resistor_types* resistor_types;
    double* configurations;
};

struct resister_configs* compute_resister_configs(struct resistor_types *resistors, int count)
{
    int config_count = (int) pow(resistors->resistor_count, count);
    int resistor_count = resistors->resistor_count;

    struct resister_configs configs;
    configs.resistor_count = count;
    configs.configuration_count = config_count;
    configs.resistor_types = resistors;

    double *configurations = (double*) malloc(sizeof(double) * resistors->resistor_count*count);
    double *config_head = configurations;

    configs.configurations = configurations;

    for (int i = 0; i < config_count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            *config_head = resistors->resistors[(int) (i / pow(resistor_count, j))%resistor_count];
            config_head++;
        }
    }

    return configurations;
}

int main()
{
    

    return 0;
}