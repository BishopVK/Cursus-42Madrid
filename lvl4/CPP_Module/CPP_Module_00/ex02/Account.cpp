/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:51:20 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/26 14:24:08 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

#define BLUE "\033[34m"
#define WHITE "\033[37m"
#define RESET "\033[0m"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;

	std::string	account_index = BLUE + std::to_string(this->_accountIndex) + RESET;
	std::string	amount = BLUE + std::to_string(this->_amount) + RESET;

	Account::_displayTimestamp();
	std::cout << " index:" << account_index // Index
	<< ";amount:" << amount // amount
	<< ";created" << std::endl; // created
}

Account::~Account(void)
{
	std::string	account_index = BLUE + std::to_string(this->_accountIndex) + RESET;
	std::string	amount = BLUE + std::to_string(this->_amount) + RESET;

	Account::_displayTimestamp();
	std::cout << " index:" << account_index // Index
	<< ";amount:" << amount // amount
	<< ";closed" << std::endl; // created
}

void	Account::_displayTimestamp( void )
{
	time_t	t  = time(nullptr);
	struct tm *tmp = localtime(&t);

	std::cout << "[" << (1900 + tmp->tm_year) // Year
	<< std::setw(2) << std::setfill('0') << (tmp->tm_mon + 1) // Month
	<< std::setw(2) << tmp->tm_mday << "_" // Day
	<< std::setw(2) << tmp->tm_hour // Hour
	<< std::setw(2) << tmp->tm_min // Mins
	<< std::setw(2) << tmp->tm_sec << "]"; // Secs
}

void	Account::displayAccountsInfos( void )
{
	std::string	nbAccounts = BLUE + std::to_string(Account::_nbAccounts) + RESET;
	std::string	totalAmount = BLUE + std::to_string(Account::_totalAmount) + RESET;
	std::string	totalNbDeposits = BLUE + std::to_string(Account::_totalNbDeposits) + RESET;
	std::string	totalNbWithdrawals = BLUE + std::to_string(Account::_totalNbWithdrawals) + RESET;

	Account::_displayTimestamp();
	std::cout << " accounts:" << nbAccounts // Number of accounts
	<< ";total:" << totalAmount // Total amounts
	<< ";deposits:" << totalNbDeposits // Total number of deposits
	<< ";withdrawals:" << totalNbWithdrawals << std::endl; // Total number of withdrawals
}