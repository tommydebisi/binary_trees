#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is perfect and 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height = 0;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);
	return (bin_is_perfect(tree, height));
}

/**
 * bin_is_perfect - checks if a binary tree is perfect with a height
 *
 * @tree: pointer to the root node of the tree to check
 * @count: the current height of the tree
 * Return: 1 if tree is perfect or 0 if not
 */
int bin_is_perfect(const binary_tree_t *tree, int count)
{
	int left = 0, right = 0, height = 0;

	if (!tree)
		return (0);

	height = count - 1;
	left = bin_is_perfect(tree->left, height);
	right = bin_is_perfect(tree->right, height);

	if (!left && !right && !count) /* leaf node */
	{
		if ((!tree->left && !tree->right && !count))
			return (1);
		else if ((tree->left && tree->right))
			return (1);
		return (0);
	}
	else if (!left || !right)	/* we're past the leaf node */
		return (0);
	return (1);	/* two children are present */
}

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
