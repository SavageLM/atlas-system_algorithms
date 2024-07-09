#include "rb_trees.h"

/**
 * rb_tree_insert - Inserts a node into the tree
 * @tree: Tree to insert node into
 * @value: value of node to insert
 * Return: pointer to new node or NULL
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *new_node = NULL;

	if (!*tree)
	{
		*tree = rb_tree_node(NULL, value, 1);
		return (*tree);
	}
	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
		{
			new_node = (rb_tree_node(*tree, value, 0));
			(*tree)->left = new_node;
			return (new_node);
		}
		else
			new_node = rb_tree_insert(&(*tree)->left, value);
	}
	else if (value > (*tree)->n)
	{
		if (!(*tree)->right)
		{
			new_node = (rb_tree_node(*tree, value, 0));
			(*tree)->right = new_node;
			return (new_node);
		}
		else
			new_node = rb_tree_insert(&(*tree)->right, value);
	}
	else
		return (NULL);
	return (new_node);
}
