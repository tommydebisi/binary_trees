#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is full or 0 is not full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);

	left = binary_tree_is_full(tree->left);
	right = binary_tree_is_full(tree->right);

	if (!left && !right) /* just starting out or not */
	{
		if ((!tree->left && !tree->right) || (tree->left && tree->right))
			return (1);
		return (0);
	}
	else if (!left || !right)
		return (0);
	return (1);	/* two children are present */
}
