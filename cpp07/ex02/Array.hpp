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

# include <cstddef>
# include <exception>

template <typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &obj);
		~Array();

		Array &operator=(Array const &src);
		T &operator[](size_t index);	
		
		size_t size() const;

		class OutofBoundsException : public std::exception
		{
		public:
			virtual char const *what() const throw();
		};
		
	private:
		T *m_array;
		size_t	m_size;
};

# include "Array.tpp"

#endif // ARRAY_HPP
