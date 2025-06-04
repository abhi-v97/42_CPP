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

void Contact::setInfo(std::string firstName, std::string lastName,
                      std::string nickname, std::string number,
                      std::string secret) {
  m_first_name = firstName;
  m_last_name = lastName;
  m_nickname = nickname;
  m_phone_num = number;
  m_secret = secret;
}
