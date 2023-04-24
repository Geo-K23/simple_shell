#include "shell.h"

/**
 *is_interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int is_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @ch: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char ch, char *delim)
{
	while (*delim)
		if (*delim++ == ch)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @ch: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @strg: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *strg)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; strg[i] != '\0' && flag != 2; i++)
	{
		if (strg[i] == '-')
			sign *= -1;

		if (strg[i] >= '0' && strg[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (strg[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

