#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure size
 * Return: size of a binary tree or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	/* make sure to declare and initialize */
	size_t left_node = 0, right_node = 0, current_node = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_node = binary_tree_size(tree->left);

	if (tree->right)
		right_node = binary_tree_size(tree->right);

	current_node = 1;
	return (left_node + right_node + current_node);
}
