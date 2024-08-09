#include "pathfinding.h"

int get_distance(vertex_t const *start, vertex_t const *target, graph_t *graph,
				int *visit, int *dist, vertex_t **prev);

/**
 * dijkstra_graph - Uses dijkstra algo to find shortest path
 * @graph: Graph to find path in
 * @start: starting vertex
 * @target: Target Vertex
 * Return: Que holding path or NULL
 */
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
						vertex_t const *target)
{
	queue_t *que = NULL;
	int *visit, *dist;
	vertex_t **prev, *vert = NULL;
	size_t i = 0;

	if (!graph || !start || !target)
		return (NULL);
	que = calloc(1, sizeof(queue_t));
	if (!que)
		return (NULL);
	visit = calloc(graph->nb_vertices, sizeof(int));
	if (!visit)
		return (free(que), NULL);
	dist = calloc(graph->nb_vertices, sizeof(int));
	if (!dist)
		return (free(visit), free(que), NULL);
	prev = calloc(graph->nb_vertices, sizeof(vertex_t *));
	if (!prev)
		return (free(visit), free(que), free(dist), NULL);
	/* Setting all indices in dist to int max */
	for (i = 0; i < graph->nb_vertices; i++)
		dist[i] = INT_MAX;
	if (!get_distance(start, target, graph, visit, dist, prev))
	{
		free(prev), free(dist), free(visit), free(que);
		visit = NULL, dist = NULL, prev = NULL, que = NULL;
		return (NULL);
	}
	for (vert = prev[target->index]; prev[vert->index]; vert = prev[vert->index])
		queue_push_front(que, strdup(vert->content));
	queue_push_front(que, strdup(start->content));
	queue_push_back(que, strdup(target->content));

	free(prev), free(dist), free(visit);
	visit = NULL, dist = NULL, prev = NULL;
	return (que);
}

/**
 * get_distance - Calculates distance from Start
 * @start: starting node
 * @target: Target vertex
 * @graph: Graph to path
 * @visit: array to track if a node has been visited
 * @dist: array to track distance from Start
 * @prev: array of pointer to track path
 * Return: 1 on Success, 0 on fail.
 */
int get_distance(vertex_t const *start, vertex_t const *target, graph_t *graph,
				int *visit, int *dist, vertex_t **prev)
{
	int min_dist = INT_MAX;
	vertex_t *vert = NULL, *node = NULL;
	edge_t *edge = NULL;

	dist[start->index] = 0;

	while (node != target)
	{
		min_dist = INT_MAX, node = NULL;
		for (vert = graph->vertices; vert; vert = vert->next)
		{
			if (!visit[vert->index] && dist[vert->index] < min_dist)
				min_dist = dist[vert->index], node = vert;
		}
		if (!node)
			break;
		visit[node->index] = 1;
		printf("Checking %s, distance from %s is %d\n", node->content,
				start->content, dist[node->index]);
		for (edge = node->edges; edge; edge = edge->next)
		{
			if (!visit[edge->dest->index] && dist[edge->dest->index] >
				min_dist + edge->weight)
			{
				dist[edge->dest->index] = min_dist + edge->weight;
				prev[edge->dest->index] = node;
			}
		}
	}
	if (!node || node != target)
		return (0);
	return (1);
}
