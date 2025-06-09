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

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "PhoneBook.hpp"
#include "colours.hpp"

// print title
void printTitle(std::string str)
{
	std::cout << BHCYN << "!!! " << str << " !!!" << CRESET << std::endl;
}

// reads user input until a non-blank input is given, then returns it
std::string readUserInput(std::string str)
{
	std::string userInput;
	int i;

	while (42)
	{
		userInput.clear();
		std::cout << "\nEnter " << str << ": ";
		std::getline(std::cin, userInput);
		if (userInput.size() != 0)
			break;
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit(0);
		}
		std::cout << BHRED << "Field cannot be blank!" << CRESET << std::endl;
	}
	i = 0;
	while (userInput[i] == ' ')
		i++;
	userInput.erase(0, i);
	return (userInput);
}

// reads number, returns an empty string if the string isn't only numbers
std::string readNumber(std::string str)
{
	std::string userInput;
	int i;

	while (42)
	{
		userInput.clear();
		std::cout << "\nEnter " << str << ": ";
		std::getline(std::cin, userInput);
		if (userInput.size() != 0)
			break;
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit(0);
		}
		std::cout << BHRED << "Field cannot be blank!" << CRESET << std::endl;
	}
	i = 0;
	while (userInput[i] == ' ')
		i++;
	userInput.erase(0, i);
	i = 0;
	while (userInput[i])
	{
		if (std::isdigit(userInput[i++]) == 0)
			return ("");
	}
	return (userInput);
}

// add contact to phonebook
void add_contact(PhoneBook *phoneBook)
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNum;
	std::string secret;

	firstName = readUserInput("first name");
	lastName = readUserInput("last name");
	nickname = readUserInput("a nickname");
	while (42)
	{
		phoneNum = readNumber("phone number");

		if (phoneNum.size() != 0)
			break;
		std::cout << BHRED << "Numbers only!" << CRESET << std::endl;
	}
	secret = readUserInput("their darkest secret");
	phoneBook->addContact(firstName, lastName, nickname, phoneNum, secret);
}

// wait for user input, then clear screen
void enterPrompt(void)
{
	std::cout << BHGRN << "Press any key to continue..." << CRESET << std::endl;
	std::cin.get();
	system("clear");
}

// get index from user and pass it to phonebook instance
void indexPrompt(PhoneBook book)
{
	int i;
	std::string index;

	while (42)
	{
		index = readUserInput("index");
		if (index.size() > 1)
		{
			std::cout << BHRED << "Bad input!" << CRESET << std::endl;
			continue;
		}
		i = std::atoi(index.c_str());
		if (i == 0)
			return;
		if (i > 8 || i > book.getSize())
			std::cout << BHRED << "Index out of range!" << CRESET << std::endl;
		else
			break;
	}
	std::cout << "\nContact details of index " << index << ": " << std::endl;
	book.printContact(i - 1);
}

int main(void)
{
	PhoneBook book;
	std::string input;

	system("clear");
	printTitle("C++ PHONEBOOK");
	std::cout << BHYEL << "Instructions: ADD [1]; SEARCH [2]; EXIT [3];" << CRESET << std::endl;
	while (42)
	{
		input = readUserInput("command");
		if (!input.compare(("ADD")) || !input.compare("1"))
		{
			system("clear");
			printTitle("ADD");
			add_contact(&book);
			std::cout << BHGRN << "Contact added!" << CRESET << std::endl;
			enterPrompt();
		}
		else if (!input.compare("SEARCH") || !input.compare("2"))
		{
			system("clear");
			printTitle("SEARCH");
			std::cout << BHYEL << "Instructions: Enter a num within range 1-8, or 0 to return" << CRESET << std::endl;
			if (book.searchTable())
			{
				enterPrompt();
				continue;
			}
			indexPrompt(book);
			enterPrompt();
		}
		else if (!input.compare("EXIT") || !input.compare("3"))
			break;
		else
		{
			std::cout << BHRED << "Invalid command, please try again" << CRESET << std::endl;
			continue;
		}
		printTitle("C++ PHONEBOOK");
		std::cout << BHYEL << "Instructions: ADD [1]; SEARCH [2]; EXIT [3]" << CRESET << std::endl;
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
