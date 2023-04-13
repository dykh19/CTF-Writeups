#include <stdio.h>
#include <stdlib.h>

// Checks if array elements match with any other array element
// Return 1 on match
int checkDuplicate(char array[])
{
    for (int i = 0; i < 14; i++)
    {
        for (int j = i + 1; j < 14; j++)
        {
            if (array[i] == array[j])
            {
                return 1;
            }
        }
    }
    return 0;
}

// Add the next char from the input file
// and shift all 4 array elements, dropping the last one
void addValue1(char array[], FILE *input)
{
    array[0] = array[1];
    array[1] = array[2];
    array[2] = array[3];
    array[3] = (char)fgetc(input);
}

// Same as addValue1 but shifts 14 times due to array size
void addValue2(char array[], FILE *input)
{
    for (int i = 1; i < 14; i++)
    {
        array[i - 1] = array[i];
    }
    array[13] = (char)fgetc(input);
}

int main()
{
    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        printf("File could not be opened.");
        exit(0);
    }
    // char *array[4];
    char array[14];

    // Part 1
    // Set initial counter to 4
    // int counter = 4;

    // Part 2
    // Set initial counter to 14
    int counter = 14;

    // Part 1 loops 4 times to add initial 4 elements
    // for (int i = 0; i < 4; i++)

    // Part 2 loops 14 times to add initial 14 elements
    for (int i = 0; i < 14; i++)
    {
        array[i] = (char)fgetc(input);
    }
    // Check initial elements for match if not go to while loop
    if (checkDuplicate == 0)
    {
        printf("%d", counter);
    }

    while (1)
    {
        if (feof(input) != 0)
        {
            break;
        }
        // Part 1
        // addValue1(array, input);

        // Part 2
        // Add the next char and check for duplicate
        addValue2(array, input);
        counter++;
        if (checkDuplicate(array) == 0)
        {
            printf("%d", counter);
            break;
        }
    }

    return 0;
}