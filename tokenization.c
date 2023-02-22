#include "shell.h"

/**
 * tokenize - tokenize/split string based on delimiter
 * @s: string to be tokenized
 * @d: delimiter/common separator
 *
 * Return: pointer to array of string
 */
char **tokenize(char *s, const char *d)
{
	int count, size;
	char **ar, *t, *cpy;

	cpy = malloc(_strlen(s) + 1);
	if (cpy == NULL)
	{
		perror("failure on malloc");
		return (NULL);
	}
	for (count = 0; s[count]; count++)
		cpy[count] = s[count];
	cpy[count] = '\0';

	t = strtok(cpy, d);
	ar = malloc((sizeof(char *) * 2));
	/* copy the first token to the first array element*/
	ar[0] = _strdup(t);

	for (count = 1, size = 3; t; count++, size++)
	{
		/* get the next token */
		t = strtok(NULL, d);
		ar = Mem_Realloc(ar, (sizeof(char *) * (size - 1)), (sizeof(char *) * size));
		ar[count] = _strdup(t);
	}
	free(cpy);
	return (ar);
}
