#include "monty.h"

/**
 * push - data saving
 *
 * @stack: data structure
 * @line_number: data
 */
void push(stack_t **stack, unsigned int line_number)
{
stack_t *new = malloc(sizeof(stack_t)), *current;
char *arg;
if (new == NULL)
{
dprintf(STDERR_FILENO, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
arg = strtok(NULL, " \n\t\r");
if (arg == NULL || isdigit(arg[0]) <= 0)
{
dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
new->n = atoi(arg);
new->prev = NULL;
if (*stack == NULL)
{
new->next = NULL;
*stack = new;
return;
}
current = *stack;
new->next = current;
current->prev = new;
*stack = new;
}
