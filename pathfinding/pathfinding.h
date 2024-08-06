#ifndef _PATHFINDING_H_
#define _PATHFINDING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphs.h"
#include "queues.h"

/* MACROS */
#define VISITED visit[point->y * rows + point->x]
#define SET_RIGHT next = point, next->x += 1
#define SET_BOTTOM next = point, next->y += 1
#define SET_LEFT next = point, next->x -= 1
#define SET_TOP next = point, next->y -= 1
#define POINT map[next->y][next->x]

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

/**
 * enum direction - direction point needs to move
 * @RIGHT: Move to the right
 * @BOTTOM: Move down
 * @LEFT: Move to the left
 * @TOP: Move up
 */
typedef enum directions
{
	RIGHT,
	BOTTOM,
	LEFT,
	TOP
} directions;

/* Prototypes */
queue_t *backtracking_array(char **map, int rows, int cols,
							point_t const *start, point_t const *target);
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
							vertex_t const *target);
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
						vertex_t const *target);

#endif
