#include <stdlib.h>
#include "binary_trees.h"

/**
 * minValueNode - get the node with the smallest value
 * @node: root of the tree
 * Return: node with the smallest value
 */
bst_t *minValueNode(bst_t *node)
{
	bst_t *current = node;

	/* Loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return (current);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after
 * removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (root);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;
			if (root->parent)
			{
				if (root->parent->left == root)
					root->parent->left = temp;
				else
					root->parent->right = temp;
			}
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;
			if (root->parent)
			{
				if (root->parent->left == root)
					root->parent->left = temp;
				else
					root->parent->right = temp;
			}
			free(root);
			return (temp);
		}

		bst_t *temp = minValueNode(root->right);

		root->n = temp->n;

		if (temp->parent->left == temp)
			temp->parent->left = temp->right;
		else
			temp->parent->right = temp->right;

		free(temp);
	}
	return (root);
}
