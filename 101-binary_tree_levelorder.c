#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of a binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
	return (0);

	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (left_height > right_height ? left_height : right_height);
}

/**
 * print_given_level - prints nodes at given level
 * @tree: pointer to the root node of the tree to traverse
 * @level: level at which the nodes are to be printed
 * @func: pointer to a function to call for each node
 */
void print_given_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
	return;
	if (level == 1)
	func(tree->n);
	else if (level > 1)
	{
	print_given_level(tree->left, level - 1, func);
	print_given_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = binary_tree_height(tree);
	int i;

	if (tree == NULL || func == NULL)
	return;

	for (i = 1; i <= height + 1; i++)
	print_given_level(tree, i, func);
}
