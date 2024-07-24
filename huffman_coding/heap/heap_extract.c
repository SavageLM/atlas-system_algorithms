#include "heap.h"

static btn *get_last(heap_t *heap);
static btn *balance(int (*cmp)(void *, void *), btn *node);

/**
 * heap_extract - Extracts a value from the heap
 * @heap: heap to extract from
 * Return: extracted data, or NULL on Fail
 */
void *heap_extract(heap_t *heap)
{
	int *extract = NULL, *tmp_data = 0;
	btn *tmp = NULL;

	if (!heap)
		return (NULL);
	extract = (int *)heap->root->data;
	if (heap->size == 1)
	{
		free(heap->root);
		return ((void *)extract);
	}
	tmp = get_last(heap);
	if (tmp->parent->left == tmp)
		tmp->parent->left = NULL;
	else
		tmp->parent->right = NULL;
	tmp_data = (int *)tmp->data;
	free(tmp);
	heap->root->data = (void *)tmp_data;
	balance(heap->data_cmp, heap->root);
	heap->size -= 1;
	return ((void *)extract);
}

/**
 * get_last - retreives last node
 * @heap: Heap to navigate
 * Return: Pointer to last node
 */
static btn *get_last(heap_t *heap)
{
	div_t results;
	unsigned long size = (unsigned long)heap->size;
	btn *node = heap->root;

	while (size >= 2)
	{
		results = div(size, 2);
		if (results.rem == 1)
			node = node->left;
		else
			node = node->right;
		size = results.quot;
	}

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

	if (RIGHT && LEFT)
	{
		if (cmp(LEFT->data, RIGHT->data) > 0)
		{
			if (cmp(RIGHT->data, node->data) < 0)
			{
				tmp = (int *)RIGHT->data;
				RIGHT->data = node->data;
				node->data = (void *)tmp;
				balance(cmp, RIGHT);
			}
			return (node);
		}
		else
		{
			if (cmp(LEFT->data, node->data) < 0)
			{
				tmp = (int *)LEFT->data;
				LEFT->data = node->data;
				node->data = (void *)tmp;
				balance(cmp, LEFT);
			}
			return (node);
		}
	}
	if (!RIGHT && LEFT)
	{
		if (cmp(LEFT->data, node->data) < 0)
		{
			tmp = (int *)LEFT->data;
			LEFT->data = node->data;
			node->data = (void *)tmp;
			balance(cmp, LEFT);
		}
			return (node);
	}
	return (node);
}
