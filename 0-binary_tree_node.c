#include "binary_trees.h"

/**
 * binary_tree_node - Creates binary tree node
 * @parent: pointer to the parent of node to create
 * @value: value to put in the new node
 *
 * Return: If an error occurs - NULL (0)
 *         Otherwise - pointer to the new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
