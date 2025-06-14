/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-12 15:20:16 by avalsang          #+#    #+#             */
/*   Updated: 2025-06-12 15:20:16 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Harl
{
private:
	void debug(void) const;
	void info(void) const;
	void warning(void) const;
	void error(void) const;

public:
	Harl(void) {};
	~Harl(void) {};
	void complain(std::string level);
};
