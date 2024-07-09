#include "rb_trees.h"

int count_blk(rb_tree_t *node, const int count);
int is_bst(const rb_tree_t *tree, const int *val);

/**
 * rb_tree_is_valid - determines if a rb tree is valid
 * @tree: tree to verify
 * Return: 1 if valid, 0 otherwise
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (!tree->parent && tree->color != 1)
		return (0);
	if (!tree || (tree->color != 0 && tree->color != 1))
		return (0);
	if (tree->color == 0 && ((tree->left && tree->left->color == 0) ||
		(tree->right && tree->right->color == 0)))
		return (0);
	if (count_blk(tree->left, 0) != count_blk(tree->right, 0))
		return (0);
	if (!is_bst(tree->left, &tree->n) || !is_bst(tree->right, &tree->n))
		return (0);
	if (tree->left && !rb_tree_is_valid(tree->left))
		return (0);
	if (tree->right && !rb_tree_is_valid(tree->right))
		return (0);
	return (1);
}

/**
 * count_blk - Counts the number of black nodes in a tree
 * @node: node to check
 * @count: number of black nodes
 */
int count_blk(rb_tree_t *node, int count)
{
	int left = 0, right = 0;

	if (!node)
		return (count);
	if (node->color == 1)
		count += 1;
	left = count_blk(node->left, count);
	right = count_blk(node->right, count);
	return (left == right ? count : 0);
}

/**
 * is_bst - Function for checking if a tree is a BST
 * @tree: Tree to check
 * @val: value of root
 * Return: 1 if tree is BST, 0 if not
 */
int is_bst(const rb_tree_t *tree, const int *val)
{
	if (!tree)
		return (1);

	if (!is_bst(tree->left, val) || &tree->n <= val)
		return (0);
	val = &tree->n;
	return (is_bst(tree->right, val));
}
