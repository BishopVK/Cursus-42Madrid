/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:22:23 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 12:17:34 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		for (size_t j = 0; j < arg.length(); j++)
			arg[j] = std::toupper(arg[j]);
		std::cout << arg;
	}
	std::cout << std::endl;
	return (0);
}

/* #include <iostream>
#include <string>
#include <map>

std::string to_upper_extended(const std::string& s) {
	static const std::map<std::string, std::string> extended_upper = {
		{"á", "Á"}, {"é", "É"}, {"í", "Í"},
		{"ó", "Ó"}, {"ú", "Ú"}, {"ñ", "Ñ"},
		{"ä", "Ä"}, {"ë", "Ë"}, {"ï", "Ï"},
		{"ö", "Ö"}, {"ü", "Ü"}
	};

	// Si la cadena está en el mapa, retornamos la versión en mayúscula
	if (extended_upper.count(s)) {
		return extended_upper.at(s);
	}

	return s; // Retornamos la misma cadena si no está en el mapa
}

std::string process_argument(const std::string& arg) {
	std::string result;
	for (size_t i = 0; i < arg.size(); i++) {
		// Detectar caracteres multibyte (usando UTF-8)
		if ((arg[i] & 0x80) != 0) { // Carácter extendido
			std::string multibyte_char = arg.substr(i, 2); // Tomamos 2 bytes
			result += to_upper_extended(multibyte_char);
			i++; // Saltamos el segundo byte
		} else {
			// Carácter ASCII
			result += std::toupper(static_cast<unsigned char>(arg[i]));
		}
	}
	return result;
}

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	} else {
		for (int i = 1; i < argc; i++) {
			std::cout << process_argument(argv[i]);
		}
	}
	std::cout << std::endl;
	return 0;
}
*/