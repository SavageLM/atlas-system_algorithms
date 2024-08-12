#include "nary_trees.h"

size_t get_depth(nt const *root, size_t depth,
				 void (*action)(nt const *node, size_t depth));

/**
 * nary_tree_traverse - Traverses a tree
 * @root: Tree to navigate
 * @action: function to call on each node
 * Return: Depth of tree
 */
size_t nary_tree_traverse(nt const *root,
						  void (*action)(nt const *node, size_t depth))
{
	size_t depth = 0;

	return (get_depth(root, depth, action));
}

/**
 * get_depth - finds depth of tree
 * @root: Tree to navigate
 * @action: function to call on each node
 * @depth: depth of tree
 * Return: Depth or 0
 */
size_t get_depth(nt const *root, size_t depth,
				 void (*action)(nt const *node, size_t depth))
{
	if (!root)
		return (depth);
	action(root, depth);
	get_depth(root->children, depth + 1, action);
	get_depth(root->next, depth, action);

	return (depth);
}
