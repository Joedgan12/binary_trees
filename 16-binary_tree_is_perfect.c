#include "binary_trees.h"

int binary_tree_is_perfect(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
	size_t leaf_depth, size_t level);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
size_t depth(const binary_tree_t *tree);
unsigned char is_leaf(const binary_tree_t *node);

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 0 if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect.
 *
 * @tree: A pointer to the node of the tree to check.
 * @leaf_depth: The depth of the first leaf found in the tree.
 * @level: The level of the tree.
 *
 * Return: If the tree is perfect - 1.
 *	Otherwise - 0.
 */
int is_perfect_recursive(const binary_tree_t *tree,
	size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
	return (level == leaf_depth);
	if (!tree->left || !tree->right)
	return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
	is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * get_leaf - Gets the first leaf of a tree.
 *
 * @tree: A pointer to the root node of the tree to find a leaf in.
 *
 * Return: A pointer to the first leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	while (tree->left)
	tree = tree->left;
	return (tree);
}

/**
 * depth - Returns the depth of a given
 *	node in a binary tree.
 * @tree: A pointer to the node to measure the depth of.
 *
 * Return: The depth of node.
 */
size_t depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree)
	{
	depth++;
	tree = tree->parent;
	}
	return (depth);
}

/**
 * is_leaf - Checks if a node is a leaf of a tree.
 *
 * @node: The node to check.
 *
 * Return: If the node is a leaf - 1.
 *	Otherwise - 0.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return (!node->left && !node->right);
}
