#include "nary_trees.h"

/**
 * nary_tree_delete - Deletes an N-ary tree
 * @tree: Tree to delete
 */
void nary_tree_delete(nary_tree_t *tree)
{
	if (!tree)
		return;
	nary_tree_delete(tree->children);
	nary_tree_delete(tree->next);
	free(tree->content), tree->content = NULL;
	free(tree), tree = NULL;
}
