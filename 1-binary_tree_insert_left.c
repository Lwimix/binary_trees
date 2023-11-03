#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as left child of another
 * @parent: pointer to node to insert the left child
 * @value: value to store in new node
 *
 * Return: pointer to created node, NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL, *temp_left = NULL;

	if (parent == NULL)
		return (NULL);
	new_node = (binary_tree_t *) malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	if (parent->left == NULL)/*There was no left node*/
		parent->left = new_node;
	else/*left node exists*/
	{
		new_node->parent = parent;
		temp_left = parent->left;
		new_node->left = temp_left;
		parent->left->parent = new_node;
		parent->left = new_node;
	}
	return (new_node);
}
