#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// defining colors
#define GREEN   "\e[42m"
#define RED     "\e[41m"
#define WHITE   "\e[47m"
#define YELLOW  "\e[43m"
#define RESET   "\x1b[0m"
#define ALPHABET 26
#define LIST_SIZE 80

// keyboard colors based on guess
int KEY_COLORS[ALPHABET];
char KEYBOARD[] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};

char *get_guess(int lenght);
int corresponding_letter(char guess);
void print_guess(char *guess, char *answer);
void print_keyboard(void);
void print_all_guesses(char *guesses[], char* answer, int lenght);
void free_guesses(char *guesses[], int lenght);

int main(int argc, char *argv[])
{
    // ensuring proper usage
    if (argc != 2)
    {
        printf("Uso: ./termo 5.txt");
        return 1;
    }

    // opening words file
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Houve um erro ao abrir o arquivo %s\n", argv[1]);
        return 2;
    }

    // getting size of word
    int lenght = atoi(argv[1]) + 1;

    // getting random word
    char random[LIST_SIZE][lenght];

    for (int i = 0; i < LIST_SIZE; i++)
    {
        fscanf(inptr, "%s", random[i]);
    }

    srand(time(NULL));
    char *answer = random[rand() % LIST_SIZE];

    // iniatializing keyboard colors
    for (int i = 0; i < ALPHABET; i++)
    {
        KEY_COLORS[i] = 0;
    }

    // intro of the game
    printf(GREEN"Seja bem-vindo ao TERMO!"RESET);
    printf("\n"GREEN"Adivinhe a palavra de 5 letras para ganhar."RESET"\n");

    // array string of guesses
    char *guesses[lenght];
    for (int i = 0; i < lenght; i++)
    {
        guesses[i] = NULL;
    }

    for (int i = 0; i < lenght; i++)
    {
        // getting user guesses
        guesses[i] = get_guess(lenght);
        print_all_guesses(guesses, answer, lenght);

        if (strcmp(guesses[i], answer) == 0)
        {
            printf("\n"GREEN"Parabens, voce acertou!"RESET"\n");
            free_guesses(guesses, lenght);
            fclose(inptr);
            return 0;
        }
        print_keyboard();
    }

    // freeing guess ptrs
    free_guesses(guesses, lenght);

    printf("\n"GREEN"A resposta era: %s"RESET"\n", answer);
    printf(YELLOW"Nao foi dessa vez :("RESET"\n");

    // closing file
    fclose(inptr);
    return 0;
}

// generatin pseudo random word

char *get_guess(int lenght)
{
    // allocating memory for guess string
    char *guess = malloc(lenght);

    // ensuring proper usage
    do
    {
        printf("Digite seu palpite: ");
        scanf("%s", guess);
        int last = strlen(guess);
        guess[last] = '\0';
    }
    while (strlen(guess) != lenght - 1);

    // lowering all letters
    for (int i = 0; i < lenght - 1; i++)
    {
        guess[i] = tolower(guess[i]);
    }

    // returning guess ptr
    return guess;
}

void print_guess(char *guess, char *answer)
{
    int lenght = strlen(answer);

    // setting colors to each letter of guess
    for (int i = 0; i < lenght; i++)
    {
        int color = 0, key_status = corresponding_letter(guess[i]);
        
        for (int j = 0; j < lenght; j++)
        {
            // answer contains letter, right position
            if (answer[i] == guess[i])
            {
                printf(GREEN"%c "RESET, guess[i]);
                color = 1;

                if (KEY_COLORS[key_status] == 0 || KEY_COLORS[key_status] == 2)
                {
                    KEY_COLORS[key_status] = 1;
                }
                break;
            }

            else if (answer[j] == guess[i])
            {
                // answer contains letter, wrong positon
                printf(YELLOW"%c "RESET, guess[i]);
                color = 1;

                if (KEY_COLORS[key_status] == 0)
                {
                    KEY_COLORS[key_status] = 2;
                }
                break;
            }
        }
        // answer does not contain this letter
        if (!color)
        {
            printf(RED"%c "RESET, guess[i]);
            
            if (KEY_COLORS[key_status] == 0)
            {
                KEY_COLORS[key_status] = 3;
            }
        }
    }
    printf("\n");
}

// printing keyboard status
void print_keyboard(void)
{
    for (int i = 0; i < ALPHABET; i++)
    {
        int color = KEY_COLORS[i];

        if (i % 10 == 0)
        {
            printf("\n");
        }

        switch (color)
        {
            case 1:
                printf(GREEN"%c "RESET, KEYBOARD[i]);
                break;

            case 2:
                printf(YELLOW"%c "RESET, KEYBOARD[i]);
                break;

            case 3:
                printf(RED"%c "RESET, KEYBOARD[i]);
                break;

            default:
                printf(WHITE"%c "RESET, KEYBOARD[i]);
                break;
        }
    }
    printf("\n");
}

// returns the position of the letter in qwerty keyboard
int corresponding_letter(char guess)
{
    for (int k = 0; k < ALPHABET; k++)
    {
        if (guess == KEYBOARD[k])
        {
            return k;
        }
    }
    return 0;
}

void print_all_guesses(char *guesses[], char *answer, int lenght)
{
  for (int i = 0; i < lenght; i++)
    {
        if (guesses[i] == NULL)
        {
            continue;
        }
        else
        {
            printf("Palpite %i: ", i + 1);
            print_guess(guesses[i], answer);
        }
    }
}

void free_guesses(char *guesses[], int lenght)
{
    for (int i = 0; i < lenght; i++)
    {
        free(guesses[i]);
    }
}
