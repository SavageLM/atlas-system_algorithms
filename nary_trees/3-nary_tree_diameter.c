#include "nary_trees.h"

size_t get_height(nt const *root);

/**
 * nary_tree_diameter - Finds diameter of tree
 * @root: Tree to find diameter of
 * Return: Diameter or 0 on fail
 */
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t max1 = 0, max2 = 0, height = 0, dm = 0;
	nt *node;

	if (!root)
		return (0);
	for (node = root->children; node; node = node->next)
	{
		height = get_height(node);
		if (height > max1)
			max2 = max1, max1 = height;
		else if (height > max2)
			max2 = height;
		dm = dm > nary_tree_diameter(node) ? dm : nary_tree_diameter(node);
	}
	return (dm > max1 + max2 + 1 ? dm : max1 + max2 + 1);
}

/**
 * get_height - gets the height of a tree
 * @root: tree to get height of
 * Return: height or 0
 */
size_t get_height(nt const *root)
{
	size_t max = 0;
	nt *node;

	for (node = root->children; node; node = node->next)
	{
		max = max > get_height(node) ? max : get_height(node);
	}
	return (max + 1);
}
