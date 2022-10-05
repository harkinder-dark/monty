#include "monty.h"

void pchar(stack_t **stack, unsigned int line_number)
{
    stack_t *current;
    if (*stack == NULL)
    {
        dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    current = *stack;
    if (current->n < 0 || current->n > 127)
    {
        dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    putchar(current->n);
}