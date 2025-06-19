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
