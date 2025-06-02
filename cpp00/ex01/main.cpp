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
#include <cstring>

std::string readUserInput(std::string str) {
  std::string userInput;

  while (42) {
    std::cout << "\nEnter " << str << ": ";
    std::getline(std::cin, userInput);
    if (userInput.size() != 0)
      break ;
    std::cout << "Field cannot be blank!\n" << std::endl;
  }
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

  while (42) {
    book.prompt();
    std::getline(std::cin, input);
    if (!input.compare(("ADD")))
      add_contact(&book);
    // else if (!input.compare("SEARCH"))
    //   search_contact();
    else if (!input.compare("EXIT"))
      break;
    else
      std::cout << "Command not recognised, please try again!" << std::endl;
  }
  return (0);
}
