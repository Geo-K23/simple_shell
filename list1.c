#include "shell.h"

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
		len++;
		h = h->next;
	}
	return (len);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 * Return: array of strings
 */

char **list_to_strings(list_t *head)
{

	int count = 0;
	int i = 0;
	list_t *current = head;
	char **strings;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	strings = malloc(sizeof(char *) * count);
	current = head;
	while (current != NULL)
	{
		strings[i] = malloc(_strlen(current->str) + 1);
		_strcpy(strings[i], current->str);
		current = current->next;
		i++;
	}
	current = head;
	while (current != NULL)
	{
		list_t *temp = current;

		current = current->next;

		free(temp->str);
		free(temp);
	}
	return (strings);
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
