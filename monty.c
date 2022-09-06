#include "monty.h"
#define READSIZE 1024
#define EXIT exit(EXIT_FAILURE)
/**
 * ErrorHandler - handle errors in the program
 * @error_number: unique error number for different error
 * @arg: string needle for the error
 *
 * Return: return void
 */
void ErrorHandler(int error_number, char *arg)
{
	switch (error_number)
	{
		case 1:/* program argument error */
		{
			dprintf(STDERR_FILENO, "USAGE: monty %s\n", arg);
			EXIT;
			break;
		}
		case 2:/* open file error */
		{
			dprintf(STDERR_FILENO, "Error could'nt open file %s\n", arg);
			EXIT;
			break;
		}
		case 3:/* malloc error */
		{
			dprintf(STDERR_FILENO, "Error: malloc failed\n");
			EXIT;
			break;
		}
	}
}
static void _execute(char **argv)
{
	size_t i = 0, j;
	instruction_t func[] = {
		{"push", Func_push},
		{"pall", Func_pall},
		{'\0', NULL}
	};
	while (func[i].opcode)
	{
		j = 0;
		while (argv[j])
		{
			if (!strcmp(argv[j], "push"))
				Func_push(argv[j], atoi(argv[j + 1]));
			else if (isdigit(argv[j]) != 0)
				func[i].f(argv[j]);
			j++;
		}
		i++;
	}
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
	int fd, readsize;
	char *readptr = NULL, **commands = NULL;

	if (argc == 1 || argc > 2)
		ErrorHandler(1, argv[1]);
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		ErrorHandler(2, argv[1]);
	readptr = malloc(sizeof(char) * READSIZE);
	if (!readptr)
		ErrorHandler(3, NULL);
	readsize = read(fd, readptr, READSIZE);
	commands = _strtokenize(readptr);
	_execute(commands);
	return (0);
}
