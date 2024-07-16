#include "graphs.h"

/**
 * breadth_first_traverse - Traverses a graph breadth first
 * @graph: graph to traverse
 * @action: function to perform on vertices
 * Return: Max Depth or ) on fail
 */
size_t breadth_first_traverse(const graph_t *graph, void (*action)(const
							  vertex_t *v, size_t depth))
{
	size_t *visited, *level, depth = 0, add = 0, pop = 0;
	vertex_t *vertex, **que;
	edge_t *edge;

	if (!graph || !graph->vertices || !action)
		return (0);
	visited = calloc(graph->nb_vertices, sizeof(size_t));
	level = calloc(graph->nb_vertices, sizeof(size_t));
	que = calloc(graph->nb_vertices + 1, sizeof(size_t *));

	visited[graph->vertices->index] = 1;
	que[add++] = graph->vertices;

	while (pop < add)
	{
		vertex = que[pop];
		action(que[pop++], level[vertex->index]);
		for (edge = que[pop - 1]->edges; edge; edge = edge->next)
		{
			if (!visited[NEXT_VERT])
			{	que[add++] = edge->dest;
				visited[NEXT_VERT] = 1;
				level[NEXT_VERT] = level[vertex->index] + 1;
			}
			if (depth < level[NEXT_VERT])
				depth = level[NEXT_VERT];
		}
	}
	free(visited), free(que), free(level);
	return (depth);
}
