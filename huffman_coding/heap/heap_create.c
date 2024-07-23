#include "heap.h"

/**
 * heap_create - Creates a heap
 * @data_cmp: function to add to created heap
 * Return: Pointer to new Heap or NULL on fail
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *new = NULL;

	new = malloc(sizeof(heap_t));
	if (!new || !data_cmp)
		return (NULL);
	new->root = NULL, new->size = 0;
	new->data_cmp = data_cmp;
	return (new);
}
