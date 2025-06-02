/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-01 15:50:23 by abhi              #+#    #+#             */
/*   Updated: 2025-06-01 15:50:23 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"
#include <iostream>

void Contact::setInfo(std::string firstName, std::string lastName,
                      std::string nickname, std::string number,
                      std::string secret) {
  m_first_name = firstName;
  m_last_name = lastName;
  m_nickname = nickname;
  m_phone_num = number;
  m_secret = secret;
}

void Contact::printContact() {
  std::cout << "First Name:\t" << m_first_name << std::endl;
  std::cout << "Last Name:\t" << m_last_name << std::endl;
  std::cout << "Nickname:\t" << m_nickname << std::endl;
  std::cout << "Phone Number:\t" << m_phone_num << std::endl;
  std::cout << "Darkest Secret:\t" << m_secret << std::endl;
}
