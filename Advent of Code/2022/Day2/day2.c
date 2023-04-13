#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rockpaperscissors(char opponent, char player)
{
    // 1 Rock = A or X
    // 2 Paper = B or Y
    // 3 Scissors = C or Z
    // Switch case to determine score based player and opponent
    // rock paper scissors choice
    switch (opponent)
    {
    case 'A':
        switch (player)
        {
        case 'X':
            return 3 + 1;
            break;
        case 'Y':
            return 6 + 2;
            break;
        case 'Z':
            return 0 + 3;
            break;
        }
        break;
    case 'B':
        switch (player)
        {
        case 'X':
            return 0 + 1;
        case 'Y':
            return 3 + 2;
        case 'Z':
            return 6 + 3;
        }
        break;
    case 'C':
        switch (player)
        {
        case 'X':
            return 6 + 1;
        case 'Y':
            return 0 + 2;
        case 'Z':
            return 3 + 3;
        }
        break;
    }
}

int rockpaperscissors2(char opponent, char player)
{
    // 1 Rock = A
    // 2 Paper = B
    // 3 Scissors = C
    // X = Lose
    // Y = Draw
    // Z = Win
    // Switch case to determine score based player and opponent
    // rock paper scissors choice
    switch (opponent)
    {
    case 'A':
        switch (player)
        {
        case 'X':
            return 0 + 3;
        case 'Y':
            return 3 + 1;
        case 'Z':
            return 6 + 2;
        }
        break;
    case 'B':
        switch (player)
        {
        case 'X':
            return 0 + 1;
        case 'Y':
            return 3 + 2;
        case 'Z':
            return 6 + 3;
        }
        break;
    case 'C':
        switch (player)
        {
        case 'X':
            return 0 + 2;
        case 'Y':
            return 3 + 3;
        case 'Z':
            return 6 + 1;
        }
        break;
    }
}

int main()
{
    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        printf("File could not be opened.");
        exit(0);
    }
    int totalScore = 0;
    char line[5];
    while (1)
    {
        fgets(line, 10, input);
        if (feof(input))
        {
            break;
        }
        printf("Opponent: %c, Player : %c\n", line[0], line[2]);
        // totalScore += rockpaperscissors(line[0], line[2]);
        totalScore += rockpaperscissors2(line[0], line[2]);
    }
    printf("Total Score: %d", totalScore);
    fclose(input);
}