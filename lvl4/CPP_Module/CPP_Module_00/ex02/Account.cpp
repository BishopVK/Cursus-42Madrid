/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:51:20 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 12:28:34 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>

#define BLUE "\033[34m"
#define WHITE "\033[37m"
#define RESET "\033[0m"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

std::string	blue(int nbr)
{
	std::stringstream ss;
	ss << nbr;
	
	std::string blueText = BLUE + ss.str() + RESET;
	return (blueText);
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;

	Account::_displayTimestamp();
	std::cout
	<< " index:" << blue(this->_accountIndex) // Index
	<< ";amount:" << blue(this->_amount) // amount
	<< ";created"
	<< std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout
	<< " index:" << blue(this->_accountIndex) // Index
	<< ";amount:" << blue(this->_amount) // amount
	<< ";closed"
	<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t	t  = time(NULL);
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
	Account::_displayTimestamp();
	std::cout
	<< " accounts:" << blue(Account::_nbAccounts) // Number of accounts
	<< ";total:" << blue(Account::_totalAmount) // Total amounts
	<< ";deposits:" << blue(Account::_totalNbDeposits) // Total number of deposits
	<< ";withdrawals:" << blue(Account::_totalNbWithdrawals) // Total number of withdrawals
	<< std::endl;
}

void Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout
	<< " index:" << blue(this->_accountIndex) // Index
	<< ";amount:" << blue(this->_amount) // amount
	<< ";deposits:" << blue(this->_nbDeposits) // deposits
	<< ";withdrawals:" << blue(this->_nbWithdrawals) // withdrawals
	<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout
	<< " index:" << blue(this->_accountIndex) // Index
	<< ";p_amount:" << blue(this->_amount); // previous amount before deposit
	
	this->_amount += deposit;
	this->_nbDeposits++;

	std::cout
	<< ";deposit:" << blue(deposit) // deposit
	<< ";amount:" << blue(this->_amount) // amount after deposit
	<< ";nb_deposits:" << blue(this->_nbDeposits) // number of deposits
	<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > this->_amount)
	{
		Account::_displayTimestamp();
		std::cout
		<< " index:" << blue(this->_accountIndex) // Index
		<< ";p_amount:" << blue(this->_amount) // previous amount before withdrawal
		<< ";withdrawal:refused"
		<< std::endl;
		return (false);
	}

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;

	Account::_displayTimestamp();
	std::cout
	<< " index:" << blue(this->_accountIndex) // Index
	<< ";p_amount:" << blue(this->_amount); // previous amount before withdrawal

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;

	std::cout
	<< ";withdrawal:" << blue(withdrawal) // deposit
	<< ";amount:" << blue(this->_amount) // amount after withdrawal
	<< ";nb_withdrawals:" << blue(this->_nbWithdrawals) // number of withdrawal
	<< std::endl;

	return (true);
}