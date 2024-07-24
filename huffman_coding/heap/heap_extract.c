#include "heap.h"

static btn *is_full(btn *node);
static btn *balance(int (*cmp)(void *, void *), btn *node);

/**
 * heap_extract - Extracts a value from the heap
 * @heap: heap to extract from
 */
void *heap_extract(heap_t *heap)
{
	int *extract = NULL, *tmp_data = 0;
	btn *tmp = NULL;

	if (!heap)
		return (NULL);
	extract = (int *)heap->root->data;
	tmp = is_full(heap->root);
	if (!tmp)
	{
		for (tmp = heap->root; tmp->right; tmp = tmp->right)
			;
	}
	if (tmp)
		tmp = tmp->left;
	tmp_data = (int *)tmp->data;
	free(tmp);
	heap->root->data = (void *)tmp_data;
	balance(heap->data_cmp, heap->root);
	heap->size -= 1;
	return ((void *)extract);
}

/**
 * is_full - verifies if binary tree is full
 * @node: node to check
 * Return: NULL if Full, pointer to non-full node on fail
 */
static btn *is_full(btn *node)
{
	btn *ptr = NULL;

	if (!node || (!node->left && node->right) || (node->left && !node->right))
		return (node);
	if (!node->left && !node->right)
		return (NULL);
	ptr = is_full(node->left);
	if (ptr)
		return (ptr);
	ptr = is_full(node->right);
	if (ptr)
		return (ptr);
	return (NULL);
}

/**
 * balance - Re-balances after new node is inserted
 * @cmp: Function pointer to compare node data
 * @node: Newest node
 * Return: node that contains newest data
 */
static btn *balance(int (*cmp)(void *, void *), btn *node)
{
	int *tmp = (int *)node->data, *left = 0, *right = 0;

	
	if (node->right)
		right = (int *)node->right->data;
	if (node->left)
		left = (int *)node->left->data;
	if ((right && left && right < left) || !left)
	{
		if ((cmp(node->data, node->right->data) > 0))
		{
			node->data = (void *)right, node->right->data = (void *)tmp;
			return (balance(cmp, node->right));
		}
		return (node);
	}
	if ((right && left && left < right) || !right)
	{
		if ((cmp(node->data, node->left->data) > 0))
		{
			node->data = (void *)left, node->left->data = (void *)tmp;
			return (balance(cmp, node->left));
		}
		return (node);
	}
	else
		return (node);
}
