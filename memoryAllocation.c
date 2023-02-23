#include "shell.h"

/**
 * Mem_Realloc - reallocate memory
 * @ptrPrev: pointer to be reallocated
 * @old_size: current size of the pointer
 * @new_size: new size to be reallocated
 *
 * Return: void.
 */
void *Mem_Realloc(void *ptrPrev, unsigned int old_size, unsigned int new_size)
{
	unsigned int count;
	char *old, *new;

	if (ptrPrev == NULL)
		return (malloc(new_size));
	if (new_size == old_size)
		return (ptrPrev);
	if (new_size == 0 && ptrPrev != NULL)
	{
		free(ptrPrev);
		return (NULL);
	}
	new = malloc(new_size);
	old = ptrPrev;
	if (new == NULL)
		return (NULL);
	if (new_size > old_size)
	{
		count = 0;
		while (count < old_size)
		{
			new[count] = old[count];
			count++;
		}
		free(ptrPrev);
		count = old_size;
		while (count < new_size)
		{
			new[count] = '\0';
			count++;
		}
	}
	if (new_size < old_size)
	{
		for (count = 0; count < new_size; count++)
			new[count] = old[count];
		free(ptrPrev);
	}
	return (new);
}

/**
 * freearv - frees the array of pointers arv
 *@arv: array of pointers
 *
 * Return: void.
 */

void freearv(char **arv)
{
	int i;

	if (arv == NULL)
		return;
	for (i = 0; arv[i]; i++)
		free(arv[i]);

	if (arv[i] == NULL)
		free(arv[i]);
	free(arv);
}
