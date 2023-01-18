#include "monty.h"

/**
 * errro_exit - If the pointer passed to the function is not NULL, 
 * it calls the free_dlistint function, which frees the memory allocated for each node in the stack.
 * Exits the program with the status EXIT_FAILURE.
 *
 * @stack: pointer to the head of the stack
 *
 */

void error_exit(stack_t **stack)
{
	if (*stack)
		free_dlistint(*stack);
	exit(EXIT_FAILURE);
}

/**
 * isnumber - checks if the string represent a number
 * If the pointer passed to the function is NULL, it returns 0, indicating that the string is not a number.
 * It initializes a variable i and sets it to 0
 * Then, it enters a while loop that will iterate through each character of the string.
 * if the first character of the string is '-', it increments the i and continues the iteration
 * Within the while loop, it uses the isdigit function to check if the current character is a digit.
 * If it is not, it returns 0, indicating that the string is not a number.
 * After the while loop, it returns 1, indicating that the string is a number.
 *
 * @str: string being passed
 *
 * Return: returns 1 is the string is a number and 0 if its not
 */

int isnumber(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}


/**
 * _rotl - performs a left rotation on the elemtent of in the stack, it does this by:
 * Checking if the pointer passed to the function is NULL, if so it returns immediately
 * Initializing a runner pointer and sets it to point to the head of the stack.
 * Iterates through the stack using the runner pointer until it reaches the end of the list.
 * Within the while loop, it checks if the runner pointer is pointing to the last node of the
 * list. If so, it swaps the value of that node with the head of the stack.
 * Else it saves the current node's value in a temporary variable, swaps the value of the
 * current node with the value saved in the previous iteration, and saves the current
 * node's value in the temporary variable.
 * Sets the runner pointer to point to the previous node
 *
 * @stack: pointer to the top of the stack
 * @__attribute__ ((unused)): to tell the compiler that the line_number argument is not used,
 * this is used to suppress the warning from the compiler.
 * @linenumber: the index of the current line
 */

void _rotl(stack_t **stack,  __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner;
	int temp1, temp2;

	if (*stack == NULL)
		return;
	runner = *stack;

	while (runner->next)
		runner = runner->next;
	while (runner)
	{
		if (!runner->next)
		{
			temp1 = runner->n;
			runner->n = (*stack)->n;
		}
		else
		{
			temp2 = runner->n;
			runner->n = temp1;
			temp1 = temp2;
		}
		runner = runner->prev;
	}
}

/**
 * _rotr - performs  a right rotation on the elements of the stack, it does this by:
 * Checking if the pointer passed to the function is NULL, if so it returns immediately.
 * Initializing two runner1, runner2 pointers and sets both of them to point to the head
 * and set them to point on the stack
 * Iterates through the stack using the runner1 pointer until it reaches the end of the list.
 * Iterates through the stack using the runner2 pointer until it reaches the end of the list.
 * Within the while loop, it checks if the runner2 pointer is pointing to the first node of
 * the list. If so, it swaps the value of that node with the last node of the stack.
 * Else it saves the current node's value in a temporary variable, swaps the value of the
 * current node with the value saved in the previous iteration, and saves the current
 * node's value in the temporary variable.
 * Sets the runner2 pointer to point to the next node
 *
 * @ __attribute__ ((unused)): to tell the compiler that the line_number argument is not used
 */

void _rotr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner1, *runner2;
	int temp1, temp2;

	if (*stack == NULL)
		return;

	runner1 = *stack;
	runner2 = *stack;

	while (runner1->next)
	{
		runner1 = runner1->next;
	}
	while (runner2)
	{
		if (runner2->prev == NULL)
		{
			temp1 = runner2->n;
			runner2->n = runner1->n;
		}
		else
		{
			temp2 = runner2->n;
			runner2->n = temp1;
			temp1 = temp2;
		}
		runner2 = runner2->next;
	}
}







































































