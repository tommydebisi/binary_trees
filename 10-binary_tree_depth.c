#include "binary_trees.h"

/**
 * binary_tree_depth - measures depth of a node in a binary tree
 *
 * @tree: pointer to the node to measure depth
 * Return: the depth of the node or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (count);

	while (tree->parent)
	{
		count++;
		tree = tree->parent;
	}

	return (count);
}
