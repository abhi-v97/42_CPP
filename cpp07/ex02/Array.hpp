/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-11 09:14:40 by abhi              #+#    #+#             */
/*   Updated: 2025-08-11 09:14:40 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>
# include <iostream>

template <typename T = int>
class Array
{
	public:
		virtual char const *what() const throw()
		{
			return ("Array out of bounds");
		}
		Array(void) : m_array(NULL), m_size(0) {}
		Array(unsigned int n) : m_array(new T[n]), m_size(n) {}
		Array(Array const &obj) : m_array(new T[obj.m_size]), m_size(obj.m_size) {
			for (size_t i = 0; i < this->m_size; i++)
				this->m_array[i] = obj.m_array[i];
		}
		~Array() {delete [] m_array;}

		Array &operator=(Array const &src)
		{
			if (*this != src)
			{
				if (this->m_size != src.m_size)
				{
					delete [] m_array;
					this->m_size = src.m_size;
					this->m_array = new T[this->m_size];
				}
				for (size_t i = 0; i < this->m_size; i++)
					this->m_array[i] = src.m_array[i];
			}
			return (*this);
		}

		T &operator[](size_t index)
		{
			if (index >= this->m_size)
				throw(std::exception());
			return (this->m_array[index]);
		}
		
		size_t size() const
		{
			return (this->m_size);
		}
	private:
		T *m_array;
		size_t	m_size;
};

template <typename T>
std::ostream &operator<<(std::ostream &outf, Array<T> &obj)
{
	size_t len = obj.size();

	std::cout << "{ ";
	for (size_t i = 0; i < len; i++)
	{
		std::cout << obj[i];
		if (i < len - 1)
			std::cout << ", ";
	}
	std::cout << " }" << std::endl;
	return (outf);
}

#endif // ARRAY_HPP
