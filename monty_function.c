#include "monty.h"
#include <string.h>

/**
 * read_file - reads a bytecode file and runs commands
 * @filename: pathname to file
 * @stack: pointer to the top of the stack
 *
 * how does this func works?
 *
 * The function starts by opening the file and checking if it's NULL.
 * If it is, it prints an error message and exits. 
 * The function then reads the file line by line using the getline function
 * and assigns the line to a buffer.
 * The line is then parsed using the parse_line function and if the line is NULL or starts with '#',
 * the line count is incremented and the loop continues.
 * The function then gets the operation function associated with the line using 
 * the get_op_func function. If the operation function is NULL, 
 * it prints an error message and exits.
 * The operation function is then executed and the line count is incremented.
 * The buffer is then freed and the file is closed.
 *
 */

void read_file(char *filename, stack_t **stack)
{
	char *buffer = NULL;
	char *line;
	size_t i = 0;
	int line_count = 1;
	instruct_func s;
	int check;
	/*int read;*/
	FILE *file = fopen(filename, "r");


	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		error_exit(stack);
	}
	while (fgets(buffer, i, file) != NULL)
	{
		line = parse_line(buffer);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = get_op_func(line);
		if (s == NULL)
		{
			printf("L%d: unknown instruction %s\n", line_count, line);
			error_exit(stack);
		}
		s(stack, line_count);
		line_count++;
	}
	free(buffer);
	check = fclose(file);
	if (check == -1)
		exit(-1);
}
/**
 * get_op_func -  checks opcode and returns the correct function
 * @str: the opcode
 *
 * Return: returns a function, or NULL on failure
 */
instruct_func get_op_func(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"pchar", _pchar},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"nop", _nop},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"pstr", _pstr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}

#include "monty.h"

/**
 * parse_line - parses a line for an opcode and arguments
 * @line: the line to be parsed
 *
 * Return: returns the opcode or null on failure
 */
char *parse_line(char *line)
{
	char *op_code;

	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);
	return (op_code);
}



