#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to be used in qsort
int compare(const void *a, const void *b)
{
    if (*(int *)a == *(int *)b)
        return 0;
    return *(int *)a > *(int *)b ? -1 : 1;
}

int main()
{
    // Get number of elfs
    int numberOfElfs = 0;
    FILE *input = fopen("input.txt", "r");

    char *string_buf = (char *)malloc(sizeof(char) * 10);
    while (1)
    {
        strncpy(string_buf, "0", 1);
        fgets(string_buf, 10, input);
        if (feof(input))
        {
            numberOfElfs++;
            break;
        }
        if (strcmp(string_buf, "\n") == 0)
        {
            numberOfElfs++;
        }
    }
    // free(string_buf);
    printf("Number of elfs = %d\n", numberOfElfs);

    // Allocate memory for array of elfs
    int *elfCalories = (int *)malloc(numberOfElfs * sizeof(int));
    // Add calories for each elf
    rewind(input);
    int totalCalories;
    int counter = numberOfElfs;
    for (int i = 0; i < numberOfElfs; i++)
    {
        totalCalories = 0;
        while (1)
        {
            strncpy(string_buf, "0", 1);
            fgets(string_buf, 10, input);
            if (feof(input))
            {
                break;
            }
            if (strcmp(string_buf, "\n") == 1)
            {
                totalCalories += atoi(string_buf);
            }
            else
            {
                break;
            }
        }
        elfCalories[i] = totalCalories;
    }

    // Sort Array to find first second third
    qsort(elfCalories, numberOfElfs, sizeof(int), compare);

    printf("First Elf Calories:%d\n", elfCalories[0]);
    printf("Second Elf Calories:%d\n", elfCalories[1]);
    printf("Third Elf Calories:%d\n", elfCalories[2]);
    printf("Total = %d\n", elfCalories[0] + elfCalories[1] + elfCalories[2]);

    free(string_buf);
    free(elfCalories);
    fclose(input);
}
