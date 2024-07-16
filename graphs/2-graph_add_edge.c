#include "graphs.h"

int assign_edge(vertex_t *start, vertex_t *end);

/**
 * graph_add_edge - Addes an Edge to existing graph
 * @graph: Graph to add edge to
 * @src: Starting point of Edge
 * @dest: End point of Edge
 * @type: Edge type
 * Return: 1 on success, else 0
 */
int graph_add_edge(graph_t *graph, const char *src, const char *dest,
					edge_type_t type)
{
	vertex_t *start = NULL, *end = NULL, *tmp;

	if (!graph || !graph->vertices || !src || !dest)
		return (0);
	for (tmp = graph->vertices; tmp; tmp = tmp->next)
	{
		if (!strcmp(src, tmp->content))
			start = tmp;
		else if (!strcmp(dest, tmp->content))
			end = tmp;
	}
	if (!start || !end)
		return (0);
	if (!assign_edge(start, end))
		return (0);
	if (type == 1)
		return (assign_edge(end, start) ? 1 : 0);
	return (1);
}

/**
 * assign_edge - creates and assigns an edge
 * @start: vertice to add an edge to
 * @end: destination of edge
 * Return: 1 on success, 0 on fail
 */
int assign_edge(vertex_t *start, vertex_t *end)
{
	edge_t *new_edge = NULL, *edge;

	new_edge = malloc(sizeof(edge_t));
	if (!new_edge)
		return (0);
	new_edge->dest = end, new_edge->next = NULL;
	if (!start->edges)
		start->edges = new_edge;
	else
	{
		for (edge = start->edges; edge->next; edge = edge->next)
			continue;
		edge->next = new_edge, start->nb_edges += 1;
	}
	return (1);
}
