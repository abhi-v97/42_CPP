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

class PhoneBook {

public:
  PhoneBook(void) {
    this->m_index = 0;
    this->m_size = 0;
  }
  ~PhoneBook(void) {}
  void prompt(void) const;
  void addContact(std::string firstName, std::string lastName,
                  std::string nickname, std::string number, std::string secret);
  int search(void) const;
  void printContact(int i);

private:
  Contact m_contacts[8];
  int m_index;
  int m_size;

  void printSearchField(std::string str) const;
};

#endif
