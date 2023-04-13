#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void part1(FILE *input, char *buf)
{
    int counter = 0;
    int totalValue = 0;
    // Hardcoded length of input file
    while (counter < 300)
    {
        if (feof(input))
        {
            break;
        }

        counter++;
        printf("Line Number : %d, Common Char: ", counter);
        fgets(buf, 100, input);
        // Remove the newline by using strcspn to get position of newline and set to 0
        buf[strcspn(buf, "\n")] = 0;

        // Split the string in half
        int halfLength = strlen(buf) / 2;
        char *str1 = (char *)malloc(sizeof(char) * (halfLength + 1));
        char *str2 = (char *)malloc(sizeof(char) * (halfLength + 1));
        memcpy(str1, buf, halfLength);
        str1[halfLength] = '\0';
        memcpy(str2, buf + halfLength, halfLength);
        str2[halfLength] = '\0';

        // Create 2 zero arrays
        char *allChars1[52] = {0};
        char *allChars2[52] = {0};

        // For every char, add 1 to the array element of the char
        for (int i = 0; i < halfLength; i++)
        {
            // Take into account the letter values in the challenge
            // are different to the normal ascii values
            if (str1[i] <= 90)
            {
                allChars1[str1[i] - 39]++;
            }
            else
            {
                allChars1[str1[i] - 97]++;
            }

            if (str2[i] <= 90)
            {
                allChars2[str2[i] - 39]++;
            }
            else
            {
                allChars2[str2[i] - 97]++;
            }
        }

        // Check each string array to see which char exists in both arrays
        for (int j = 0; j < 52; j++)
        {
            if (allChars1[j] != 0 && allChars2[j] != 0)
            {
                if (j < 26)
                {
                    totalValue += (j + 1);
                    printf("%c, Value: %d", j + 97, j + 1);
                }
                else
                {
                    totalValue += (j + 1);
                    printf("%c, Value: %d", j + 39, j + 1);
                }
            }
        }
        printf("\n");

        free(str1);
        free(str2);
    }
    printf("Total Value: %d\n", totalValue);
    return;
}

void part2(FILE *input)
{
    int counter = 0;
    int totalValue = 0;
    while (counter < 100) // 300 lines / group of 3
    {
        if (feof(input))
        {
            break;
        }
        printf("Counter: %d ", counter + 1);

        int allChars1[52];
        int allChars2[52];
        int allChars3[52];
        for (int group = 0; group < 3; group++)
        {
            char *buf2 = (char *)malloc(sizeof(char) * 100);
            fgets(buf2, 100, input);
            buf2[strcspn(buf2, "\n")] = 0;
            int strLen = strlen(buf2);

            // group is value for which string is currently being processed
            switch (group)
            {
            case 0:
                memset(allChars1, 0, sizeof(allChars1));
                for (int i = 0; i < strLen; i++)
                {
                    // Take into account the letter values in the challenge
                    // are different to the normal ascii values
                    if (buf2[i] <= 90)
                    {
                        allChars1[buf2[i] - 39]++;
                    }
                    else
                    {
                        allChars1[buf2[i] - 97]++;
                    }
                }
            case 1:
                memset(allChars2, 0, sizeof(allChars2));
                for (int i = 0; i < strLen; i++)
                {
                    // Take into account the letter values in the challenge
                    // are different to the normal ascii values
                    if (buf2[i] <= 90)
                    {
                        allChars2[buf2[i] - 39]++;
                    }
                    else
                    {
                        allChars2[buf2[i] - 97]++;
                    }
                }
            case 2:
                memset(allChars3, 0, sizeof(allChars3));
                for (int i = 0; i < strLen; i++)
                {
                    // Take into account the letter values in the challenge
                    // are different to the normal ascii values
                    if (buf2[i] <= 90)
                    {
                        allChars3[buf2[i] - 39]++;
                    }
                    else
                    {
                        allChars3[buf2[i] - 97]++;
                    }
                }
            }
            free(buf2);
        }
        // Check which char exists in all 3 arrays
        for (int j = 0; j < 52; j++)
        {
            if (allChars1[j] != 0 && allChars2[j] != 0 && allChars3[j] != 0)
            {
                if (j < 26)
                {
                    totalValue += (j + 1);
                    printf("Common Char: %c\n", j + 97);
                }
                else
                {
                    totalValue += (j + 1);
                    printf("Common Char: %c\n", j + 39);
                }
            }
        }
        counter++;
    }
    printf("Total Value: %d\n", totalValue);
}

int main()
{
    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        printf("File could not be opened.");
        exit(0);
    }
    char *buf = (char *)malloc(sizeof(char) * 100);

    // part1(input);
    part2(input);

    free(buf);
    fclose(input);
}