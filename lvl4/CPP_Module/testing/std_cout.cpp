/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_cout.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:57:21 by danjimen          #+#    #+#             */
/*   Updated: 2025/01/28 23:46:42 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define BOLD "\033[1m"
#define BOLD_OFF "\033[22m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"
#define ITALIC "\033[3m"
#define UNDER "\033[4m"
#define SLOW_BLINK "\033[5m"
#define FAST_BLINK "\033[6m"
#define INVERT "\033[7m"
#define STROKE "\033[9m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_RESET "\033[49m"
#define CURSOR_UP "\033[<n>A"
#define CURSOR_DOWN "\033[<n>B"
#define CURSOR_RIGHT "\033[<n>C"
#define CURSOR_LEFT "\033[<n>D"
#define CLEAN_SCREEN "\033[2J"

int main(void)
{
	std::string	buff;

	std::cout << "Hello World !" << std::endl << RESET;
	std::cout << BOLD << "Hello World !" << std::endl << RESET;
	std::cout << RED << "Hello World !" << std::endl << RESET;
	std::cout << GREEN << "Hello World !" << std::endl << RESET;
	std::cout << YELLOW << "Hello World !" << std::endl << RESET;
	std::cout << BLUE << "Hello World !" << std::endl << RESET;
	std::cout << CYAN << "Hello World !" << std::endl << RESET;
	std::cout << ITALIC << "Hello World !" << std::endl << RESET;
	std::cout << UNDER << "Hello World !" << std::endl << RESET;
	std::cout << SLOW_BLINK << "Hello World !" << std::endl << RESET;
	std::cout << FAST_BLINK << "Hello World !" << std::endl << RESET;
	std::cout << INVERT << "Hello World !" << std::endl << RESET;
	std::cout << STROKE << "Hello World !" << std::endl << RESET;
	std::cout << BG_RED << "Hello World !" << std::endl << BG_RESET;
	std::cout << BG_GREEN << "Hello World !" << std::endl << BG_RESET;
	std::cout << BG_YELLOW << "Hello World !" << std::endl << BG_RESET;
	std::cout << BG_BLUE << "Hello World !" << std::endl << BG_RESET;
	std::cout << BG_MAGENTA << "Hello World !" << std::endl << BG_RESET;
	std::cout << BG_CYAN << "Hello World !" << std::endl << BG_RESET;
	std::cout << CURSOR_UP << "Hello World !" << std::endl << RESET;
	std::cout << CURSOR_DOWN << "Hello World !" << std::endl << RESET;
	std::cout << CURSOR_RIGHT << "Hello World !" << std::endl << RESET;
	std::cout << CURSOR_LEFT << "Hello World !" << std::endl << RESET;
	std::cout << CLEAN_SCREEN << "Hello World !" << std::endl << RESET;
	

	std::cout << "Input a word: ";
	//std::cin >> buff; // Recibe una palabra
	std::getline(std::cin, buff); // Recibe una string, incluyendo espacios, hasta detectar un salto de línea
	std::cout << "You entered: [" << buff << "]" << std::endl;
	std::cout << "You entered: " << buff << std::endl;

	return (0);
}