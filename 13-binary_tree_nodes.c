#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodeswith at least 1 child in a binary tree
 * @tree: pointer to root node of the tree to count number of nodes from
 *
 * Return: number of nodes, 0 otherwise
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	if (tree->left != NULL || tree->right != NULL)
		return (binary_tree_nodes(tree->left) +
				binary_tree_nodes(tree->right) + 1);

	else
		return (binary_tree_nodes(tree->left) +
				binary_tree_nodes(tree->right));
}
