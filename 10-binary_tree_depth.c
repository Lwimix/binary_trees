#include "binary_trees.h"

/**
 * binary_tree_depth - measures depth of a node in a binary tree
 * @tree: pointer to node to measure depth
 *
 * Return: the depth value, 0 for failure
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	binary_tree_t *temp = NULL;

	if (tree == NULL)
		return (0);
	temp = (binary_tree_t *)tree;
	while (temp->parent != NULL)
	{
		depth += 1;
		temp = temp->parent;
	}
	return (depth);
}
