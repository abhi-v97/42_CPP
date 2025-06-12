/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-05 18:02:24 by abhi              #+#    #+#             */
/*   Updated: 2025-06-05 18:02:24 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {

public:
  Zombie(void);
  Zombie(std::string name);
  ~Zombie(void);

  void announce(void) const;
  std::string getName(void) const { return (this->m_name); }

private:
  std::string m_name;
};

#endif // ZOMBIE_HPP
