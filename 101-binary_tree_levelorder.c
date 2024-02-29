#include "binary_trees.h"

void levelorder(const binary_tree_t *tree, void (*func)(int), size_t level);
size_t binary_tree_height(const binary_tree_t *tree);
/**
 * binary_tree_levelorder - goes through a binary tree using
 *			level-order traversal
 *
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t max_level, level;

	if (!tree)
		return;
	max_level = binary_tree_height(tree) + 1;
	for (level = 1; level <= max_level; level++)
		levelorder(tree, func, level);
}

/**
 * levelorder - helper for binary_tree_levelorder
 *
 * @tree: pointer to root node or sub trees root node
 * @func: pointer to a function to call for each node
 * @level: current level
 */
void levelorder(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (!tree)
		return;
	if (level == 1)
		func(tree->n);
	else
	{
		levelorder(tree->left, func, level - 1);
		levelorder(tree->right, func, level - 1);
	}
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
