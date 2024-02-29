#include "binary_trees.h"
#include <limits.h>

int isBTSHelper(const binary_tree_t *tree, int min, int max);
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int min = INT_MIN, max = INT_MAX;

	if (!tree)
		return (0);

	return (isBTSHelper(tree, min, max));
}

/**
 * isBTSHelper - helper function to check if a subtree is a BST
 *
 * @tree: pointer to current tree node
 * @min: smallest possible value
 * @max: largest possible value
 *
 * Return: 1 if tree is a valid BST, otherwise 0
 */
int isBTSHelper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (isBTSHelper(tree->left, min, tree->n) &&
		isBTSHelper(tree->right, tree->n, max));
}
