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

class Fixed {
public:
  Fixed();
  Fixed(const Fixed &cpy);
  ~Fixed();

  Fixed &operator=(Fixed const &src);
  int getRawBits(void) const;
  void setRawBits(int const raw);



private:
  int m_raw;
  static const int m_fractionalBits = 8;
};

#endif // FIXED_HPP
