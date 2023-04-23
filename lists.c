#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 * Return: size of list
 */

list_t *add_node(list_t **head, const char *str, int num)
{

	list_t *new_node;

	if (head == NULL)
	{
		return (NULL);
	}
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (new_node->str == NULL)
		{
			free(new_node);
			return (NULL);
		}
	}
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}
/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 * Return: size of list
 */

list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
	{
		return (NULL);
	}
	node = *head;
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str != NULL)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node != NULL)
	{
		while (node->next)
		{
			node = node->next;
		}
		node->next = new_node;
	}
	else
	{
		*head = new_node;
	}
	return (new_node);
}

/**
 * print_list_str - prints only the str element of a linked list
 * @h: pointer to first node
 * Return: size of list
 */

size_t print_list_str(const list_t *h)
{
	size_t len = 0;

	while (h != NULL)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		len++;
	}
	return (len);
}

/**
 * delete_node_at_index - deletes a node at a given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *  Return: 1 on success, 0 on failure
 */

int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *prev, *cur;
	unsigned int i;

	if (*head == NULL)
		return (-1);
	cur = *head;
	if (index == 0)
	{
		*head = cur->next;
		free(cur);
		return (0);
	}
	for (i = 0; i < index; i++)
	{
		prev = cur;
		cur = cur->next;
		if (cur == NULL)
			return (-1);
	}
	prev->next = cur->next;
	free(cur);
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 * Return: void
 */

void free_list(list_t **head_ptr)
{
	list_t *current = *head_ptr;

	while (current != NULL)
	{
		list_t *temp = current;

		current = current->next;

		free(temp);
	}
	*head_ptr = NULL;
}
