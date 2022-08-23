#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 *
 * @tree: Pointer to the root of the node to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	/* using post ordeer traversal */
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
