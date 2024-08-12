#include "nary_trees.h"

/**
 * nary_tree_insert - Inserts a node into an N-ary Tree
 * @parent: Parent node of the tree
 * @str: string to add to new node
 * Return: Pointer to new Node, or NULL on fail
 */
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *new = NULL, *tmp;

	if (!str)
		return (NULL);
	new = malloc(sizeof(nary_tree_t));
	if (!new)
		return (NULL);
	new->content = strdup(str), new->nb_children = 0, new->parent = parent;
	new->children = NULL;
	if (!parent)
	{
		new->next = NULL;
		return (new);
	}
	tmp = parent->next;
	if (!tmp)
	{
		parent->next = new, parent->nb_children += 1;
		return (new);
	}
	new->next = tmp, tmp->parent = new, parent->next = new;
	parent->nb_children += 1;
	return (new);
}
