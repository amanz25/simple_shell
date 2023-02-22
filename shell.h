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


void executeCmd(char **argv);

void *Mem_Realloc(void *ptrPrev, unsigned int old_size, unsigned int new_size);
void EndOfFile(char *b, int l);

int _putchar(char c);
void _puts(char *s);
int _strlen(char *str);
char *_strdup(char *s);

char **tokenize(char *s, const char *d);

#endif
