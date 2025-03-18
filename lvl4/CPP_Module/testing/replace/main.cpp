/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:52:44 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/18 14:37:58 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <fstream>

/* int	main(void)
{
	std::string line = "la lana de la mala gana";
	std::string s2 = "a";
	std::string s3 = "caca";
	unsigned long int	start = 0;

	while (start != std::string::npos)
	{
		start = line.find(s2, start);
		if (start != std::string::npos)
		{
			std::cout << "Found '" << s2 << "' at " << start << " position" << std::endl;
			line.erase(start, s2.length());
			std::cout << line << std::endl;
			line.insert(start, s3);
			std::cout << line << std::endl;
			start += s3.length();
		}
	}
	return 0;
} */

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Nº de parametros erroneo." << std::endl << "Saliendo del programa..." << std::endl;
		return -1;
	}
	std::ifstream	in_stream; // fstream command to initiate "in_stream" as a command.
	std::string		file_name = argv[1]; // variable for "filename".
	std::string		out_file = file_name + ".replace";
	std::ofstream	out_stream(out_file);

	in_stream.open(file_name); // this in_stream (fstream) the "filename" to open.
	if (!in_stream)
	{
		std::cerr << "Could not open file to read." << std::endl; // if the open file fails.
		return -1;
	}
	
	std::string	line;
	while (std::getline(in_stream, line))
	{
		std::cout << "Line: " << line << std::endl;
		out_stream << line << std::endl;
	}

	in_stream.close();
	out_stream.close();
	
	return 0;
}