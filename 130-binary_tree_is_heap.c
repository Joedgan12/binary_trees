#include "binary_trees.h"
int is_complete(const binary_tree_t *tree, int index, int number_nodes);
int count_nodes(const binary_tree_t *tree);
int is_heap(const binary_tree_t *tree);
/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	if (is_complete(tree, 0, count_nodes(tree)) && is_heap(tree))
	return (1);

	return (0);
}

/**
 * is_complete - Checks if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 * @index: Index of the node
 * @nodes: Total number of nodes
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, int index, int nodes)
{
	if (tree == NULL)
	return (1);

	if (index >= nodes)
	return (0);

	return (is_complete(tree->left, 2 * index + 1, nodes) &&
	is_complete(tree->right, 2 * index + 2, nodes));
}

/**
 * count_nodes - Counts the number of nodes in a binary tree
 *
 * @tree: Pointer to the root node of the tree to count the number of nodes
 *
 * Return: Number of nodes in the tree
 */
int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_heap - Checks if a binary tree is a heap
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a heap, 0 otherwise
 */
int is_heap(const binary_tree_t *tree)
{
	if (tree->left == NULL && tree->right == NULL)
	return (1);

	if (tree->right == NULL)
	return (tree->n >= tree->left->n);

	if (tree->n >= tree->left->n && tree->n >= tree->right->n)
	return (is_heap(tree->left) && is_heap(tree->right));

	return (0);
}
