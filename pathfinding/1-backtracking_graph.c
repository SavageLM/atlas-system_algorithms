#include "pathfinding.h"

queue_t *pathfinder(vertex_t const *vert, vertex_t const *target, queue_t *que,
					int *visit);

/**
 * backtracking_graph - Find a path with backtracking in graphs
 * @graph: graph to back track through
 * @start: starting vertex
 * @target: Target Vertex
 * Return: Queue containing the path, or NULL
 */
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
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
	pathfinder(start, target, que, visit);
	free(visit);
	return (que);
}

/**
 * pathfinder - FInds the path to target
 * @vert: Vertex to check
 * @target: Target to look for
 * @que: que to hold the path
 * @visit: array to track if a vert has been visited
 * Return: que holding path, or NULL
 */
queue_t *pathfinder(vertex_t const *vert, vertex_t const *target, queue_t *que,
					int *visit)
{
	edge_t *edge = vert->edges;

	if (!vert)
		return (NULL);
	if (G_VISIT)
		return (NULL);
	printf("Checking %s\n", vert->content);
	G_VISIT = 1;
	if (!strcmp(vert->content, target->content))
	{

		if (queue_push_front(que, strdup(vert->content)))
			return (que);
	}

	while (edge)
	{
		if (pathfinder(edge->dest, target, que, visit))
		{
			if (queue_push_front(que, strdup(vert->content)))
				return (que);
		}
		edge = edge->next;
	}
	return (NULL);
}
