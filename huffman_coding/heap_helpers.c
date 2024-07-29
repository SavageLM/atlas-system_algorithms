#include "huffman.h"
#include "heap.h"

/**
 * get_last_ext - retreives last node for extraction function
 * @heap: Heap to navigate
 * Return: Pointer to last node
 */
btn *get_last_ext(heap_t *heap)
{
	unsigned long mask = 1;
	btn *node = NULL;

	for (mask <<= 63; !(mask & heap->size); mask >>= 1)
		;
	mask >>= 1;
	for (node = heap->root; mask > 1; mask >>= 1)
		node = mask & heap->size ? node->right : node->left;
	return (node);
}

/**
 * get_last_ins - retreives last node for Insert Function
 * @heap: Heap to navigate
 * Return: Pointer to last node
 */
btn *get_last_ins(heap_t *heap)
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
 * balance_ins - Re-balances after new node is inserted
 * @cmp: Function pointer to compare node data
 * @node: Newest node
 * Return: node that contains newest data
 */
btn *balance_ins(int (*cmp)(void *, void *), btn *node)
{
	int *tmp;

	if (node->parent && cmp(SYMBOL, P_SYMBOL))
	{
		tmp = (int *)node->parent->data;
		node->parent->data = node->data;
		node->data = (void *)tmp;
		return (balance_ins(cmp, node->parent));
	}
	return (node);
}

/**
 * balance_ext - Re-balances after a node is extracted
 * @cmp: Function pointer to compare node data
 * @node: Newest node
 * Return: node that contains newest data
 */
btn *balance_ext(int (*cmp)(void *, void *), btn *node)
{
	int *tmp;

	if (RIGHT && LEFT)
	{
		if (!cmp(SYMBOL_L, SYMBOL_R))
		{
			if (cmp(SYMBOL_R, SYMBOL))
			{
				tmp = (int *)RIGHT->data;
				RIGHT->data = node->data;
				node->data = (void *)tmp;
				balance_ext(cmp, RIGHT);
			}
			return (node);
		}
		else
		{
			if (cmp(SYMBOL_L, SYMBOL))
			{
				tmp = (int *)LEFT->data;
				LEFT->data = node->data;
				node->data = (void *)tmp;
				balance_ext(cmp, LEFT);
			}
			return (node);
		}
	}
	if (!RIGHT && LEFT)
	{
		if (cmp(SYMBOL_L, SYMBOL))
		{
			tmp = (int *)LEFT->data;
			LEFT->data = node->data;
			node->data = (void *)tmp;
			balance_ext(cmp, LEFT);
		}
			return (node);
	}
	return (node);
}
