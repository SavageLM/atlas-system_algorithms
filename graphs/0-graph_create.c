#include "graphs.h"

/**
 * graph_create - Creates a graph and initializes elements
 * Return: created graph or NULL
 */
graph_t *graph_create(void)
{
	graph_t *new_graph = NULL;

	new_graph = calloc(1, sizeof(graph_t));
	return(!new_graph ? NULL : new_graph);
}
