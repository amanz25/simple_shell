#include "shell.h"

/**
 * executeCmd - executes a command defined on the first arg
 * @argv: array of args, the first is the comman
 *
 * Returns: void
 */
void executeCmd(char **argv)
{
	int process, status;

	if (!argv || !argv[0])
		return;
	process = fork();
	if (process == -1)
		perror("unable to create child process");
	if (process == 0)
	{
		/* child created */
		execve(argv[0], argv, NULL);
		perror("./shell");
		exit(EXIT_FAILURE);
	}
	/* parent process will wait until the child finish */
	wait(&status);
}