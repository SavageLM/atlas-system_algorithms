#include "graphs.h"

/**
 * graph_add_vertex - Adds a vertex to an existing Graph
 * @graph: Existing graph to add vertex to
 * @str: String to be placed in vertex
 * Return: Pointer to new Vertex
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *tmp = NULL, *new_vert = NULL;

	if (!graph)
		return (NULL);
	new_vert = calloc(1, sizeof(vertex_t));
	if (!new_vert)
		return (NULL);
	if (!graph->vertices)
	{
		graph->vertices = new_vert, graph->nb_vertices += 1;
		new_vert->content = strdup(str);
		return (new_vert);
	}
	for (tmp = graph->vertices; tmp->next; tmp = tmp->next)
	{
		if (!strcmp(str, tmp->content))
		{
			free(new_vert);
			return (NULL);
		}
	}
	tmp->next = new_vert;
	new_vert->content = strdup(str);
	new_vert->index = tmp->index + 1;
	new_vert->next = NULL;
	graph->nb_vertices += 1;
	return (new_vert);
}
