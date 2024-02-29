#include "binary_trees.h"

bst_t *bst_min(bst_t *root);
/**
 * bst_remove - removes a node from a Binary Search Tree
 *
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree after removing the
 *		desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left && !root->right)
		{
			free(root);
			return (NULL);
		}
		else if (!root->left)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		temp = bst_min(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}

/**
 * bst_min - finds the node with smallest value from a Binary Search Tree
 *
 * @root: pointer to the root node of the tree
 *
 * Return: pointer to the node with smallest value
 */
bst_t *bst_min(bst_t *root)
{
	bst_t *min = root;

	while (min->left)
		min = min->left;
	return (min);
}
