#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/game.h"
#include "../include/read.h"
#include "../include/validate.h"

int main(int argc, char *argv[])
{
    // checking for valid input
    FILE *infile = NULL;
    if (!validateInput(argc, argv, &infile))
    {
        printf("ERROR\n");
        return 1;
    }

    // setting seed
    srand(time(NULL));

    // reading file words and randomly choosing one to be the answer
    char *answer = readFile(infile);

    // starting game
    play(answer);
}
