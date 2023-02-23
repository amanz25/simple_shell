#include "shell.h"


/**
 * EndOfFile - handles buffer end of file
 * @b: buffer
 * @l: length of input by std in
 *
 * Return: void.
 */
void EndOfFile(char *b, int l)
{
	(void) b;
	if (l == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(b);
		}
		exit(0);
	}
}

/**
 * sig_handler - checks if Ctrl C is pressed
 * @sig_num: int
 *
 * Return: void.
 */
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		_puts("\n#cisfun$ ");
	}
}

/**
  * terminal - verif if terminal
  *
  * Return: void.
  */

void terminal(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#cisfun$ ");
}

/**
 * main - our simple shell
 *
 * Return: 0.
 */
int main(void)
{
	ssize_t l = 0;
	size_t size = 0;
	char *buff = NULL, **arv, *v, *p;
	list_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, sig_handler);
	while (l != EOF)
	{
		terminal();
		l = getline(&buff, &size, stdin);
		EndOfFile(buff, l);
		arv = tokenize(buff, " \n");
		if (!arv || !arv[0])
			executeCmd(arv);
		else
		{	/* get the env from PATH */
			v = _getenv("PATH");
			head = linkpath(v);
			p = _which(arv[0], head);
			f = checkcommand(arv);
			if (f)
			{
				free(buff);
				f(arv);
			}
			else if (!p)
				executeCmd(arv);
			else if (p)
			{
				free(arv[0]);
				arv[0] = p;
				executeCmd(arv);
			}
		}
	}
	free_list(head);
	freearv(arv);
	free(buff);
	return (0);
}
