#include "graphs.h"

/**
 * depth_first_traverse - Recursively traverses a graph to get largest depth
 * @graph: graph to traverse
 * @action: function to call on each visted vertex
 * Return: Largest depth, or 0 on fail
 */
size_t depth_first_traverse(const graph_t *graph,
							void (*action)(const vertex_t *v, size_t depth))
{
	size_t *visited, depth = 0;

	if (!graph || !graph->vertices || !action)
		return (0);
	visited = calloc(graph->nb_vertices, sizeof(size_t));
	depth = dft_recursive(graph->vertices, action, visited, depth);
	free(visited);
	return (depth);
}

/**
 * dft_recursive - Recursively traverses a graph depth first
 * @vertex: Pointer to the current vertex
 * @action: function to perform on each vertex
 * @visited: Array to track if a vertex has been visted
 * @depth: Depth of Current vertex
 * Return: max_depth found
 */
size_t dft_recursive(vertex_t *vertex, void (*action)(const vertex_t *v,
					size_t depth), size_t *visited, size_t depth)
{
	static size_t max_depth;
	edge_t *edge = vertex->edges;

	if (!vertex)
		return (max_depth);
	if (!visited[vertex->index])
		visited[vertex->index] = 1;
	else
		return (max_depth);
	if (max_depth < depth)
		max_depth = depth;
	action(vertex, depth);

	while (edge)
	{
		max_depth = dft_recursive(edge->dest, action, visited, depth + 1);
		edge = edge->next;
	}
	/* dft_recursive(vertex->next, action, visited, depth + 1); */
	return (max_depth);
}
