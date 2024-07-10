#include "rb_trees.h"

rb_tree_t *rotate_left(rb_tree_t *tree);
rb_tree_t *rotate_right(rb_tree_t *tree);
void rebalance(rb_tree_t *node);


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
			(*tree)->left = new_node;
			rebalance(new_node);
		}
		else
			new_node = rb_tree_insert(&(*tree)->left, value);
	}
	else if (value > (*tree)->n)
	{
		if (!(*tree)->right)
		{
			new_node = (rb_tree_node(*tree, value, 0));
			(*tree)->right = new_node;
			rebalance(new_node);
		}
		else
			new_node = rb_tree_insert(&(*tree)->right, value);
	}
	else
		return (NULL);
	rebalance(*tree);
	return (new_node);
}

/**
 * rotate_left - performs a left-rotation on binary tree
 * @tree: root node of tree to be left-rotated
 * Return: pointer to new root node of tree following left-rotation
 */
rb_tree_t *rotate_left(rb_tree_t *tree)
{
	rb_tree_t *tmp = NULL;

	if (!tree)
		return (NULL);
	tmp = tree->right;
	tmp->parent = tree->parent;
	tree->right = tmp->left;
	if (tmp->left)
		tmp->left->parent = tree;
	tmp->left = tree;
	tree->parent = tmp;
	return (tmp);
}

/**
 * rotate_right - performs a right-rotation on binary tree
 * @tree: root node of tree to be right-rotated
 * Return: pointer to new root node of tree following right-rotation
 */
rb_tree_t *rotate_right(rb_tree_t *tree)
{
	rb_tree_t *tmp = NULL;

	if (!tree)
		return (NULL);
	tmp = tree->left;
	tmp->parent = tree->parent;
	tree->left = tmp->right;
	if (tmp->right)
		tmp->right->parent = tree;
	tmp->right = tree;
	tree->parent = tmp;

	return (tmp);
}

/**
 * rebalance - Checks if a color change or rotation is needed
 * @node: node to check balance of
 */
void rebalance(rb_tree_t *node)
{
	rb_tree_t *uncle = NULL;

	if (!PARENT || PARENT->color == 1)/*PARENT IS BLACK CASE*/
		return;

	uncle = GRANDPA->left == PARENT ? GRANDPA->right : GRANDPA->left;
	if (uncle && uncle->color == 0)/*UNCLE IS RED CASE*/
	{
		PARENT->color = 1, uncle->color = 1;
		if (GRANDPA->parent)
			GRANDPA->color = 0;
	}
	else if (!uncle || uncle->color == 1)/*UNCLE IS BLACK CASE*/
	{
		if (GRANDPA->left == uncle && PARENT->right == node)
		{/*LEFT ROTATE CASE*/
			rotate_left(GRANDPA);
			if (GRANDPA)
				GRANDPA->color = 0;
			PARENT->color = 1;
		}
		else if (GRANDPA->right == uncle && PARENT->left == node)
		{/*RIGHT ROTATE CASE*/
			node = rotate_right(GRANDPA);
			if (GRANDPA)
				GRANDPA->color = 0;
			PARENT->color = 1;
		}
		else if (GRANDPA->left == uncle && PARENT->left == node)
		{/*LEFT-RIGHT ROTATE CASE*/
			PARENT = rotate_right(PARENT);
			/* node->left->parent = node; */
			rotate_right(GRANDPA);
			if (GRANDPA)
				GRANDPA->color = 0;
			PARENT->color = 1;
		}
		else
		{/*RIGHT-LEFT ROTATE CASE*/
			PARENT = rotate_left(PARENT);
			/* node->right->parent = node; */
			node = rotate_right(GRANDPA);
			if (GRANDPA)
				GRANDPA->color = 0;
			PARENT->color = 1;
		}
	}
}
