#include "huffman.h"
#include "heap.h"

static int cmp(void *f1, void *f2);
static btn *get_last(heap_t *heap);
static btn *balance(int (*cmp)(void *, void *), btn *node);


/**
 * huffman_priority_queue - Function to create a priority queue
 * @data: Array of characters
 * @freq: Array of ints representing the frequency of a character
 * @size: Size of data and freq arrays
 * Return: Pointer to priority queue
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	heap_t *heap = NULL;
	symbol_t *symb = NULL;
	btn *node = NULL, *nest = NULL, *tmp;
	size_t i = 0;

	if (!data || !freq || !size)
		return (NULL);
	heap = heap_create(cmp);
	if (!heap)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		symb = symbol_create(data[i], freq[i]);
		if (!symb)
			return (free(heap), NULL);
		nest = binary_tree_node(NULL, (void *)symb);
		if (!nest)
			return (free(symb), free(heap), NULL);
		node = binary_tree_node(NULL, (void *)nest);
		if (!node)
			return (free(symb), free(nest), free(heap), NULL);
		if (!heap->root)
			heap->root = node, heap->size++;
		else
			{
				tmp = get_last(heap);
				if (heap->size & 1)
					tmp->left = node;
				else
					tmp->right = node;
				node->parent = tmp;
				heap->size++;
				balance(heap->data_cmp, node);
			}
	}
	return (heap);
}

/**
 * cmp - Compares two frequencies
 * @f1: frequency 1
 * @f2: frequency 2
 * Return: 1 or 0
 */
static int cmp(void *f1, void *f2)
{
	return (FREQUENCY(f1) < FREQUENCY(f2) ? 1 : 0);
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

	if (node->parent && cmp(SYMBOL, P_SYMBOL))
	{
		tmp = (int *)node->parent->data;
		node->parent->data = node->data;
		node->data = (void *)tmp;
		return (balance(cmp, node->parent));
	}
	return (node);
}
