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
  void addContact(std::string firstName, std::string lastName,
                  std::string nickname, std::string number, std::string secret);
  int searchTable(void) const;
  void printContact(int i);
  int getSize(void);

private:
  Contact m_contacts[8];
  int m_index;
  int m_size;

  void printField(std::string str) const;
};

#endif
