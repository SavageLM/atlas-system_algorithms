#include "heap.h"

static btn *get_last(heap_t *heap);
static btn *balance(int (*cmp)(void *, void *), btn *node);

/**
 * heap_insert - Inserts a node value data to min heap tree
 * @heap: heap to insert to
 * @data: data to give inserted node
 * Return: Pointer to node with value data, or NULL on fail
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *new = NULL, *tmp = NULL;

	if (!heap || !data)
		return (NULL);
	new = binary_tree_node(NULL, data);
	if (!new)
		return (NULL);
	if (!heap->root)
	{
		heap->root = new, heap->size += 1;
		return (new);
	}
	tmp = get_last(heap);
	if (heap->size & 1)
		tmp->left = new;
	else
		tmp->right = new;
	new->parent = tmp;
	heap->size += 1;
	return (balance(heap->data_cmp, new));
}

/**
 * get_last - retreives last node
 * @heap: Heap to navigate
 * Return: Pointer to last node
 */
static btn *get_last(heap_t *heap)
{
	unsigned long mask = 1;
	btn *node = NULL;

	for (mask <<= 63; !(mask & (heap->size + 1)); mask >>= 1)
		;
	mask >>= 1;
	for (node = heap->root; mask > 1; mask >>= 1)
		node = mask & (heap->size + 1) ? node->right : node->left;
	return (node);
}

/**
 * balance - Re-balances after new node is inserted
 * @cmp: Function pointer to compare node data
 * @node: Newest node
 * Return: node that contains newest data
 */
static btn *balance(int (*cmp)(void *, void *), btn *node)
{
	int *tmp;

	if (node->parent && (cmp(node->data, node->parent->data) < 0))
	{
		tmp = (int *)node->parent->data;
		node->parent->data = node->data;
		node->data = (void *)tmp;
		return (balance(cmp, node->parent));
	}
	return (node);
}
