#include "nary_trees.h"

/**
 * path_exists - Checks if path exists in tree
 * @root: tree to check for path in
 * @path: path to check for
 * Return: 1 if all of path is in root, 0 if not
 */
int path_exists(nary_tree_t const *root, char const * const *path)
{
	nt *node;
	static int i;

	if (path[i] == NULL)
		return (1);
	if (!root)
		return (0);
	for (node = (nt *)&root->content; node; node = node->next)
	{
		if (!strcmp(path[i], node->content))
		{
			i++;
			if (path_exists(node->children, path))
				return (1);
		}
	}
	return (0);
}
