#include <stdio.h>
#include <stdlib.h>
#include "../include/game.h"
#include "../include/guess.h"
#include "../include/print.h"

// global variable to hold player score
int SCORE;

// defining qwerty keyboard
keyboard qwerty[] = {
    {'q', 0}, {'w', 0}, {'e', 0}, {'r', 0}, {'t', 0}, {'y', 0}, {'u', 0}, {'i', 0}, {'o', 0}, {'p', 0},
    {'a', 0}, {'s', 0}, {'d', 0}, {'f', 0}, {'g', 0}, {'h', 0}, {'j', 0}, {'k', 0}, {'l', 0},
    {'z', 0}, {'x', 0}, {'c', 0}, {'v', 0}, {'b', 0}, {'n', 0}, {'m', 0}
};

void play(char *answer)
{
    // printing intro of the game
    printIntroduction();

    int num_guesses = 0, win = 0;
    guess guesses[MAX_GUESSES];
    for (int i = 0; i < MAX_GUESSES; i++)
    {
        // getting user guess
        guesses[i].word = getGuess();
        num_guesses++;
        
        // setting score to 0
        SCORE = 0;

        // updating score based on guess
        updateStatus(answer, &guesses[i]);

        // printing all words guessed
        printGuesses(guesses, i + 1);

        if (SCORE == MAX_LENGTH - 1)
        {
            printTrophy();
            win = 1;
            break;
        }

        printKeyboard(qwerty);
    }

    if (!win)
    {
        printAnswer(answer);
    }

    // freeing memory allocated
    freeGuesses(guesses, num_guesses);
    free(answer);
}

// calculating user score
void updateStatus(char *answer, guess *cur_guess)
{
    for (int i = 0; i < MAX_LENGTH - 1; i++)
    {
        int find = 0;
        int letter_idx = correspondingLetter(cur_guess->word[i]);

        // letter in word and in right position
        if (answer[i] == cur_guess->word[i])
        {
            cur_guess->letter_status[i] = 1;
            find = 1;
            SCORE++;

            // updating letter status in keyboard to rigth position
            qwerty[letter_idx].status = 1;
        }
        else
        {
            for (int j = 0; j < MAX_LENGTH - 1; j++)
            {
                // letter in word but wrong position
                if (answer[j] == cur_guess->word[i])
                {
                    cur_guess->letter_status[i] = 2;
                    find = 1;

                    // updating letter status in keyboard to wrong position
                    if (qwerty[letter_idx].status != 1)
                    {
                        qwerty[letter_idx].status = 2;
                    }

                    break;
                }
            }
        }

        // letter not in word
        if (!find)
        {
            cur_guess->letter_status[i] = 3;
            if (qwerty[letter_idx].status == 0)
            {
                qwerty[letter_idx].status = 3;
            }
        }
    }
}

// returns index of letter in qwerty keyboard
int correspondingLetter(char letter)
{
    for (int i = 0; i < ALPHABET; i++)
    {
        if (qwerty[i].letter == letter)
        {
            return i;
        }
    }

    return -1;
}
