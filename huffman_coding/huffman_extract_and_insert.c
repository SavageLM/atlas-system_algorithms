#include "huffman.h"
#include "heap.h"
#include "heap_helpers.c"

static int cmp(void *f1, void *f2);
static void *huffman_extract(heap_t *heap);
static binary_tree_node_t *huffman_insert(heap_t *heap, void *data);

/**
 * huffman_extract_and_insert - Builds a Huffman tree by extract 2 insert 1
 * @priority_queue: Queue to use to build Huffman tree
 * Return: 1 on success, 0 on fail
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
	btn *left, *right, *new_node = NULL;
	symbol_t *sym_l, *sym_r, *new_sym = NULL;

	if (!priority_queue || !priority_queue->root)
		return (0);
	priority_queue->data_cmp = cmp;
	left = huffman_extract(priority_queue);
	right = huffman_extract(priority_queue);
	sym_l = (symbol_t *)left->data;
	sym_r = (symbol_t *)right->data;
	new_sym = symbol_create((char)-1, sym_l->freq + sym_r->freq);
	if (!new_sym)
		return (0);
	new_node = binary_tree_node(NULL, (void *)new_sym);
	if (!new_node)
		return (0);
	left->parent = new_node, right->parent = new_node;
	new_node->left = left, new_node->right = right;
	if (!huffman_insert(priority_queue, (void *)new_node))
		return (0);
	return (1);
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
 * huffman_extract - Extracts a value from the heap
 * @heap: heap to extract from
 * Return: extracted data, or NULL on Fail
 */
static void *huffman_extract(heap_t *heap)
{
	int *extract = NULL, *tmp_data = 0;
	btn *tmp = NULL, *node;

	if (!heap)
		return (NULL);
	extract = (int *)heap->root->data;
	if (heap->size == 1)
	{
		free(heap->root);
		heap->root = NULL;
		heap->size -= 1;
		return ((void *)extract);
	}
	tmp = get_last_ext(heap);
	if ((heap->size - 1) & 1)
		node = tmp->left, tmp->left = NULL;
	else
		node = tmp->right, tmp->right = NULL;
	tmp_data = (int *)node->data;
	free(node);
	heap->root->data = (void *)tmp_data;
	balance_ext(heap->data_cmp, heap->root);
	heap->size -= 1;
	return ((void *)extract);
}

/**
 * huffman_insert - Inserts a node value data to min heap tree
 * @heap: heap to insert to
 * @data: data to give inserted node
 * Return: Pointer to node with value data, or NULL on fail
 */
static binary_tree_node_t *huffman_insert(heap_t *heap, void *data)
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
	tmp = get_last_ins(heap);
	if (heap->size & 1)
		tmp->left = new;
	else
		tmp->right = new;
	new->parent = tmp;
	heap->size += 1;
	return (balance_ins(heap->data_cmp, new));
}
