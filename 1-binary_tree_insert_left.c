#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 *
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node (SUCCESS) or NULL (FAILURE)
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *temp;

	if (!parent)
		return (NULL);
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);
	if (!parent->left)
		parent->left = new_node;
	else
	{
		temp = parent->left;
		parent->left = new_node;
		new_node->left = temp;
		temp->parent = new_node;
	}
	return (new_node);
}
