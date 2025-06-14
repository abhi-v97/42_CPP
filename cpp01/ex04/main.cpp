/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-10 21:38:35 by abhi              #+#    #+#             */
/*   Updated: 2025-06-10 21:38:35 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

static void stringReplace(std::string *buffer, std::string s1, std::string s2);

int main(int argc, char **argv)
{	
	if (argc != 4)
		return (0);

	// open streams for input and output
	std::ifstream inf(argv[1]);
	std::string outfile(argv[1]);
	outfile = outfile + ".replace";
	std::ofstream outf(outfile.c_str());
	if (!inf.good() || !outf.good())
	{
		std::cerr << "File streaming error" << "\n";
		return (1);
	}

	// loop to copy contents, make a sub if needed
	std::string buffer;
	while (std::getline(inf, buffer))
	{
		stringReplace(&buffer, argv[2], argv[3]);
		outf  << buffer;
		if (!inf.eof())
			outf << "\n";
	}
	return (0);
}

static void stringReplace(std::string *buffer, std::string s1, std::string s2)
{
	size_t cursor;

	cursor = 0;
	if (s1.empty())
		return ;
	while (cursor != std::string::npos)
	{
		cursor = buffer->find(s1, cursor);
		if (cursor == std::string::npos)
			break ;
		buffer->erase(cursor, s1.length());
		if (!s2.empty())
		{
			buffer->insert(cursor, s2);
			cursor += s2.length(); // prevent inf loop if s1 = s2
		}
	}
}
