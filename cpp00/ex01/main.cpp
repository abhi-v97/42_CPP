/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-01 15:52:18 by abhi              #+#    #+#             */
/*   Updated: 2025-06-01 15:52:18 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>

std::string readUserInput(std::string str) {
  std::string userInput;
  int i;

  while (42) {
	userInput.clear();
    std::cout << "Enter " << str << ": ";
    std::getline(std::cin, userInput);
    if (userInput.size() != 0)
      break ;
	if (std::cin.eof())
	{
		std::cout << std::endl;
		exit(0);
	}
    std::cout << "Field cannot be blank!" << std::endl;
  }
  i = 0;
  while (userInput[i] == ' ')
  	i++;
  userInput.erase(0, i);
  return (userInput);
}

void add_contact(PhoneBook *phoneBook) {
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNum;
  std::string secret;

  firstName = readUserInput("first name");
  lastName = readUserInput("last name");
  nickname = readUserInput("a nickname");
  phoneNum = readUserInput("phone number");
  secret = readUserInput("their darkest secret");
  phoneBook->addContact(firstName, lastName, nickname, phoneNum, secret);
}

int main(void) {
  PhoneBook book;
  std::string input;
  std::string index;
  int i;

  while (42) {
	book.prompt();
    input = readUserInput("command");
    if (!input.compare(("ADD")) || !input.compare("1"))
      add_contact(&book);
    else if (!input.compare("SEARCH") || !input.compare("2"))
	{
		if (book.search())
			continue ;
		index = readUserInput("index");
		i = std::atoi(index.c_str());
		if (i == 0)
			continue ;
		else if (i)
		{
			std::cout << "\nContact details of index " << index << ": " << std::endl;
			book.printContact(i - 1);
		}
		else
		 	std::cout << "Bad index!" << std::endl;
	}
    else if (!input.compare("EXIT") || !input.compare("3"))
      break;
  }
  return (0);
}

//   book.addContact("name1", "name1", "nick", "111111", "secret");
//   book.addContact("name2", "name1", "nick", "222222", "secret");
//   book.addContact("name3", "name1", "nick", "333333", "secret");
//   book.addContact("name4", "name1", "nick", "444444", "secret");
//   book.addContact("name5", "name1", "nick", "555555", "secret");
//   book.addContact("name6", "name1", "nick", "666666", "secret");
//   book.addContact("name7", "name1", "nick", "777777", "secret");
//   book.addContact("name8", "name1", "nick", "888888", "secret");