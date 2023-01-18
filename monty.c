#include "monty.h"

/**
 * main - Entry of the program monty
 * @ac: an integer representing the number of arguments passed to the program
 * @av: a double pointer to an array of strings representing the arguments passed to the program
 * Return: 0
 *
 * it works like this:
 * The function starts by defining and initializing a pointer to a stack named stack to NULL.
 * It then checks if the number of arguments passed to the program is not equal to 2,
 * if it is, it prints an error message "USAGE: monty file\n" and calls the error_exit function, 
 * passing in the address of the stack pointer.
 * If the number of arguments is correct, it calls the read_file function,
 * passing in the second argument (the file name) and the address of the stack pointer.
 * After the read_file function is done, it calls the free_dlistint function
 * and passing in the stack pointer, to free the memory allocated for the stack. 
 * Finally, it returns 0.
 */
int sq_flag = 0;
int main(int ac, char **av)
{
	stack_t *stack;

	stack = NULL;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		error_exit(&stack);
	}
	read_file(av[1], &stack);
	free_dlistint(stack);
	return (0);
}
