#include "monty.h"

/* This code is a function named add_dnodeint that takes in two arguments*/

/**
 * add_dnodeint - add node at the beginning of the list
 * it does this by:
 * The function starts by allocating memory for a new node using the malloc function 
 * and assigns it to a pointer named new. If the allocation fails, NULL is returned.
 * Then it checks if the list is empty, if it is, the new node will be the first node in the list,
 * it assigns the value of n to the new node,
 * set both next and prev pointers to NULL and 
 * the double pointer head points to the new node.
 * Otherwise, it sets the prev pointer of the current first node to point to the new node
 * and sets the next pointer of the new node to point to the current first node.
 * The value of n is assigned to the new node,
 * the prev pointer is set to NULL and 
 * the double pointer head is updated to point to the new node. 
 * Finally, the function returns a pointer to the new first node.
 *
 * @head: pointer to first node
 * @n: data inside the node
 * Return: pointer to first node
 */


stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;
	new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);

	if (*head == NULL)
	{
		new->n = n;
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (*head);
	}
	(*head)->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
	return (*head);
}


/* This code is a function named delete_dnodeint_at_index that takes in two argument*/
/**
 * @head: pointer to first node
 * @index: an integer representing the position of the node in the list that will be deleted.
 *
 * it works like this:
 * The function starts by checking if the list is empty, if it is, it returns -1.
 * Then it creates a pointer named tmp and assigns it to the current first node of the list
 * and creates another pointer named tmp2.
 * It checks if the node to be deleted is the first node in the list.
 * If so, it updates the pointer head to point to the second node,
 * if there is one, sets the prev pointer of the second node to NULL, 
 * frees the memory of the first node and returns 1.
 * Otherwise, it iterates through the list starting from the first node,
 * until it reaches the node before the one to be deleted
 * Then it sets tmp2 to the node after the one to be deleted, 
 * if there is one, updates the prev pointer of the node after the one to be deleted 
 * to point to the current node,
 * frees the memory of the node to be deleted,
 * sets the next pointer of the current node to tmp2.
 *
 * Return: return 1 to indicate that the deletion was successful and -1 if failure
 */

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *tmp;
	stack_t *tmp2;
	unsigned int i;

	if (*head == NULL)
		return (-1);
	tmp = *head;

	if (index == 0)
	{
		*head = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = NULL;
		free(tmp);
		return (1);
	}
	i = 0;
	while (i < (index - 1))
	{
		if (tmp == NULL)
			return (-1);
		tmp = tmp->next;
		i++;
	}
	tmp2 = (tmp->next)->next;
	if (tmp->next->next != NULL)
		tmp->next->next->prev = tmp;
	free(tmp->next);
	tmp->next = tmp2;

	return (1);
}

/**
 * add_dnodeint_end - add node to end of list
 * @head: pointer to first node
 * @n: data to be filled in the node
 * Return: pointer to the first node
 *
 * The function starts by allocating memory for a new node using the malloc function 
 * and assigns it to a pointer named new_node. If the allocation fails, NULL is returned.
 * Then it assigns the value of n to the new node, creates a pointer named tmp 
 * and assigns it to the first node of the list.
 * If the list is empty, the new node will be the first node in the list, 
 * sets both next and prev pointers to NULL, 
 * the double pointer head points to the new node and the function returns pointer to the new node.
 * Otherwise, it iterates through the list using tmp->next until it reaches the last node.
 * Then it sets the next pointer of the last node to point to the new node, 
 * sets the prev pointer of the new node to point to the last node,
 * sets the next pointer of the new node to NULL and 
 * returns the pointer to the new node.
 *
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tmp = *head;
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (*head == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new_node;
	new_node->prev = tmp;
	new_node->next = NULL;
	return (new_node);
}


/**
 * free_dlisint- free a list
 * @head: pointer to first node
 *
 * The function starts by creating a pointer named tmp and 
 * initializing it to the next pointer of the first node.
 * It then enters a while loop that continues while the head pointer is not equal to NULL.
 * Inside the loop it assigns the next pointer of the current head node to tmp, 
 * calls the free() function to deallocate the memory of the current head node 
 * and assigns the value of tmp to head.
 * This continues until head becomes NULL indicating that all nodes 
 * have been freed and the function exits.
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;
	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}



