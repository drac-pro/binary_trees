#include "binary_trees.h"

int is_complete_helper(const binary_tree_t *tree, size_t index, size_t size);
size_t binary_tree_size(const binary_tree_t *tree);
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);
	return (is_complete_helper(tree, 0, size));
}

/**
 * is_complete_helper - helper for binary_tree_is_complete
 *
 * @tree:  a pointer to the root node of the tree to check
 * @index: index of the node to check
 * @size: size of the binary tree
 *
 * Return: 1 if tree is complete, otherwise 0
 */
int is_complete_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);
	if (index >= size)
		return (0);
	return (is_complete_helper(tree->left, 2 * index + 1, size) &&
		is_complete_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: the size of the tree, otherwise 0;
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (0);
	size++;
	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);

	return (size);
}
