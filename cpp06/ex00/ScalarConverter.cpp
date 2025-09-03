/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:25:03 by abhi              #+#    #+#             */
/*   Updated: 2025/08/09 18:51:26 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <string>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &o, ScalarConverter const &i)
{
	(void)i;
	(void)o;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ScalarConverter::printChar(double value)
{
	std::cout << "char: ";
	if (std::isprint(static_cast<char>(value)))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printInt(double value)
{
	std::cout << "int: ";
	if (value > 2147483647 || value < -2147483648)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value)
{
	std::cout << "float: ";
	if (static_cast<float>(value) == static_cast<int>(value))
		std::cout << static_cast<float>(value) << ".0f" << std::endl;
	else
		std::cout << std::setprecision(std::numeric_limits<float>::digits10)
				  << static_cast<float>(value) << ".0f" << std::endl;
}

void ScalarConverter::printDouble(double value)
{
	std::cout << "double: ";
	if (static_cast<double>(value) == static_cast<int>(value))
		std::cout << static_cast<double>(value) << ".0" << std::endl;
	else
		std::cout << std::setprecision(std::numeric_limits<double>::digits10)
				  << static_cast<double>(value) << ".0" << std::endl;
}

void ScalarConverter::convert(std::string const &str)
{
	double value;

	if (str.empty())
		return;
	else if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		value = static_cast<char>(str[1]);
	else
		value = strtod(str.c_str(), NULL);

	if (value == 0 && !std::isdigit(str[0]))
		return;

	if (std::isnan(value) || std::isinf(value) || std::isinf(static_cast<float>(value)))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << std::showpos << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << std::showpos << static_cast<double>(value) << std::endl;
	}
	else
	{
		printChar(value);
		printInt(value);
		printFloat(value);
		printDouble(value);
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */