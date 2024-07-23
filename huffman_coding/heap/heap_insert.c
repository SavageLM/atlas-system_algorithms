#include "heap.h"

/**
 * heap_insert - Inserts a node value data to min heap tree
 * @heap: heap to insert to
 * @data: data to give inserted node
 * Return: Pointer to node with value data, or NULL on fail
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *new = NULL, *ptr = NULL, *tmp = NULL;

	if (!heap || !data)
		return (NULL);
	if (!heap->root)
	{
		new = binary_tree_node(NULL, data);
		if (!new)
			return (NULL);
		heap->root = new, heap->size += 1;
		return (new);
	}
	tmp = is_full(heap->root);
	if (!tmp)
	{
		for (tmp = heap->root; tmp->left; tmp = tmp->left)
			;
		new = binary_tree_node(tmp, data);
		if (!new)
			return (NULL);
	}
	else
	{
		new = binary_tree_node(tmp, data);
		if (!new)
			return (NULL);
	}
	return (balance(heap->data_cmp, new));
}

/**
 * is_full - verifies if binary tree is full
 * @node: node to check
 * Return: NULL if Full, pointer to non-full node on fail
 */
btn *is_full(const btn *node)
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
btn *balance(int (*cmp)(void *, void *), btn *node)
{
	btn *tmp = NULL;

	if (cmp(node->data, node->parent->data) < 0)
	{
		tmp = node->parent;
		node->parent->data = node->data;
		node->data = tmp->data;
		return (balance(cmp, node->parent));
	}
	return (node);
}
