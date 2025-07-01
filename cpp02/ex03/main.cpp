/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-10 21:38:35 by abhi              #+#    #+#             */
/*   Updated: 2025-06-10 21:38:35 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <cmath>
#include <ios>

static Fixed sign(const Point a, const Point b, const Point c) {
  return ((a.getX() - c.getX()) * (b.getY() - c.getY()) -
          (a.getY() - c.getY()) * (b.getX() - c.getX()));
}

// https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle
bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed d1, d2, d3;
  bool hasNeg, hasPos;

  d1 = sign(point, a, b);
  d2 = sign(point, b, c);
  d3 = sign(point, c, a);

  hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
  hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);
  return !(hasNeg && hasPos);
}

int main(void) {
  Point v1(-3, 0);
  Point v2(0, 3);
  Point v3(3, 0);

  std::cout << "Triangle vertices: " << std::endl;
  std::cout << "v1 = (-3, 0)" << std::endl;
  std::cout << "v2 = (0, 3)" << std::endl;
  std::cout << "v3 = (3, 0)" << std::endl;

  std::cout << std::endl;
  std::cout << std::boolalpha;
  std::cout << "Test (3, 0): " << bsp(v1, v2, v3, Point(3, 0)) << std::endl;
  std::cout << "Test (-3, 0): " << bsp(v1, v2, v3, Point(-3, 0)) << std::endl;
  std::cout << "Test (0, 3): " << bsp(v1, v2, v3, Point(0, 3)) << std::endl;
  std::cout << "Test (4.5, 4.5): " << bsp(v1, v2, v3, Point(4.5, 4.5))
            << std::endl;
  std::cout << "Test (0, -1.3): " << bsp(v1, v2, v3, Point(0, -1.3))
            << std::endl;
  std::cout << "Test (0, 1.3): " << bsp(v1, v2, v3, Point(0, 1.3)) << std::endl;
  std::cout << "Test (-1, 0.5): " << bsp(v1, v2, v3, Point(-1, 0.5))
            << std::endl;

  return (0);
}
