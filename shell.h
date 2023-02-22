#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>

extern char **environ;

/**
 * struct command - pointer to function with corresponding buildin command
 * @name: buildin command
 * @func: execute the buildin command
 */
typedef struct command
{
	char *name;
	void (*func)(char **);
} command;

void executeCmd(char **argv);

void *Mem_Realloc(void *ptrPrev, unsigned int old_size, unsigned int new_size);
void EndOfFile(char *b, int l);

int _putchar(char c);
void _puts(char *s);
int _strlen(char *str);
char *_strdup(char *s);

char **tokenize(char *s, const char *d);

char *concat(char *name, char *sep, char *value);


void(*checkcommand(char **arv))(char **arv);

void _exit(char **arv);
int _atoi(char *s);
void _env(char **arv __attribute__ ((unused)));
void _setenv(char **arv);
void _unsetenv(char **arv);

#endif
