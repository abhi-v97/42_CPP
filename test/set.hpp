#pragma once

#include "searchable_bag.hpp"

class set : public searchable_bag
{
	private:
		searchable_bag &bag;
	public:
		set();
		set(const set &src);
		set &operator=(const set &src);
		set(searchable_bag &bag);
		~set();

		bool has(int) const;
		void insert(int);
		void insert(int *, int);
		void print() const;
		void clear();
		
		const searchable_bag &get_bag();
};