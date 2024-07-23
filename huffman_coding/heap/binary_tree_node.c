#include "heap.h"

/**
 * binary_tree_node - Makes a node
 * @parent: Parent node
 * @data: data to give node
 * Return: Pointer to new node, or NULL on fail
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *new = NULL;

	new = malloc(sizeof(binary_tree_node_t));
	if (!new)
		return (NULL);
	new->parent = parent, new->data = data;
	return (new);
}
