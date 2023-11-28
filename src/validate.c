#include <stdio.h>
#include "../include/validate.h"

int validateInput(int argc, char *argv[], FILE **file)
{
    if (argc != 2)
    {
        return 0;
    }
    
    *file = fopen(argv[1], "r");
    if (*file == NULL)
    {
        return 0;
    }

    return 1;
}