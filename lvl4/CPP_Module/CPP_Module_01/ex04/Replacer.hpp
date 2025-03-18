/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:18:12 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/18 13:57:10 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
# define REPLACER_HPP

#include "SedIsForLosers.h"

class Replacer
{
	private:
		std::string _file_name;
		std::string	_string_to_find;
		std::string	_string_to_replace;
		std::string	_output_file_name;

	public:
		Replacer(const std::string &file_name, const std::string &s1, const std::string &s2);
		~Replacer();
		void				setReplacedFileName(const std::string &filename, const std::string &extension);
		const std::string	getFileName();
		const std::string	getStringToFind();
		const std::string	getStringToReplace();
		const std::string	getReplacedFileName();
		void				replace_string(std::string &line);
		void				create_Outfile();
};

#endif