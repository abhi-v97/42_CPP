/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3025-06-10 30:38:35 by abhi              #+#    #+#             */
/*   Updated: 3025-06-10 30:38:35 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>
#include <iostream>

// https://floating-point-gui.de
int main(void) {
  Fixed a(0.0f);

  std::cout << std::endl;
  std::cout << std::setw(30) << "Test" << std::setw(30) << "Result" << std::endl;

  std::cout << std::endl;
  std::cout << "Testing increment" << std::endl;
  std::cout << std::setw(30) << "a: " << std::setw(30) << a << std::endl;
  std::cout << std::setw(30) << "++a: "<< std::setw(30) << ++a << std::endl;
  std::cout << std::setw(30) << "a: " << std::setw(30) << a << std::endl;
  std::cout << std::setw(30) << "a++: " << std::setw(30) << a++ << std::endl;
  std::cout << std::setw(30) << "a: " << std::setw(30) << a << std::endl;

  std::cout << std::endl;
  std::cout << "Testing decrement" << std::endl;
  std::cout << std::setw(30) << "a: " << std::setw(30) << a << std::endl;
  std::cout << std::setw(30) << "--a: "<< std::setw(30) << ++a << std::endl;
  std::cout << std::setw(30) << "a: " << std::setw(30) << a << std::endl;
  std::cout << std::setw(30) << "a--: " << std::setw(30) << a++ << std::endl;
  std::cout << std::setw(30) << "a: " << std::setw(30) << a << std::endl;

  std::cout << std::endl;
  std::cout << "Testing arithmetic" << std::endl;
  std::cout << std::setw(30) << "3 + 2: " << std::setw(30) << Fixed(3) + Fixed(2) << std::endl;
  std::cout << std::setw(30) << "2.1 + 2.1: " << std::setw(30) << Fixed(2.1f) + Fixed(2.1f) << std::endl;
  std::cout << std::setw(30) << "1234 - 234: " << std::setw(30) << Fixed(1234) - Fixed(234) << std::endl;
  std::cout << std::setw(30) << "42.105 - 0.105: " << std::setw(30) << Fixed(42.105f) - Fixed(.105f) << std::endl; 
  std::cout << std::setw(30) << "42 * 2: " << std::setw(30) << Fixed(42) * Fixed(2) << std::endl;
  std::cout << std::setw(30) << "2.4 * 4.8: " << std::setw(30) << Fixed(2.4f) * Fixed(4.8f) << std::endl;
  std::cout << std::setw(30) << "42 / 2: " << std::setw(30) << Fixed(42) / Fixed(2) << std::endl; 
  std::cout << std::setw(30) << "2.4 / 4.8: " << std::setw(30) << Fixed(2.4f) / Fixed(4.8f) << std::endl;

  std::cout << std::endl;
  std::cout << std::boolalpha;
  std::cout << "Testing comparison ops" << std::endl;
  std::cout << std::setw(30) << "5.99 > 2.01: " << std::setw(30) << (Fixed(5.99f) > Fixed(2.01f)) << std::endl;
  std::cout << std::setw(30) << "5.99 > 7.01: " << std::setw(30) << (Fixed(5.99f) > Fixed(7.01f)) << std::endl;
  std::cout << std::setw(30) << "0.2 < 1.2: " << std::setw(30) << (Fixed(0.2f) < Fixed(1.2f)) << std::endl;
  std::cout << std::setw(30) << "4.2 < 1.2: " << std::setw(30) << (Fixed(4.2f) < Fixed(1.2f)) << std::endl;
  std::cout << std::setw(30) << "7.10 >= 7.10: " << std::setw(30) << (Fixed(7.10f) >= Fixed(7.10f)) << std::endl;
  std::cout << std::setw(30) << "7.10 >= 7.11: " << std::setw(30) << (Fixed(7.10f) >= Fixed(7.11f)) << std::endl;
  std::cout << std::setw(30) << "6.99 <= 7.01: " << std::setw(30) << (Fixed(6.99f) <= Fixed(7.01f)) << std::endl;
  std::cout << std::setw(30) << "8.99 <= 7.01: " << std::setw(30) << (Fixed(8.99f) <= Fixed(7.01f)) << std::endl;
  std::cout << std::setw(30) << "4.30 == 4.30: " << std::setw(30) << (Fixed(4.2f) == Fixed(4.2f)) << std::endl;
  std::cout << std::setw(30) << "4.30 == 4.21: " << std::setw(30) << (Fixed(4.2f) == Fixed(4.21f)) << std::endl;
  std::cout << std::setw(30) << "5.34 != 5.342: " << std::setw(30) << (Fixed(5.34f) != Fixed(5.342f)) << std::endl;
  std::cout << std::setw(30) << "5.34 != 5.34: " << std::setw(30) << (Fixed(5.34f) != Fixed(5.34f)) << std::endl;
  

  const Fixed c(2.4f);
  const Fixed d(4.4f);
  std::cout << std::endl;
  std::cout << "Testing minmax" << std::endl;
  std::cout << std::setw(30) << "min(2.4, 4.4): " << std::setw(30) << Fixed::min(Fixed(2.4f), Fixed(4.4f)) << std::endl;
  std::cout << std::setw(30) << "(const) min(2.4, 4.4): " << std::setw(30) << Fixed::min(c, d) << std::endl;
  std::cout << std::setw(30) << "max(2.4, 4.4): " << std::setw(30) << Fixed::max(Fixed(2.4f), Fixed(4.4f)) << std::endl;
  std::cout << std::setw(30) << "(const) max(2.4, 4.4): " << std::setw(30) << Fixed::max(c, d) << std::endl;
  return (0);
}
