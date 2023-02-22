#include "shell.h"

/**
 * main - our simple shell
 *
 * Return: void.
 */
int main(void)
{
	ssize_t l = 0, size = 0;
	char *buff = NULL, **arv;

	while (l != EOF)
	{
		_puts("#");
		l = getline(&buff, &size, stdin);
		EndOfFile(buff, l);
		arv = tokenize(buff, " \n");
		executeCmd(arv);
	}
	free(buff);
	return (0);
}
