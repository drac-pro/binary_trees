#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 *
 * @tree: pointer to the node to measure the depth
 *
 * Return: depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	binary_tree_t *temp = tree->parent;
	size_t depth = 0;

	if (!tree)
		return (0);
	while (temp)
	{
		depth += 1;
		temp = temp->parent;
	}
	return (depth);
}
