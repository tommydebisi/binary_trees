#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: a pointer to the root node of the created BST,
 * or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *tree_head = NULL;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
		bst_insert(&tree_head, array[i]);

	return (tree_head);
}
