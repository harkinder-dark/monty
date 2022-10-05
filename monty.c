#include "monty.h"
#include <stdio.h>
#include <string.h>

param_t run = {NULL, NULL, NULL};

/**
 * main - monty programme main
 * 
 * @argc: main parameter count 
 * @argv: main parameter
 * Return: int
 */
int main(int argc, char *argv[])
{
    size_t n = 0;
    unsigned int i;
    FILE *fd = NULL;
    char *lineptr = NULL;
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    fd = fopen(argv[1], "r");
    if (fd == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    for (i = 1; getline(&lineptr, &n, fd) != -1; i++)
    {
        run.line = strtok(lineptr, "\n\t\r$");
        execute(&stack, i);
    }
    fclose(fd);
    return (0);
}
