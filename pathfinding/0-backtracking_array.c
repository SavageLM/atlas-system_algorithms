#include "pathfinding.h"

queue_t *backtrack(char **map, int rows, int cols,
					point_t *point, point_t const *target,
					queue_t *que, int *visit);
point_t *valid_next(char **map, point_t *point, int rows, int cols, int dir);

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
	point_t *tmp = NULL;
	int *visit;

	if (!map || !rows || !cols || !start || !target)
		return (NULL);
	que = queue_create();
	if (!que)
		return (NULL);
	/* Access: visit[y * row + x]*/
	visit = calloc((rows * cols), sizeof(int));
	if (!visit)
		return (NULL);
	tmp = malloc(sizeof(point_t));
	if (!tmp)
		return (NULL);
	tmp->x = start->x, tmp->y = start->y;
	if (!backtrack(map, rows, cols, tmp, target, que, visit))
	{
		puts("FINAL NULL");
		return (NULL);
	}
	return (que);
}

/**
 * backtrack - Recursive function to find path
 * @map: Read-only 2d aray
 * @rows: Num of rows
 * @cols: Num of cols
 * @point: point to check
 * @target: pointer to end of path
 * @que: Que to hold the path
 * @visit: array to track if point has been visited
 * Return: pointer to que holding the path
 */
queue_t *backtrack(char **map, int rows, int cols,
					point_t *point, point_t const *target,
					queue_t *que, int *visit)
{
	int x = point->x, y = point->y;
	point_t *tmp;
	enum directions dir;

	if (VISITED)
		return (NULL);
	printf("Checking coordinates [%d, %d]\n", point->x, point->y);

	if (x == target->x && y == target->y)
	{
		if (queue_push_front(que, (void *)point))
			return (que);
	}
	VISITED = 1;
	dir = RIGHT, tmp = valid_next(map,point, rows, cols, dir);
	if (tmp && backtrack(map, rows, cols, tmp, target, que, visit))
	{
		if (queue_push_front(que, (void *)point))
			return (que);
	}
	dir = BOTTOM, tmp = valid_next(map,point, rows, cols, dir);
	if (tmp && backtrack(map, rows, cols, tmp, target, que, visit))
	{
		if (queue_push_front(que, (void *)point))
			return (que);
	}
	dir = LEFT, tmp = valid_next(map,point, rows, cols, dir);
	if (tmp && backtrack(map, rows, cols, tmp, target, que, visit))
	{
		if (queue_push_front(que, (void *)point))
			return (que);
	}
	dir = TOP, tmp = valid_next(map,point, rows, cols, dir);
	if (tmp && backtrack(map, rows, cols, tmp, target, que, visit))
	{
		if (queue_push_front(que, (void *)point))
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
point_t *valid_next(char **map, point_t *point, int rows, int cols, int dir)
{
	point_t *next = NULL;

	next = malloc(sizeof(point_t));
	if (!next)
		return (NULL);
	next->x = point->x, next->y = point->y;
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
