#include "pathfinding.h"

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
	if (!map || !row || !cols || !start || !target)
		return (NULL);
}