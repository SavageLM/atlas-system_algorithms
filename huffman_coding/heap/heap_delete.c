#include "heap.h"

/**
 * heap_delete - Deletes a heap
 * @heap: heap to delete
 * @free_data: function to call on each node to free contents
 */
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (!heap)
		return;
	get_outta_here(heap->root, free_data);
	free(heap);
}

/**
 * get_outta_here - Frees a tree recursively
 * @node: Node to free
 * @free_data: function to call on all nodes
 */
get_outta_here(btn *node, void (*free_data)(void *))
{
	if (!node)
		return;
	get_outta_here(node->left, free_data);
	get_outta_here(node->right, free_data);
	if (free_data)
		free_data(node->data);
	free(node);
}