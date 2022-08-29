#include "binary_trees.h"

/**
 * bst_remove - removes a node from a Binary Search Tree
 *
 * @root: pointer to the root node of the tree where
 * you will remove a node
 * @value: value to remove in the tree
 * Return: a pointer to the new root node of the tree
 * after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *successor = NULL;

	if (!root)
		return (NULL);

	bst_remove(root->left, value);
	bst_remove(root->right, value);

	if (root->n == value)
	{
		if (!root->left && !root->right)    /* case 0: No child */
			update_parent(root, NULL);
		else if (root->left && !root->right)    /* case 1: one child */
			update_parent(root, root->left);
		else if (!root->left && root->right)    /* case 1: one child */
			update_parent(root, root->right);
		else if (root->left && root->right) /* case 2: two children */
			successor = min_child(root->right, root->right->n);

		if (successor)	/* for Case 2 */
		{
			if (successor->right)
				update_parent(successor, successor->right);
			else
				update_parent(successor, NULL);

			root->n = successor->n;	/* replace root val with successor */
			free(successor);
		}
		else
			free(root);
	}
	return (root);
}

/**
 * min_child - gets the minimum child value at the right
 *
 * @node: the node to be removed
 * @min: minimum value
 * Return: the address of the minimum child value
 */
bst_t *min_child(bst_t *node, int min)
{
	bst_t *left, *right;

	if (!node)
		return (NULL);

	left = min_child(node->left, min);
	right = min_child(node->right, min);

	if (left || right)
	{
		if (left && right)
		{
			if (left->n < min)
			{
				if (left->n < right->n)
					return (left);
			}
			if (right->n < min)
			{
				if (right->n < left->n)
					return (right);
			}
			return (node);
		}
		else if (left)
		{
			if (left->n < min)
				return (left);
			return (node);
		}
		if (right->n < min)
			return (right);
		return (node);
	}
	return (node);
}

/**
 * update_parent - updates parent node to the address provided
 *
 * @node: pointer to the node to set to parent node
 * @set_add: pointer to the address to be set to parent node
 */
void update_parent(bst_t *node, bst_t *set_add)
{
	if (node->parent)
	{
		if (node->parent->left == node)
			node->parent->left = set_add;
		else
			node->parent->right = set_add;
	}

	if (set_add)
		set_add->parent = node->parent;
}
