#ifndef _PATHFINDING_H_
#define _PATHFINDING_H_

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphs.h"
#include "queues.h"

/* MACROS */
#define VISITED visit[y * rows + x]
#define G_VISIT visit[vert->index]
#define POINT map[next->y][next->x]
#define NEXT_VERT edge->dest->index
#define DEST edge->dest->index

/* STRUCTS */

/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
	int x;
	int y;
} point_t;

/* Prototypes */
queue_t *backtracking_array(char **map, int rows, int cols,
							point_t const *start, point_t const *target);
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
							vertex_t const *target);
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
						vertex_t const *target);

#endif
