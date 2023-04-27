#include "shell.h"
/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 * Return: array of strings
 */

char **list_to_strings(list_t *head)
{
	char **strs;
	char *str;
	list_t *node = head;
	size_t k = list_len(head), j;

	if (!head || !k)
		return (NULL);
	strs = malloc(sizeof(char *) * (k + 1));
	if (!strs)
		return (NULL);
	for (k = 0; node; node = node->next, k++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < k; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
		str = _strcpy(str, node->str);
		strs[k] = str;
	}
	strs[k] = NULL;
	return (strs);
}
/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 * Return: index of node or -1
 */

ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t index = 0;

	while (head != NULL)
	{
		if (head == node)
		{
			return (index);
		}
		head = head->next;
		index++;
	}
	return (-1);
}
/**
 * list_len - determines length of linked list
 * @h: pointer to first node
 * Return: size of list
 */

size_t list_len(const list_t *h)
{
	size_t len = 0;

	while (h != NULL)
	{
		h = h->next;
		len++;
	}
	return (len);
}

/**
 * print_list - prints all elements of a linked list list_t
 * @h: pointer to first node
 * Return: size of list
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		count++;
	}
	return (count);
}

/**
 * node_starts_with - returns node whose string starts with a prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 * Return: match node or null
 */

list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
		{
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}


