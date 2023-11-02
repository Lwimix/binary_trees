#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a tree
 * @tree: pointer to the root node of the tree to measure size
 *
 * Return: size, otherwise 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t l_nodes = 0, r_nodes = 0, total_nodes = 0;

	if (tree == NULL)
		return (0);
	l_nodes = binary_tree_size(tree->left);
	r_nodes = binary_tree_size(tree->right);
	total_nodes = (l_nodes + r_nodes) + 1;
	return (total_nodes);
}
