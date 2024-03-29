#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current;

	if (tree == NULL)
	return (NULL);

	if (*tree == NULL)
	{
	*tree = binary_tree_node(NULL, value);
	return (*tree);
	}

	current = *tree;
	while (1)
	{
	if (value < current->n)
	{
	if (current->left == NULL)
	{
	new_node = binary_tree_node(current, value);
	current->left = new_node;
	return (new_node);
	}
	current = current->left;
	}
	else if (value > current->n)
	{
	if (current->right == NULL)
	{
	new_node = binary_tree_node(current, value);
	current->right = new_node;
	return (new_node);
	}
	current = current->right;
	}
	else
	return (NULL);
	}
}
