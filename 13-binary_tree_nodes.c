#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 *
 * @tree: pointer to the root node of the tree to count the number of nodes
 *
 * Return: number of parent nodes, otherwise 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t parent_nodes = 0;

	if (!tree)
		return (0);
	if (tree->left || tree->right)
		parent_nodes += 1;
	parent_nodes += binary_tree_nodes(tree->left);
	parent_nodes += binary_tree_nodes(tree->right);

	return (parent_nodes);
}
