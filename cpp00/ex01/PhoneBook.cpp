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

// getter for m_size
int PhoneBook::getSize(void) { return (m_size);}

// adds a new contact to m_contacts array
// if more than 8 contacts are added, the new contact overwrites old ones
void PhoneBook::addContact(std::string firstName, std::string lastName,
						   std::string nickname, std::string number,
						   std::string secret)
{
	this->m_contacts[m_index].setInfo(firstName, lastName, nickname, number,
									  secret);
	this->m_size++;
	this->m_index = this->m_size % 8;
}

// print contact details for index i
void PhoneBook::printContact(int i)
{
	std::cout << "First Name:\t" << m_contacts[i].firstName() << std::endl;
	std::cout << "Last Name:\t" << this->m_contacts[i].lastName() << std::endl;
	std::cout << "Nickname:\t" << this->m_contacts[i].nickname() << std::endl;
	std::cout << "Phone Number:\t" << this->m_contacts[i].phoneNum() << std::endl;
	std::cout << "Darkest Secret:\t" << this->m_contacts[i].secret() << std::endl
			  << std::endl;
}

// prints all contacts in a neat table
int PhoneBook::searchTable(void) const
{
	if (this->m_size == 0)
	{
		std::cout << "\t No contacts found!" << std::endl;
		return (1);
	}
	std::cout << "\n\t --INDEX----FIRST NAME--LAST NAME--NICKNAME---" << std::endl;
	std::cout << "\t ";
	for (int i = 0; i < this->m_size && i < 8; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1;
		printField(this->m_contacts[i].firstName());
		printField(this->m_contacts[i].lastName());
		printField(this->m_contacts[i].nickname());
		std::cout << "|" << std::setw(10) << std::endl;
	}
	std::cout << "\t ---------------------------------------------" << std::endl;
	return (0);
}

// prints a field to the search table
// if size is greater than 10, resize it to 9 and append a "."
void PhoneBook::printField(std::string str) const
{
	if (str.length() > 10)
	{
		str.resize(9);
		str += ".";
	}
	std::cout << "|" << std::setw(10) << str;
}
