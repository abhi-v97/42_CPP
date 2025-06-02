/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-01 14:12:32 by abhi              #+#    #+#             */
/*   Updated: 2025-06-01 14:12:32 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::prompt(void) const {
  std::cout << "C++ PhoneBook" << std::endl;
  std::cout << "Instructions:" << std::endl;
  std::cout << "ADD:" << std::endl;
  std::cout << "SEARCH" << std::endl;
  std::cout << "EXIT" << std::endl;
}

void PhoneBook::addContact(std::string firstName, std::string lastName,
                           std::string nickname, std::string number,
                           std::string secret) {
  this->m_index++;
  this->m_index = this->m_index % 8;
  this->m_contacts[m_index].setInfo(firstName, lastName, nickname, number,
                                    secret);
}

void PhoneBook::search(void) const {}