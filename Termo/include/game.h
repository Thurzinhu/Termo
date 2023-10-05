#ifndef GAME_H
#define GAME_H

#define MAX_GUESSES 6
#define MAX_LENGTH 6
#define ALPHABET 26

typedef struct
{
    char *word;
    int letter_status[MAX_LENGTH];
}
guess;

typedef struct 
{
    char letter;
    int status;
}
keyboard;

int correspondingLetter(char letter);
void play(char *answer);
void updateStatus(char *answer, guess *cur_guess);

#endif