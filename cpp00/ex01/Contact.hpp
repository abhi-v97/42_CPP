/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-01 15:48:51 by abhi              #+#    #+#             */
/*   Updated: 2025-06-01 15:48:51 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {

public:
  Contact() { return; }
  ~Contact() { return; }

  // setter
  void setInfo(std::string firstName, std::string lastName,
                  std::string nickname, std::string number, std::string secret);

  // getters
  std::string firstName() const { return m_first_name; }
  std::string lastName() const { return m_last_name; }
  std::string nickname() const { return m_nickname; }
  std::string phoneNum() const { return m_phone_num; }
  std::string secret() const { return m_secret; }

private:
  std::string m_first_name;
  std::string m_last_name;
  std::string m_nickname;
  std::string m_phone_num;
  std::string m_secret;
};

#endif // CONTACT_HPP
