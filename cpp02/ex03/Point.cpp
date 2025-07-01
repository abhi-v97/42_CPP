/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-01 21:01:18 by abhi              #+#    #+#             */
/*   Updated: 2025-07-01 21:01:18 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// constructors and destructors
Point::Point(void) : m_x(0), m_y(0) {}

Point::Point(const float x, const float y) : m_x(x), m_y(y) {}

Point::Point(const Point &obj) : m_x(obj.getX()), m_y(obj.getY()) {}

Point::~Point() {}

// getters
Fixed const &Point::getX(void) const {
	return (this->m_x);
}

Fixed const &Point::getY(void) const {
	return (this->m_y);
}

// operator overload
Point &Point::operator=(Point const &obj) {
	(void) obj;
	return (*this);
}
