#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "heap.h"

/* MACROS */

#define SYMBOL ((btn *)node->data)->data
#define SYMBOL_L ((btn *)node->left->data)->data
#define SYMBOL_R ((btn *)node->right->data)->data
#define P_SYMBOL ((btn *)node->parent->data)->data
#define FREQUENCY(x) ((symbol_t *)(x))->freq

/* Structs */

/**
 * struct symbol_s - Stores a char and its associated frequency
 *
 * @data: The character
 * @freq: The associated frequency
 */
typedef struct symbol_s
{
	char data;
	size_t freq;
} symbol_t;

/* Prototypes */
btn *get_last_ext(heap_t *heap);
btn *get_last_ins(heap_t *heap);
btn *balance_ins(int (*cmp)(void *, void *), btn *node);
btn *balance_ext(int (*cmp)(void *, void *), btn *node);

symbol_t *symbol_create(char data, size_t freq);
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size);
int huffman_extract_and_insert(heap_t *priority_queue);
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size);
int huffman_codes(char *data, size_t *freq, size_t size);


#endif
