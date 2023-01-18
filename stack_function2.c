#include "monty.h"
/**
 * _nop - The opcode nop doesn’t do anything.
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void _nop(__attribute__ ((unused))stack_t **stack,
	  __attribute__ ((unused))unsigned int line_number)
{
	;
}

/**
 * _pchar - prints the ASCII value of a number
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 * how does this function works?
 * It checks if the stack is empty and if so,
 * it prints an error message and exits the program. 
 * If the stack is not empty, it sets the value of a "runner" variable to the top of the stack
 * and assigns the value of the top of the stack to a variable called "val".
 * It then checks if "val" is a printable ASCII character using the "isprint" function.
 * If "val" is not a printable ASCII character, 
 * it prints an error message and exits the program.
 * If "val" is a printable ASCII character, 
 * it prints the character and a newline.
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;
	int val;

	if (*stack == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_number);
		error_exit(stack);
	}

	runner = *stack;
	val = runner->n;

	if (!isprint(val))
	{
		printf("L%d: can't pchar, value out of range\n", line_number);
		error_exit(stack);
	}
	putchar(val);
	putchar('\n');
}


/**
 * _pstr - print string starting a top of stack
 * @stack: linked list for stack
 * @line_number: line number opcode occurs on
 */

void _pstr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner;
	int val;
	
	runner = *stack;

	while (runner != NULL)
	{
		val = runner->n;
		if (val == 0)
			break;
		if (!isprint(val))
		{
			break;
		}
		putchar(val);
		runner = runner->next;
	}
	putchar('\n');
}


/**
 * _stack - sets stack-queue_flag to stack
 * @stack: pointer to stack list
 * @line_number: line opcode occurs on
 */
void _stack(__attribute__ ((unused)) stack_t **stack,
	    __attribute__ ((unused)) unsigned int line_number)
{
	sq_flag = 0;
}

/**
 * _queue - sets stack-queue_flag to queue
 * @stack: pointer to stack list
 * @line_number: line opcode occurs on
 */
void _queue(__attribute__ ((unused))stack_t **stack,
	    __attribute__ ((unused))unsigned int line_number)
{
	sq_flag = 1;
}
