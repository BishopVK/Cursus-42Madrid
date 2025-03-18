/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:27:59 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/18 14:34:48 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(const std::string &file_name, const std::string &s1, const std::string &s2)
	: _file_name(file_name), _string_to_find(s1), _string_to_replace(s2)
{
}

Replacer::~Replacer()
{
}

void	Replacer::setReplacedFileName(const std::string &filename, const std::string &extension)
{
	this->_output_file_name = filename + extension;
	//std::cout << "Output file name is: " << this->_output_file << std::endl;
}

const	std::string	Replacer::getFileName()
{
	return (this->_file_name);
}

const	std::string	Replacer::getStringToFind()
{
	return (this->_string_to_find);
}

const	std::string	Replacer::getStringToReplace()
{
	return (this->_string_to_replace);
}

const	std::string	Replacer::getReplacedFileName()
{
	return (this->_output_file_name);
}

void	Replacer::replace_string(std::string &line)
{
	unsigned long int	start = 0;

	while (start != std::string::npos)
	{
		start = line.find(this->_string_to_find, start);
		if (start != std::string::npos)
		{
			line.erase(start, this->_string_to_find.length());
			line.insert(start, _string_to_replace);
			start += _string_to_replace.length();
		}
	}
}

void	Replacer::create_Outfile()
{
	std::ifstream	infile_stream;  // fstream command to initiate "infile_stream" as a command.
	infile_stream.open(this->getFileName()); // this in_stream (fstream) the "filename" to open.
	if (!infile_stream)
	{
		std::cerr << RED << "Could not open file to read." << RESET << std::endl; // if the open file fails.
		exit (-1);
	}

	std::ofstream	outfile_stream(this->_output_file_name); 
	std::string		line; // Buffer the save a read line

	while (std::getline(infile_stream, line))
	{
		replace_string(line);
		outfile_stream << line;
		if (!infile_stream.eof())
			outfile_stream << std::endl;
	}

	infile_stream.close();
	outfile_stream.close();
}