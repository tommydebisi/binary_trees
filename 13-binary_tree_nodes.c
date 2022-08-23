#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with
 * at least 1 child in a binary tree
 *
 * @tree: pointer to the root node of the
 * tree to count the number of nodes
 *
 * Return: number of nodes with at least 1 child or
 * 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	/* make sure to declare and initialize */
	size_t left_node = 0, right_node = 0, count = 0;

	if (!tree)
		return (0);

	left_node = binary_tree_nodes(tree->left);
	right_node = binary_tree_nodes(tree->right);

	if (!tree->left && tree->right)
		count++;
	else if (tree->left && !tree->right)
		count++;
	else if (tree->left && tree->right)
		count++;

	return (left_node + right_node + count);
}
