#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 *
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (!tree)
		return (NULL);
	if (!tree->right)
		return (NULL);
	temp = tree->right;
	tree->right = temp->left;
	if (temp->left)
		temp->left->parent = tree;
	temp->parent = tree->parent;
	if (!tree->parent)
	{
		temp->left = tree;
		tree->parent = temp;
		return (temp);
	}
	else if (tree == tree->parent->left)
		tree->parent->left = temp;
	else
		tree->parent->right = temp;
	temp->left = tree;
	tree->parent = temp;

	return (temp);
}
