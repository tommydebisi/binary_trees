#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree:  pointer to the root node of the tree to measure the height
 *
 * Return: the height of the binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	return (get_maxHeight(tree) - 1);
}

/**
 * get_maxHeight - gets the maximum height of a tree
 *
 * @tree: pointer to the root node of the tree
 * Return: The maximum height of a tree
 */
size_t get_maxHeight(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;
	if (!tree)
		return (0);

	left = 1 + get_maxHeight(tree->left);
	right = 1 + get_maxHeight(tree->right);

	if (left < right)
		return (right);
	else
		return (left);
}

