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

#include <string>

class Zombie {

public:
  Zombie(void);
  Zombie(std::string name);
  ~Zombie(void);

  void announce(void);
//   Zombie *newZombie(std::string name);
//   void randomChump(std::string name);

private:
  std::string name;
  std::string getName(void) const;
};