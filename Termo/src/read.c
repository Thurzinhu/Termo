#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/read.h"

char *readFile(FILE *file)
{
    char words[MAX_WORDS][MAX_LENGTH];
    for (int i = 0; i < MAX_WORDS; i++)
    {
        fscanf(file, "%s", words[i]);
    }

    // closing file
    fclose(file);
    
    // allocing memory to return random word
    char *answer = malloc(sizeof(char) * MAX_LENGTH);

    // generating random word
    strcpy(answer, words[rand() % MAX_WORDS]);
    
    return answer;
}