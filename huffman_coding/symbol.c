#include "huffman.h"

/**
 * symbol_create - Creates a symbol struct
 * @data: Data to add to symbol
 * @freq: Frequency of symbol
 * Return: Pointer to new symbol, or NULL on Fail
 */
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *new = NULL;

	if (!data)
		return (NULL);

	new = malloc(sizeof(symbol_t));
	if (!new)
		return (NULL);
	new->data = data;
	new->freq = freq;
	return (new);
}
