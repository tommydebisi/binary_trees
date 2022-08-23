#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 *
 * @tree: pointer to the root node of the tree to count the number of leaves
 * Return: number of leaves in the binary tree or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	/* make sure to declare and initialize */
	size_t left_node = 0, right_node = 0, count = 0;

	if (!tree)
		return (0);

	left_node = binary_tree_leaves(tree->left);
	right_node = binary_tree_leaves(tree->right);

	if (!tree->left && !tree->right) /* count only at leaf nodes */
		count++;

	return (left_node + right_node + count);
}
