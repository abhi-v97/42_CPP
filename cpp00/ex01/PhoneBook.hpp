/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-01 16:35:25 by abhi              #+#    #+#             */
/*   Updated: 2025-06-01 16:35:25 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "./Contact.hpp"
#include <iostream>

class PhoneBook {

public:
  void prompt(void) const;
  void addContact(std::string firstName, std::string lastName,
	std::string nickname, std::string number,
	std::string secret);
  void search(void) const;

  PhoneBook(void) {
    std::cout << "PhoneBook constructed!" << std::endl;
    this->m_index = 0;
  }
  ~PhoneBook(void) {}

  void getUserInput(std::string str, void (Contact::*f)(std::string));

private:
  Contact m_contacts[8];
  int m_index;
};

#endif
