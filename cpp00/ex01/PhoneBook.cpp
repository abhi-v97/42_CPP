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
#include <iomanip>
#include <iostream>

void PhoneBook::prompt(void) const {
  std::cout << "!!! C++ PhoneBook !!!" << std::endl;
  std::cout << "Instructions: ADD [1]; SEARCH [2]; EXIT [3]" << std::endl;
}

void PhoneBook::addContact(std::string firstName, std::string lastName,
                           std::string nickname, std::string number,
                           std::string secret) {
  this->m_contacts[m_index].setInfo(firstName, lastName, nickname, number,
                                    secret);
	this->m_size++;
	this->m_index = this->m_size % 8;
}

void PhoneBook::printSearchField(std::string str) const {
	if (str.length() > 10)
	{
		str.resize(9);
		str += ".";
	}
	std::cout << "|" << std::setw(10) << str;
}

int PhoneBook::search(void) const {
  if (this->m_size == 0)
  {
	std::cout << "\t No contacts found!" << std::endl;
	return (1);
  }
  std::cout << "\t --INDEX----FIRST NAME--LAST NAME--NICKNAME---" << std::endl;
  std::cout << "\t ";
  for (int i = 0; i < this->m_size && i < 8; i++) {
    std::cout << "|" << std::setw(10) << i + 1;
	printSearchField(this->m_contacts[i].firstName());
	printSearchField(this->m_contacts[i].lastName());
	printSearchField(this->m_contacts[i].nickname());
    std::cout << "|" << std::setw(10) << std::endl;
  }
  std::cout << "\t ---------------------------------------------" << std::endl;
  return (0);
}

void PhoneBook::printContact(int i) {
	if (i < this->m_size)
	{
		std::cout << "Index out of range!" << std::endl;
		return ;
	}
	std::cout << "First Name:\t" << m_contacts[i].firstName() << std::endl;
	std::cout << "Last Name:\t" << this->m_contacts[i].lastName() << std::endl;
	std::cout << "Nickname:\t" << this->m_contacts[i].nickname() << std::endl;
	std::cout << "Phone Number:\t" << this->m_contacts[i].phoneNum() << std::endl;
	std::cout << "Darkest Secret:\t" << this->m_contacts[i].secret() << std::endl << std::endl;
  }
  