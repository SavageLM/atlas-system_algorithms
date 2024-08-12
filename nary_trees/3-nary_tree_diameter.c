#include "nary_trees.h"

size_t get_diam(nt const *root);

/**
 * nary_tree_diameter - Finds diameter of tree
 * @root: Tree to find diameter of
 * Return: Diameter or 0 on fail
 */
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t diam = 0;

	if (!root)
		return (0);
	if (root->children || root->next)
	{
		diam = get_diam(root), diam -= 1;
		return (diam);
	}
	else
		return (1);
}

/**
 * get_diam - gets the diameter of a tree
 * @root: tree to get diam of
 * Return: Diameter or 0
 */
size_t get_diam(nt const *root)
{
	size_t max = 0, diam = 0;

	diam = root->children ? get_diam(root->children) + 1 : 0;
	if (diam > max)
		max = diam;
	diam = root->next ? get_diam(root->next) + 1 : 0;
	if (diam > max)
		max = diam;
	return (max);
} 
