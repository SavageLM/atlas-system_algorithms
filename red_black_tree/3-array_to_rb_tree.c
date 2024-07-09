#include "rb_trees.h"

/**
 * array_to_rb_tree - Creates a Red Black tree from an array
 * @array: array to use
 * @size: size of array
 * Return: pointer to new tree or NULL
 */
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	size_t i = 0;
	rb_tree_t *root = NULL;

	if (!array)
		return (NULL);
	if (!root)
		root = binary_tree_node(NULL, array[i]), i++;

	for (; i < size; i++)
		if (!rb_tree_insert(&root, array[i]))
			continue;

	return (root);
}