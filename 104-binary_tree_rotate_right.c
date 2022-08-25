#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 *
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (!tree)
		return (NULL);

	if (tree->parent)
	{
		if (tree->parent->left == tree)
		{
			tree->parent->left = tree->left;
			tree->left->parent = tree->parent;
		}
		else
		{
			tree->parent->right = tree->left;
			tree->left->parent = tree->parent;
		}
	}
	else
		tree->left->parent = NULL;

	tree->parent = tree->left;
	tree->left = tree->left->right;
	tree->left->parent = tree;
	tree->parent->right = tree;
	return (tree->parent);
}
