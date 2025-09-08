
#include "searchable_tree_bag.hpp"
#include <cstddef>

searchable_tree_bag::searchable_tree_bag()
{
}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &src) : tree_bag(src)
{
}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &src)
{
	if (this != &src)
		tree_bag::operator=(src);
	return (*this);
}

bool searchable_tree_bag::has(int value) const
{
	return (search(this->tree, value));
}

bool searchable_tree_bag::search(node *node, const int value) const
{
	if (node == NULL)
		return (false);
	if (value == node->value)
		return (true);
	else if (value < node->value)
		return (search(node->l, value));
	else
	 	return (search(node->r, value));
	
}

searchable_tree_bag::~searchable_tree_bag()
{
}