#include "binary_trees.h"
#include <limits.h>

int is_avlHelper(const binary_tree_t *tree, int min, int max);
size_t binary_tree_height(const binary_tree_t *tree);
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_avlHelper(tree, INT_MIN, INT_MAX));
}

/**
 * is_avlHelper - helper function for binary_tree_is_avl
 *
 * @tree: pointer to the root node of the tree
 * @min: minimum value
 * @max: maximum value
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int is_avlHelper(const binary_tree_t *tree, int min, int max)
{
	int l_height, r_height, d;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	l_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	d = l_height - r_height;

	if ((d * d) > 1)
		return (0);

	return (is_avlHelper(tree->left, min, tree->n - 1) &&
		is_avlHelper(tree->right, tree->n + 1, max));
}
/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree, otherwise 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);
	l_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (l_height >= r_height ? l_height : r_height);
}
