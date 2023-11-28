#ifndef GUESS_H
#define GUESS_H

void freeGuesses(guess guesses[], int total_guesses);
char *getGuess();
int validateGuess(char *guess);

#endif