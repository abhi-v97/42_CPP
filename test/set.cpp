#include "set.hpp"
#include "searchable_bag.hpp"

set::set(searchable_bag &bag) : bag(bag)
{}

bool set::has(int value) const
{
	return (bag.has(value));
}

void set::insert(int value)
{
	if (!this->has(value))
		bag.insert(value);
}

void set::insert(int *data, int size)
{
	for (int i = 0; i < size; i++)
		this->insert(data[i]);
}

void set::print() const
{
	bag.print();
}

void set::clear()
{
	bag.clear();
}

const searchable_bag &set::get_bag()
{
	return (this->bag);
}

set::~set() {}