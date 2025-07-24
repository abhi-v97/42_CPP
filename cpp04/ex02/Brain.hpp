/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-22 20:04:32 by abhi              #+#    #+#             */
/*   Updated: 2025-07-22 20:04:32 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{

	public:
		Brain();
		Brain(Brain const &obj);
		~Brain();

		Brain &operator=(Brain const &obj);

		static int const nb_ideas = 100;

		std::string getIdeas(int index) const;
		void setIdeas(int index, const std::string &ideas);

	private:
		std::string m_ideas[nb_ideas];
};

#endif // BRAIN_HPP
