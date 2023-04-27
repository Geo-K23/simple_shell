#include "shell.h"
/**
 *_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	char *s = dest;
	int k, l;

	k = 0;
	l = 0;

	while (dest[k] != '\0')
		k++;
	while (src[l] != '\0' && l < n)
	{
		dest[k] = src[l];
		k++;
		l++;
	}
	if (l < n)
		dest[k] = '\0';
	return (s);
}
/**
 *_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the number of characters to be copied
 *Return: the concatenated string
 */

char *_strncpy(char *dest, char *src, int n)
{
	 char *s = dest;

	 int k, l;

	k = 0;
	while (src[k] != '\0' && k < n - 1)
	{
		dest[k] = src[k];
		k++;
	}
	if (k < n)
	{
		l = k;
		while (l < n)

	{
			dest[l] = '\0';
			l++;
		}
	}
	return (s);
}

/**
 *_strchr - locates a character in a string
 * @s: the string to be parsed
 * @c: the character to look for
 * Return: a pointer to the first occurrence of the character
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');
	return (NULL);
}
