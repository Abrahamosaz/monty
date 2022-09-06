#include "monty.h"
/**
 *
 *
 *
 */
char **_strtokenize(char *readptr)
{
	char copy_readptr[1024];
	char *delim = " \n", *token, *cpy_token = NULL, **argument = NULL;
	int count  = 0, index = 0;

	strcpy(copy_readptr, readptr);
	cpy_token = strtok(copy_readptr, delim);
	while (cpy_token)
	{
		count++;
		cpy_token = strtok(NULL, delim);
	}
	argument = malloc(sizeof(char *) * count);
	if (!argument)
		ErrorHandler(3, NULL);
	token = strtok(readptr, delim);
	while (token)
	{
		argument[index] = malloc(sizeof(char) * strlen(token));
		if (!argument[index])
			ErrorHandler(3, NULL);
		strcpy(argument[index], token);
		index++;
		token = strtok(NULL, delim);
	}
	free(readptr);
	return (argument);
}
