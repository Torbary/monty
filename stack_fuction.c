#include "monty.h"

/**
 * _push - push an integer to the stack. It does this by:
 * Initializing a new node new and allocating memory for it using malloc.
 * If the allocation fails, it prints an error message and exits the program with a failure status.
 * It uses strtok to get the next token in the string, which in this case should be 
 * the integer argument to be pushed to the stack.
 * It then uses the isnumber function to check if the argument is a valid number 
 * and that it is not NULL.
 * If the argument is a valid number, it uses the atoi function to convert
 * the argument to an integer and assigns the value to push_arg.
 * Else it prints an error message to the user with the correct line number 
 * and exits the program with a failure status.
 * The new node's n is set to push_arg and added to the stack.
 *
 * sq_flag -  uses it to decide whether to add the new node to the beginning or
 * the end of the doubly linked list stack.
 *
 * If sq_flag is set to 1, it uses the add_dnodeint_end function to 
 * add the new node with the value of push_arg to the end of the stack.
 *
 * If sq_flag is set to 0, it uses the add_dnodeint function to 
 * add the new node with the value of push_arg to the beginning of the stack.
 *
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *arg;
	int push_arg;

	push_arg = 0;
	new = malloc(sizeof(stack_t));

	if (!new)
	{
		printf("Error: malloc function failed\n");
		error_exit(stack);
	}

	arg = strtok(NULL, "\n ");
	if (isnumber(arg) == 1 && arg != NULL)
	{
		push_arg = atoi(arg);
	}
	else
	{
		printf("L%d: usage: push inetger'n", line_number);
		error_exit(stack);
	}

	if (sq_flag == 1)
	{
		add_dnodeint_end(stack, push_arg);
	}

	if (sq_flag == 0)
	{
		add_dnodeint(stack, push_arg);
	}
}


/**
 * _pall - print all element in the stack lati oke de ile
 * @stack: a pointer to a linked list stack
 * @line_number: an unsigned integer representing the line number of the
 * opcode that this function is being called from
 * 
 * runner - to traverse the linked list stack and print out the value n of
 * each element in the stack, starting from the top
 *
 * it does this by:
 * initializing runner to the current top of the stack (*stack) and then 
 * iterating through the linked list by setting runner to runner->next at each iteration, 
 * until runner is equal to NULL, which indicates that we have reached the end of the stack.
 */

void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	while (runner != NULL)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}

/**
 * _pint - print the integer at the top of stack ONLY
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occures on
 *
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;

	if (runner == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		error_exit(stack);
	}
	printf("%d\n", runner->n);
}


/**
 * _swap - swap the element in the top of stack with the n in the second stack
 * it does this by:
 * Initializing runner to the current top of the stack (*stack) and 
 * checking if the stack has at least two elements. 
 * If it does not, it will print an error message "L%d: can't swap, stack too short\n"
 * with the current line number and then call error_exit function. 
 * Otherwise it will swap the values by using a temporary variable tmp and 
 * swapping the values of the top and second element using the runner->next pointer.
 *
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;
	int tmp;

	runner = *stack;
	if (runner == NULL || runner->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		error_exit(stack);
	}
	tmp = runner->n;
	runner->n = runner->next->n;
	runner->next->n = tmp;
}


/**
 * _pop - delete item at top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		error_exit(stack);
	}
	delete_dnodeint_at_index(stack, 0);
}

