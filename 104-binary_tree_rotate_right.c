#include "binary_trees.h"

/**
 * binary_tree_rotate_right - right-rotation on a binary tree
 *
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (!tree)
		return (NULL);
	if (!tree->left)
		return (NULL);
	temp = tree->left;
	tree->left = temp->right;
	if (temp->right)
		temp->right->parent = tree;
	temp->parent = tree->parent;
	if (!tree->parent)
	{
		temp->right = tree;
		tree->parent = temp;
		return (temp);
	}
	else if (tree == tree->parent->right)
		tree->parent->right = temp;
	else
		tree->parent->left = temp;
	temp->right = tree;
	tree->parent = temp;

	return (temp);
}
