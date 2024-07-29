#include "huffman.h"
#include "heap.h"

/**
 * huffman_tree - Builds a huffman tree from a priority queue
 * @data: Array holding the data for the symbol
 * @freq: Array holding the frequencies of the symbols
 * @size: size of the data and freq arrays
 * Return: Root node of huffman tree
 */
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
	heap_t *prio_que = NULL;
	btn *node = NULL;

	if (!data || !freq || !size)
		return (NULL);
	prio_que = huffman_priority_queue(data, freq, size);
	if (!prio_que)
		return (NULL);
	while (prio_que->size > 1)
	{
		if (!huffman_extract_and_insert(prio_que))
			return (NULL);
	}
	node = heap_extract(prio_que);
	heap_delete(prio_que);
	return (node);
}
