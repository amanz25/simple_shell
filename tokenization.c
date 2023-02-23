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
	int argc = 0, count;
	char *t;
	char **argv;

	char *cpy = _strdup(s);

	strcpy(cpy, s);
	t = strtok(s, d);
	argc++;
	while (t)
	{
		argc++;
		t = strtok(NULL, d);
	}

	argv = malloc((sizeof(char *) * argc));
	t = strtok(cpy, d);

	for (count = 0; t; count++)
	{
		argv[count] = malloc(sizeof(char) * _strlen(t));
		strcpy(argv[count], t);
		t = strtok(NULL, d);
	}
	argv[count] = NULL;
	return (argv);
}

/**
* checkcommand - checks if the command is a buildin
* @arv: array of arguments
* Return: pointer to function that takes arv and returns void
*/
void(*checkcommand(char **arv))(char **arv)
{
	int i, j;
	command T[] = {
		{"exit", _exit_cmd},
		{"env", _env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (i = 0; T[i].name; i++)
	{
		j = 0;
		if (T[i].name[j] == arv[0][j])
		{
			for (j = 0; arv[0][j]; j++)
			{
				if (T[i].name[j] != arv[0][j])
					break;
			}
			if (!arv[0][j])
				return (T[i].func);
		}
	}
	return (0);
}
