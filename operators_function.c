#include "monty.h"

/**
 * _add - adds top and second of stack together
 * @stack: pointer to list
 * @line_number: number of line opcode occurs on
 *
 * it works like this:
 * The function first checks if the stack has at least 2 elements in it, 
 * by checking if stack pointer is NULL or the next pointer of the top element is NULL 
 * if it is the case, it will print an error message "L%d: can't add, stack too short\n" 
 * with the current line number and then call error_exit function.
 * Otherwise, it will perform an addition operation on the n value of the second element of the
 * stack and the top element of the stack and updates the n value of the second element. 
 * Then it calls _pop function to remove the top element from the stack.
 */

void _add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_number);
}

/**
 * _sub - substract top and second of stack
 * @stack: pointer to list
 * @line_number: number of line opcode occurs on
 *
 * it works like this:
 * The function first checks if the stack has at least 2 elements in it, 
 * by checking if stack pointer is NULL or the next pointer of the top element is NULL 
 * if it is the case, it will print an error message "L%d: can't add, stack too short\n" 
 * with the current line number and then call error_exit function.
 * Otherwise, it will perform a subtraction operation on the n value of the second element of the
 * stack and the top element of the stack and updates the n value of the second element. 
 * Then it calls _pop function to remove the top element from the stack.
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n -= (*stack)->n;
	_pop(stack, line_number);
}


/**
 * _mul - multiply top and second of stack together
 * @stack: pointer to list
 * @line_number: number of line opcode occurs on
 *
 * it works like this:
 * The function first checks if the stack has at least 2 elements in it, 
 * by checking if stack pointer is NULL or the next pointer of the top element is NULL 
 * if it is the case, it will print an error message "L%d: can't add, stack too short\n" 
 * with the current line number and then call error_exit function.
 * Otherwise, it will perform a multiplication operation on the n value of the second element of the
 * stack and the top element of the stack and updates the n value of the second element. 
 * Then it calls _pop function to remove the top element from the stack.
 */


void _mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n *= (*stack)->n;
	_pop(stack, line_number);
}



/**
 * _div - divide top and second of stack together
 * @stack: pointer to list
 * @line_number: number of line opcode occurs on
 *
 * it works like this:
 * The function first checks if the stack has at least 2 elements in it, 
 * by checking if stack pointer is NULL or the next pointer of the top element is NULL 
 * if it is the case, it will print an error message "L%d: can't add, stack too short\n" 
 * with the current line number and then call error_exit function.
 * Otherwise, it will perform a devision operation on the n value of the second element of the
 * stack and the top element of the stack and updates the n value of the second element. 
 * Then it calls _pop function to remove the top element from the stack.
 */

void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		error_exit(stack);
	}
	if ((*stack)->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n /= (*stack)->n;
	_pop(stack, line_number);
}

/**
 * _mod - modulus top and second of stack together
 * @stack: pointer to list
 * @line_number: number of line opcode occurs on
 *
 * it works like this:
 * The function first checks if the stack has at least 2 elements in it, 
 * by checking if stack pointer is NULL or the next pointer of the top element is NULL 
 * if it is the case, it will print an error message "L%d: can't add, stack too short\n" 
 * with the current line number and then call error_exit function.
 * Then check if the value in the stack is 0, and print err,then call error_exitt function.
 * Otherwise, it will perform a modulus operation on the n value of the second element of the
 * stack and the top element of the stack and updates the n value of the second element. 
 * Then it calls _pop function to remove the top element from the stack.
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mod, stack too short\n", line_number);
		error_exit(stack);
	}
	if ((*stack)->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n %= (*stack)->n;
	_pop(stack, line_number);
}
