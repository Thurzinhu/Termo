#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/game.h"
#include "../include/guess.h"
#include "../include/print.h"
#include "../include/read.h"

char *getGuess()
{
    int valid = 1;
    char *guess = malloc(sizeof(char) * MAX_LENGTH);
    
    do
    {
        printf(BOLD_WHITE"Digite seu palpite: "RESET);
        scanf(" %s", guess);

        valid = (validateGuess(guess));

        if (!valid)
        {
            printf(RED"Palpite invalido. Tente novamente"RESET"\n");
        }
    } 
    while (!valid);
    
    // lowering all letters
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        guess[i] = tolower(guess[i]);
    }

    return guess;
}

int validateGuess(char *guess)
{
    int length = strlen(guess);

    if (length != MAX_LENGTH - 1)
    {
        return 0;
    }

    // ensuring all chars are be letters
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(guess[i]))
        {
            return 0;
        }
    }

    return 1;
}

void freeGuesses(guess guesses[], int total_guesses)
{
    // freeing all memory allocated
    for (int i = 0; i < total_guesses; i++)
    {
        free(guesses[i].word);
    }
}
