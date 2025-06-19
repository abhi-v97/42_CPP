/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-19 18:52:15 by abhi              #+#    #+#             */
/*   Updated: 2025-06-19 18:52:15 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point {
	private:
	const Fixed m_x;
	const Fixed m_y;
	
	public:
	Point();
	Point(const float x, const float y);
	Point(const Point &obj);
	~Point();

	Fixed const &getX(void) const;
	Fixed const &getY(void) const;

	Point &operator=(Point const &obj);
};
