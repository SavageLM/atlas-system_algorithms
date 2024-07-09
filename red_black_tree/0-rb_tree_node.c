#include "rb_trees.h"

/**
 * rb_tree_node - Adds a Node to a tree
 * @parent: Parent of the node to add
 * @value: value to add to node
 * @color: color of the node to add
 * Return: pointer to new node or NULL
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *add = NULL;

	add = malloc(sizeof(rb_tree_t));
	if (!add)
		return (NULL);
	add->parent = parent;
	add->n = value, add->color = color;
	add->left = NULL, add->right = NULL;

	return (add);
}
