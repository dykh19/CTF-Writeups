#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct code referenced from GeeksForGeeks
struct stackNode
{
    char data;
    struct stackNode *next;
};

struct stackNode *newNode(char data)
{
    struct stackNode *stackNode = (struct stackNode *)malloc(sizeof(struct stackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

void push(struct stackNode **root, char data)
{
    struct stackNode *stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

char pop(struct stackNode **root)
{
    struct stackNode *temp = *root;
    *root = (*root)->next;
    char data = temp->data;
    free(temp);
    return data;
}

char peek(struct stackNode **root)
{
    return (*root)->data;
}

int isEmpty(struct stackNode **root)
{
    return !*root;
}

int main()
{
    // Hardcode the initial state of the stacks
    struct stackNode *s1 = NULL;
    struct stackNode *s2 = NULL;
    struct stackNode *s3 = NULL;
    struct stackNode *s4 = NULL;
    struct stackNode *s5 = NULL;
    struct stackNode *s6 = NULL;
    struct stackNode *s7 = NULL;
    struct stackNode *s8 = NULL;
    struct stackNode *s9 = NULL;

    struct stackNode **stackArray[9] = {&s1, &s2, &s3, &s4, &s5, &s6, &s7, &s8, &s9};

    push(&s1, 'J');
    push(&s1, 'H');
    push(&s1, 'P');
    push(&s1, 'M');
    push(&s1, 'S');
    push(&s1, 'F');
    push(&s1, 'N');
    push(&s1, 'V');

    push(&s2, 'S');
    push(&s2, 'R');
    push(&s2, 'L');
    push(&s2, 'M');
    push(&s2, 'J');
    push(&s2, 'D');
    push(&s2, 'Q');

    push(&s3, 'N');
    push(&s3, 'Q');
    push(&s3, 'D');
    push(&s3, 'H');
    push(&s3, 'C');
    push(&s3, 'S');
    push(&s3, 'W');
    push(&s3, 'B');

    push(&s4, 'R');
    push(&s4, 'S');
    push(&s4, 'C');
    push(&s4, 'L');

    push(&s5, 'M');
    push(&s5, 'V');
    push(&s5, 'T');
    push(&s5, 'P');
    push(&s5, 'F');
    push(&s5, 'B');

    push(&s6, 'T');
    push(&s6, 'R');
    push(&s6, 'Q');
    push(&s6, 'N');
    push(&s6, 'C');

    push(&s7, 'G');
    push(&s7, 'V');
    push(&s7, 'R');

    push(&s8, 'C');
    push(&s8, 'Z');
    push(&s8, 'S');
    push(&s8, 'P');
    push(&s8, 'D');
    push(&s8, 'L');
    push(&s8, 'R');

    push(&s9, 'D');
    push(&s9, 'S');
    push(&s9, 'J');
    push(&s9, 'V');
    push(&s9, 'G');
    push(&s9, 'P');
    push(&s9, 'B');
    push(&s9, 'F');

    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        printf("File could not be opened");
        exit(0);
    }
    char *buf = (char *)malloc(sizeof(char) * 30);
    int number, src, dest, counter = 0;
    // Hardcoded length of lines in input file
    while (counter < 504)
    {
        fgets(buf, 30, input);
        buf[strcspn(buf, "\n")] = 0;
        // Split the string into the number, source and destination
        strtok(buf, " ");
        number = atoi(strtok(NULL, " "));
        strtok(NULL, " ");
        src = atoi(strtok(NULL, " "));
        strtok(NULL, " ");
        dest = atoi(strtok(NULL, " "));
        // Part 1
        // for (int i = 0; i < number; i++)
        // {
        //     char temp = pop(stackArray[src - 1]);
        //     push(stackArray[dest - 1], temp);
        // }

        // Part 2
        struct stackNode **tempStack = NULL;
        for (int i = 0; i < number; i++)
        {
            push(&tempStack, pop(stackArray[src - 1]));
        }
        for (int i = 0; i < number; i++)
        {
            push(stackArray[dest - 1], pop(&tempStack));
        }
        counter++;
    }

    // Print out top crate for each stack
    for (int i = 0; i < 9; i++)
    {
        printf("%c", peek(stackArray[i]));
    }

    // Free stack memory
    for (int i = 0; i < 9; i++)
    {
        while (isEmpty(stackArray[i]) == 0)
        {
            pop(stackArray[i]);
        }
    }
    free(buf);
}
