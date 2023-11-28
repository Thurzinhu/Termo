#include <stdio.h>
#include "../include/game.h"
#include "../include/print.h"

void printGuesses(guess guesses[], int total_guesses)
{
    for (int i = 0; i < total_guesses; i++)
    {
        printf(BOLD_WHITE"Palpite %i: "RESET, i + 1);

        for (int j = 0; j < MAX_LENGTH; j++)
        {
            switch (guesses[i].letter_status[j])
            {
                case 1:
                    printf(GREEN"%c "RESET, guesses[i].word[j]);
                    break;
                case 2:
                    printf(YELLOW"%c "RESET, guesses[i].word[j]);
                    break;
                case 3:
                    printf(RED"%c "RESET, guesses[i].word[j]);
                    break;
            }
        }

        printf("\n");
    }
}

void printKeyboard(keyboard qwerty[])
{
    for (int i = 0; i < ALPHABET; i++)
    {
        if (i % 10 == 0)
        {
            printf("\n");
        }
        
        switch (qwerty[i].status)
        {
            case 1:
                printf(GREEN"%c "RESET, qwerty[i].letter);
                break;
            case 2:
                printf(YELLOW"%c "RESET, qwerty[i].letter);
                break;
            case 3:
                printf(RED"%c "RESET, qwerty[i].letter);
                break;
            default:
                printf(WHITE"%c "RESET, qwerty[i].letter);
                break;
        }
    }

    printf("\n\n");
}

// intro of the game
void printIntroduction()
{
    printf(GREEN"Seja bem-vindo ao TERMO!"RESET);
    printf("\n"GREEN"Adivinhe a palavra de 5 letras para ganhar."RESET"\n");
}

// winner message
void printTrophy()
{
    printf("\n""       ___________      \n");
    printf("      '._==_==_=_.'     \n");
    printf("      .-\\:      /-.    \n");
    printf("     | (|:.     |) |    \n");
    printf("      '-|:.     |-'     \n");
    printf("        \\::.    /      \n");
    printf("         '::. .'        \n");
    printf("           ) (          \n");
    printf("         _.' '._        \n");
    printf("        '-------'       \n\n");
    printf("\n"GREEN"Parabens, voce acertou!"RESET"\n");
}

// loser message
void printAnswer(char *answer)
{
    printf("\n"GREEN"A resposta era: %s"RESET"\n", answer);
    printf(YELLOW"Nao foi dessa vez :("RESET"\n");
}