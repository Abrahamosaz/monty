#include "monty.h"
#define READSIZE 1024
#define EXIT exit(EXIT_FAILURE)
int stack_value;
/**
 * ErrorHandler - handle errors	 in the program
 * @error_number: unique error number for different error
 * @arg: string needle for the error
 *
 * Return: return void
 */
void ErrorHandler(int error_number, char *arg, int line_number)
{
	switch (error_number)
	{
		case 1:/* program argument error */
		{
			fprintf(stderr, "USAGE: monty %s\n", arg);
			EXIT;
			break;
		}
		case 2:/* open file error */
		{
			fprintf(stderr, "Error could'nt open file %s\n", arg);
			EXIT;
			break;
		}
		case 3:/* malloc error */
		{
			fprintf(stderr, "Error: malloc failed\n");
			EXIT;
			break;
		}
		case 4:/* opcode error (invalid instruction) */
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, arg);
			EXIT;
			break;
		}
	}
}
/**
 *
 *
 */
static void call_func(char **argv)
{
	size_t i = 0, j, line_number = 1, check = 0;
	instruction_t func[] = {
		{"push", Func_push},
		{"pall", Func_pall},
		{"pint", Func_pint},
		{"swap", Func_pall},
		{'\0', NULL}
	};
	opcode_t *opcode_info = NULL;
	stack_t *head = NULL;

	while (argv[i])
	{
		opcode_info = StrtokenizLineCommand(argv[i]);
		j  = 0;
		while (func[j].opcode)
		{
			if (!strcmp(func[j].opcode, opcode_info->opcode_name))
			{
				stack_value = opcode_info->opcode_value;
				func[j].f(&head, line_number);
				check = 1;
				break;
			}
			j++;
		}
		if (!check)
			ErrorHandler(4, opcode_info->opcode_name, line_number);
		line_number++;
		free(opcode_info);
		free(argv[i]);
		opcode_info = NULL;
		i++;
		check = 0;
	}
	free(argv);
}
/**
 * main - main program of the motty
 * @argc: number of argumant to the program
 * @argv: argument to the program
 *
 * Return: retunr integer value
 */
int main(int argc, char *argv[])
{
	int fd;
	char *readptr = NULL, **str_token = NULL;

	if (argc == 1 || argc > 2)
		ErrorHandler(1, argv[1], 0);
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		ErrorHandler(2, argv[1], 0);
	readptr = malloc(sizeof(char) * READSIZE);
	if (!readptr)
		ErrorHandler(3, NULL, 0);
	read(fd, readptr, READSIZE);
	str_token = _strtokenize(readptr);
	call_func(str_token);
	return (0);
}
