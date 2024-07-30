#include "huffman.h"
#include "heap.h"

void get_huff(btn *node, char *huff_code, int pos);
void print_huff(symbol_t *symb, char *huff_code);

/**
 * huffman_codes - Generates a Huffman code for each character
 * @data: Array of data for symbols
 * @freq: Array of int frenquencies for symbols
 * @size: size of arrays
 * Return: i on success, 0 on fail
 */
int huffman_codes(char *data, size_t *freq, size_t size)
{
	btn *huff = NULL;
	char huff_code[10];
	int pos = 0;

	if (!data || !freq || !size)
		return (0);
	huff = huffman_tree(data, freq, size);
	if (!huff)
		return (0);
	get_huff(huff, huff_code, pos);
	return (1);
}

/**
 * get_huff - Recursively generate the huffman code of a symbol
 * @node: Root node of huffman tree
 * @huff_code: array to store huff code
 * @pos: position in huff_code
 */
void get_huff(btn *node, char *huff_code, int pos)
{
	if (!node)
		return;
	if (node->left)
		huff_code[pos] = '0', get_huff(node->left, huff_code, pos + 1);
	if (node->right)
		huff_code[pos] = '1', get_huff(node->right, huff_code, pos + 1);
	if (!node->left && !node->right)
		huff_code[pos + 1] = '\0', print_huff((symbol_t *)node->data, huff_code);
}

/**
 * print_huff - Prints the huffman code of a char
 * @symb: Symbol containing the char data
 * @huff_code: array holding the huffman code
 */
void print_huff(symbol_t *symb, char *huff_code)
{
	int i = 0;

	printf("%c: ",symb->data);
	for (i = 0; huff_code[i] != '\0'; i++)
		printf("%c", huff_code[i]);
	putchar('\n');
}
