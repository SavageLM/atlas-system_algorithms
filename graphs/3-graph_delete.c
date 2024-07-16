#include "graphs.h"

/**
 * graph_delete - Deletes a graph
 * @graph: graph to delete
 */
void graph_delete(graph_t *graph)
{
	vertex_t *tmp_vert, *del_vert;
	edge_t *tmp_edge, *del_edge;

	if (!graph)
		return;
	if (!graph->vertices)
	{
		free(graph);
		return;
	}
	tmp_vert = graph->vertices;
	while (tmp_vert)
	{
		tmp_edge = tmp_vert->edges;
		while (tmp_edge)
		{
			del_edge = tmp_edge;
			tmp_edge = tmp_edge->next;
			del_edge->dest = NULL, free(del_edge);
		}
		del_vert = tmp_vert;
		tmp_vert = tmp_vert->next;
		free(del_vert->content), del_vert->edges = NULL, free(del_vert);
	}
	free(graph);
}
