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
 * binary_tree_balance - measure the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure balance factor
 *
 * Return: balance factor, otherwise 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	if (tree->left == NULL)
		return -(_height(tree->right));
	if (tree->right == NULL)
		return (_height(tree->left + 1));
	return (_height(tree->left) - _height(tree->right));
}
