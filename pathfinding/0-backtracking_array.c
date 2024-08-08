#include "pathfinding.h"

queue_t *backtrack(char **map, int rows, int cols,
					int x, int y, point_t const *target,
					queue_t *que, int *visit);

/**
 * backtracking_array - Function for finiding a path from start to target
 * @map: Read-only 2d aray
 * @rows: Num of rows
 * @cols: Num of cols
 * @start: pointer to start of path
 * @target: pointer to end of path
 * Return: pointer to que holding the path
 */
queue_t *backtracking_array(char **map, int rows, int cols,
							point_t const *start, point_t const *target)
{
	queue_t *que = NULL;
	int *visit, x = 0, y = 0;

	if (!map || !rows || !cols || !start || !target)
		return (NULL);
	que = queue_create();
	if (!que)
		return (NULL);
	/* Access: visit[y * row + x]*/
	visit = calloc((rows * cols), sizeof(int));
	if (!visit)
		return (free(que), NULL);
	x = start->x, y = start->y;
	if (!backtrack(map, rows, cols, x, y, target, que, visit))
	{
		puts("FINAL NULL");
		return (NULL);
	}
	free(visit), visit = NULL;
	return (que);
}

/**
 * backtrack - Recursive function to find path
 * @map: Read-only 2d aray
 * @rows: Num of rows
 * @cols: Num of cols
 * @x: x point to check
 * @y: y point to check
 * @target: pointer to end of path
 * @que: Que to hold the path
 * @visit: array to track if point has been visited
 * Return: pointer to que holding the path
 */
queue_t *backtrack(char **map, int rows, int cols,
					int x, int y, point_t const *target,
					queue_t *que, int *visit)
{
	point_t *point = NULL;
	/* enum directions dir; */

	if (x < 0 || x > cols - 1 || y < 0 || y > rows - 1 || map[y][x] == '1'
		|| VISITED)
		return (NULL);
	VISITED = 1;
	printf("Checking coordinates [%d, %d]\n", x, y);
	if ((x == target->x && y == target->y) ||
		backtrack(map, rows, cols, x + 1, y, target, que, visit) ||
		backtrack(map, rows, cols, x, y + 1, target, que, visit) ||
		backtrack(map, rows, cols, x - 1, y, target, que, visit) ||
		backtrack(map, rows, cols, x, y - 1, target, que, visit))
		{
			point = malloc(sizeof(point_t));
			point->x = x, point->y = y;
			queue_push_front(que, (void *)point);
			return (que);
		}
	return (NULL);
}

/**
 * valid_next - Validates point can move in direction
 * @map: Map to path
 * @point: point to move
 * @rows: number of rows
 * @cols: number of columns
 * @dir: Direction to move
 * Return: adjuested point or NULL;
 */
/* point_t *valid_next(char **map, point_t *point, int rows, int cols, int dir)
{
	point_t *next;

	next = point;
	if (dir == 0)
	{
		if (point->x + 1 < cols)
			SET_RIGHT;
		else
			return (NULL);
	}
	if (dir == 1)
	{
		if (point->y + 1 < rows)
			SET_BOTTOM;
		else
			return (NULL);
	}
	if (dir == 2)
	{
		if (point->x - 1 >= 0)
			SET_LEFT;
		else
			return (NULL);
	}
	if (dir == 3)
	{
		if (point->y - 1 >= 0)
			SET_TOP;
		else
			return (NULL);
	}
	if (POINT == '1')
		return (NULL);
	return (next);
}
 */