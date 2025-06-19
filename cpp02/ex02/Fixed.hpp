/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-16 18:26:03 by abhi              #+#    #+#             */
/*   Updated: 2025-06-16 18:26:03 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
  Fixed();
  Fixed(const Fixed &cpy);
  Fixed(const int n);
  Fixed(const float f);
  ~Fixed();

  Fixed &operator=(Fixed const &src);

  Fixed operator+(Fixed const &src) const;
  Fixed operator-(Fixed const &src) const;
  Fixed operator*(Fixed const &src) const;
  Fixed operator/(Fixed const &src) const;
  
  bool operator>(Fixed const &src) const;
  bool operator<(Fixed const &src) const;
  bool operator>=(Fixed const &src) const;
  bool operator<=(Fixed const &src) const;
  bool operator==(Fixed const &src) const;
  bool operator!=(Fixed const &src) const;
  
  Fixed &operator++(void);
  Fixed operator++(int);
  Fixed &operator--(void);
  Fixed operator--(int);
  
  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;
  
  static Fixed& min(Fixed &lhs, Fixed &rhs);
  static Fixed& max(Fixed &lhs, Fixed &rhs);

  static const Fixed& min(Fixed const &lhs, Fixed const &rhs);
  static const Fixed& max(Fixed const &lhs, Fixed const &rhs);


private:
  int m_raw;
  static const int m_fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &outf, const Fixed &obj);


#endif // FIXED_HPP
