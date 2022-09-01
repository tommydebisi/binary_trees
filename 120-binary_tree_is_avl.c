#include "binary_trees.h"

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_is_bst(tree) &&
			binary_balance2(tree));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: pointer to the root node
 * Return: 1 if bst or 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{

	if (!tree)
		return (0);

	return (helper(tree, INT_MIN, INT_MAX));
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

/**
 * binary_height2 - measures the height of a binary tree
 *
 * @tree:  pointer to the root node of the tree to measure the height
 *
 * Return: the height of the binary tree
 */
int binary_height2(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (-1);

	left = 1 + binary_height2(tree->left);
	right = 1 + binary_height2(tree->right);

	if (left < right)
		return (right);
	else
		return (left);
}

/**
 * binary_balance2 - checks if each nodes
 * of a binary tree are balanced
 *
 * @tree: pointer to the root node of the
 * tree to measure the balance factor
 *
 * Return: the balance factor of the tree or 0 if tree is not balanced
 */
int binary_balance2(const binary_tree_t *tree)
{
	int balanceFactor;

	if (!tree)
		return (1);

	balanceFactor = binary_height2(tree->left) - binary_height2(tree->right);

	if (balanceFactor < 0)
		balanceFactor *= -1;

	if (balanceFactor > 1)
		return (0);

	/* check recursively if each nodes are balanced */
	return (binary_balance2(tree->left) &&
			binary_balance2(tree->right));
}
