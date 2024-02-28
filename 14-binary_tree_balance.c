#include "binary_trees.h"

size_t b_tree_height(const binary_tree_t *tree);
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance factor of the tree, otherwise 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (b_tree_height(tree->left) - b_tree_height(tree->right));
}

/**
 * b_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree, otherwise 0
 */
size_t b_tree_height(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);
	l_height = tree->left ? 1 + b_tree_height(tree->left) : 1;
	r_height = tree->right ? 1 + b_tree_height(tree->right) : 1;

	return (l_height >= r_height ? l_height : r_height);
}
