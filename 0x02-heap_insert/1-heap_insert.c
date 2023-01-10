#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: A double pointer to the root node of the Heap
 * @value: The value store in the node to be inserted
 * Return: A pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	heap_t *temp = NULL;
	int temp_value = 0;

	if (root == NULL)
		return (NULL);
	new_node = binary_tree_node(NULL, value);
	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}
	temp = *root;
	while (temp->left != NULL && temp->right != NULL)
	{
		if (temp->left->left == NULL || temp->left->right == NULL)
			temp = temp->left;
		else if (temp->right->left == NULL || temp->right->right == NULL)
			temp = temp->right;
		else
			temp = temp->left;
	}
	if (temp->left == NULL)
		temp->left = new_node;
	else
		temp->right = new_node;
	new_node->parent = temp;
	while (new_node->parent != NULL && new_node->n > new_node->parent->n)
	{
		temp_value = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = temp_value;
		new_node = new_node->parent;
	}
	return (new_node);
}
