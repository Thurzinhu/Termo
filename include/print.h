#ifndef PRINT_H
#define PRINT_H

// defining colors
#define GREEN       "\e[42m"
#define BOLD_WHITE  "\e[1;97m"
#define RED         "\e[41m"
#define WHITE       "\e[47m"
#define YELLOW      "\e[43m"
#define RESET       "\x1b[0m"

void printAnswer(char *answer);
void printTrophy();
void printIntroduction();
void printGuesses(guess guesses[], int total_guesses);
void printKeyboard(keyboard qwerty[]);

#endif