#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 *
 * @tree: double pointer to the root node of the
 * BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *future = *tree;

	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	while (future)
	{
		if (value == future->n)
			return (NULL);

		if (value < future->n)	/* value goes left */
		{
			if (future->left)
				future = future->left;
			else	/* space to insert new node */
			{
				future->left = binary_tree_node(future, value);
				if (!future->left)
					return (NULL);
				return (future->left);
			}
		}
		else	/* value goes right */
		{
			if (future->right)
				future = future->right;
			else	/* space to insert new node */
			{
				future->right = binary_tree_node(future, value);
				if (!future->right)
					return (NULL);
				return (future->right);
			}
		}
	}
	return (NULL);
}
