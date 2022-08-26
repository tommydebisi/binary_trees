#include "binary_trees.h"


/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: pointer to the root node
 * Return: 1 if bst or 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int checker = 0;

	if (!tree)
		return (0);

	checker = helper(tree, INT_MIN, INT_MAX);
	return (checker);
}

/**
 * helper - helps checks a tree if bst
 *
 * @tree: pointer to root node
 * @min: min number a root value can have
 * @max: max number a root value can have
 * Return: 1 if tree is bst or 0 if not
 */
int helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (min > tree->n || max < tree->n)
		return (0);

	if (helper(tree->left, min, tree->n - 1))
	{
		if (helper(tree->right, tree->n + 1, max))
			return (1);
	}
	return (0);
}
