#include "rb_trees.h"

rb_tree_t *rotate_left(rb_tree_t *node, rb_tree_t **tree);
rb_tree_t *rotate_right(rb_tree_t *node, rb_tree_t **tree);
void rebalance(rb_tree_t *node, rb_tree_t **tree);


/**
 * rb_tree_insert - Inserts a node into the tree
 * @tree: Tree to insert node into
 * @value: value of node to insert
 * Return: pointer to new node or NULL
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *new_node = NULL;

	if (!*tree)
	{
		*tree = rb_tree_node(NULL, value, 1);
		return (*tree);
	}
	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
		{
			new_node = (rb_tree_node(*tree, value, 0));
			(*tree)->left = new_node; /* rebalance(new_node, tree); */
			return (new_node);
		}
		else
			new_node = rb_tree_insert(&(*tree)->left, value);
	}
	else if (value > (*tree)->n)
	{
		if (!(*tree)->right)
		{
			new_node = (rb_tree_node(*tree, value, 0));
			(*tree)->right = new_node; /* rebalance(new_node, tree); */
			return (new_node);
		}
		else
			new_node = rb_tree_insert(&(*tree)->right, value);
	}
	else
		return (NULL);
	if (!new_node)
		return (NULL);
	rebalance(new_node, tree);
	return (new_node);
}

/**
 * rotate_left - performs a left-rotation on binary tree
 * @node: root node of tree to be left-rotated
 * @tree: Root of entire tree
 * Return: pointer to new root node of tree following left-rotation
 */
rb_tree_t *rotate_left(rb_tree_t *node, rb_tree_t **tree)
{
	rb_tree_t *tmp = NULL;

	if (!node)
		return (NULL);
	tmp = node->right;
	node->right = tmp->left;
	if (tmp->left)
		tmp->left->parent = node;
	tmp->parent = node->parent;
	if (tmp->parent)
	{	
		if (node == tmp->parent->left)
			tmp->parent->left = tmp;
		else
			tmp->parent->right = tmp;
	}
	else
		*tree = tmp;
	tmp->left = node;
	node->parent = tmp;
	return (tmp);
}

/**
 * rotate_right - performs a right-rotation on binary tree
 * @node: root node of tree to be right-rotated
 * @tree: root of entire tree
 * Return: pointer to new root node of tree following right-rotation
 */
rb_tree_t *rotate_right(rb_tree_t *node, rb_tree_t **tree)
{
	rb_tree_t *tmp = NULL;

	if (!node)
		return (NULL);
	tmp = node->left;
	node->left = tmp->right;
	if (tmp->right)
		tmp->right->parent = node;
	tmp->parent = node->parent;
	if (tmp->parent)
	{	
		if (node == tmp->parent->left)
			tmp->parent->left = tmp;
		else
			tmp->parent->right = tmp;
	}
	else
		*tree = tmp;
	tmp->right = node;
	node->parent = tmp;
	return (tmp);
}

/**
 * rebalance - Checks if a color change or rotation is needed
 * @node: node to check balance of
 */
void rebalance(rb_tree_t *node, rb_tree_t **tree)
{
	rb_tree_t *uncle = NULL;

	if (!PARENT || PARENT->color == 1)/*PARENT IS BLACK CASE*/
		return;
	if (!GRANDPA)
		return;
	uncle = GRANDPA->left == PARENT ? GRANDPA->right : GRANDPA->left;
	if (uncle && uncle->color == 0)/*UNCLE IS RED CASE*/
		PARENT->color = 1, uncle->color = 1, GRANDPA->color = 0;
	else/*  if (!uncle || uncle->color == 1) *//*UNCLE IS BLACK CASE*/
	{
		if (GRANDPA->left == uncle && PARENT->right == node)/*parent right node right*/
			GRANDPA->color = 0, PARENT->color = 1, rotate_left(GRANDPA, tree);
		else if (GRANDPA->right == uncle && PARENT->left == node)/*Parent left, node left*/
			GRANDPA->color = 0, PARENT->color = 1, rotate_right(GRANDPA, tree);
		else if (GRANDPA->left == uncle && PARENT->left == node)/*Parent right, node left*/
		{
			node = node->parent, rotate_right(node, tree);
			PARENT->color = 1, GRANDPA->color = 0;
			rotate_left(GRANDPA, tree);
		}
		else /*Parent left, node right*/
		{
			node = node->parent, rotate_left(node, tree);
			PARENT->color = 1, GRANDPA->color = 0;
			rotate_right(GRANDPA, tree);
		}
	}
	if (!(*tree)->parent)
		(*tree)->color = 1;
}
