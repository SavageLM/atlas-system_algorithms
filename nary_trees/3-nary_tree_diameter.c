#include "nary_trees.h"

/**
 * nary_tree_diameter - Finds diameter of tree
 * @root: Tree to find diameter of
 * Return: Diameter or 0 on fail
 */
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t max = 0, diam = 0;
	
	if (!root)
		return (0);
	diam = root->children ? nary_tree_diameter(root->children) + 1 : 0;
	if (diam > max)
		max = diam;
	diam = root->next ? nary_tree_diameter(root->next) + 1 : 0;
	if (diam > max)
		max = diam;
	return (max);
}

/**
 * get_diam - gets the diameter of a tree
 * @root: tree to get diam of
 * @diam: diameter
 * Return: Diameter or 0
 */
/* size_t get_diam(nt const *root, size_t diam)
{
	size_t max1 = 0, max2 = 0;

	if (!root)
		return (diam);
	max1 = get_diam(root->children, diam + 1);
	max2 = get_diam(root->next, diam + 1);
	return (diam);
} */