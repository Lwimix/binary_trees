#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as right child of another
 * @parent: pointer to node to insert the right child
 * @value: value to store in new node
 *
 * Return: pointer to created node, NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL, *temp_right = NULL;

	if (parent == NULL)
		return (NULL);
	new_node = (binary_tree_t *) malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	if (parent->right == NULL)/*There was no right node*/
		parent->right = new_node;
	else/*right node exists*/
	{
		temp_right = parent->right;
		new_node->right = temp_right;
		parent->right = new_node;
		new_node->parent = parent;
	}
	return (new_node);
}
