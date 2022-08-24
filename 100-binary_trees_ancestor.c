#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 * or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	size_t left = binary_tree_depth(first), right = binary_tree_depth(second);

	if (!first || !second)
		return (NULL);

	if (left < right)
	{
		while (right != left)
		{
			second = second->parent;
			right--;
		}
	}
	else if (right < left)
	{
		while (left != right)
		{
			first = first->parent;
			left--;
		}
	}

	if (left == right)
	{
		while ((first->n != second->n) && (first->parent && second->parent))
		{
			first = first->parent;
			second = second->parent;
		}

		if (first->n == second->n)
			return ((binary_tree_t *)first);
	}
	return (NULL);
}

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
