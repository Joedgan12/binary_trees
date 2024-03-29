#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (tree == NULL)
	return (0);
	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (1);
	if (tree->left && tree->left->n >= tree->n)
	return (0);
	if (tree->right && tree->right->n <= tree->n)
	return (0);
	if (!binary_tree_is_bst(tree->left) || !binary_tree_is_bst(tree->right))
	return (0);
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height_diff;

	if (tree == NULL)
	return (0);

	if (!binary_tree_is_bst(tree))
	return (0);

	height_diff = binary_tree_height(tree->left) -
	binary_tree_height(tree->right);
	if (height_diff > 1 || height_diff < -1)
	return (0);

	if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
	return (0);

	return (1);
}
