#include "pathfinding.h"

/**
 * dijkstra_graph - Uses dijkstra algo to find shortest path
 * @graph: Graph to find path in
 * @start: starting vertex
 * @target: Target Vertex
 */
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
						vertex_t const *target)
{
	queue_t *que = NULL;
	int *visit;

	if (!graph || !start || !target)
		return (NULL);
	que = calloc(1, sizeof(queue_t));
	if (!que)
		return (NULL);
	visit = calloc(graph->nb_vertices, sizeof(int));
	if (!visit)
		return (free(que), NULL);
	free(visit);
	return (que);
}