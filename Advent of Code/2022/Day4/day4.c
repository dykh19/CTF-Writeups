#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        printf("File could not be opened.");
        exit(0);
    }
    char *buf = (char *)malloc(sizeof(char) * 20);
    int counter = 0;
    while (feof(input) == 0)
    {

        fgets(buf, 20, input);
        buf[strcspn(buf, "\n")] = 0;

        // Split the strings to low - high for each elf
        int firstLow, firstHigh, secondLow, secondHigh = 0;
        firstLow = atoi(strtok(buf, "-"));
        firstHigh = atoi(strtok(NULL, ","));
        secondLow = atoi(strtok(NULL, "-"));
        secondHigh = atoi(strtok(NULL, "-"));
        printf("Elf 1: %d-%d, Elf 2: %d-%d\n", firstLow, firstHigh, secondLow, secondHigh);

        // Part 1
        // if (firstLow >= secondLow && firstHigh <= secondHigh)
        // {
        //     counter++;
        //     printf("Added\n");
        // }
        // else if (secondLow >= firstLow && secondHigh <= firstHigh)
        // {
        //     counter++;
        //     printf("Added\n");
        // }
        // else
        // {
        //     printf("\n");
        //     continue;
        // }

        // Part 2
        if (firstHigh >= secondLow && secondHigh >= firstLow)
        {
            counter++;
            printf("Added\n");
        }
        else if (firstHigh <= secondLow && secondHigh <= firstLow)
        {
            counter++;
            printf("Added\n");
        }
        else
        {
            printf("\n");
            continue;
        }
    }
    printf("Pairs: %d", counter);
}