#include "shell.h"

/**
 * _putchar - prints character
 * @c: character to be printed
 *
 * Return: 1 (success) , -1 (error)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - print string using the above print character func
 * @s: char pointer to the string to be printed
 *
 * Return: void.
 */

void _puts(char *s)
{
	int count;

	for (count = 0; s[count]; count++)
		_putchar(s[count]);
}

/**
 * _strlen - count the characters in the string
 * @str: string to be checked
 *
 * Return: character count
 */
int _strlen(char *str)
{
	int count;

	for (count = 0; str[count] != '\0'; count++)
		;

	return (count);
}

/**
 * _strdup - copy string and allocate a new memory
 * @s: string to be copied pointer
 *
 * Return: string pointer
 */
char *_strdup(char *s)
{
	int count, newCount;
	char *cpy;

	if (!s)
		return (NULL);

	count = 0;
	while (s[count] != '\0')
		count++;

	cpy = malloc(sizeof(char) * count + 1);
	if (!cpy)
		return (NULL);
	newCount = 0;
	while (newCount < count)
	{
		cpy[newCount] = s[newCount];
		newCount++;
	}
	cpy[count] = s[count];
	return (cpy);
}

/**
 * concat - concats 3 strings in a newly allocated memory
 * @name: first string
 * @sep: second string
 * @value: Third string
 * Return: pointer to the new string
 */
char *concat(char *name, char *sep, char *value)
{
	char *result;
	int l1, l2, l3, i, k;

	l1 = _strlen(name);
	l2 = _strlen(sep);
	l3 = _strlen(value);

	result = malloc(l1 + l2 + l3 + 1);
	if (!result)
		return (NULL);

	for (i = 0; name[i]; i++)
		result[i] = name[i];
	k = i;

	for (i = 0; sep[i]; i++)
		result[k + i] = sep[i];
	k = k + i;

	for (i = 0; value[i]; i++)
		result[k + i] = value[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}
