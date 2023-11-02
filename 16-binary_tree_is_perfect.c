#include "binary_trees.h"

/**
 * _height - measures the height of a tree
 * @tree: pointer to the root node of the tree to measure height
 *
 * Return: height, otherwise 0
 */
int _height(const binary_tree_t *tree)
{
	int l_height = 0, r_height = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	if (tree->left != NULL)
		l_height = _height(tree->left);
	if (tree->right != NULL)
		r_height = _height(tree->right);
	if (l_height >= r_height)
		return (l_height + 1);
	else
		return (r_height + 1);
}

/**
 * binary_tree_is_perfect -checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 for perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l_height = 0,r_height = 0;

	if (tree == NULL)
		return (0);
	l_height = _height(tree->left);
	r_height = _height(tree->right);
	if (l_height == r_height && binary_tree_is_perfect(tree->left))
		return (binary_tree_is_perfect(tree->right));
	return (0);
}
