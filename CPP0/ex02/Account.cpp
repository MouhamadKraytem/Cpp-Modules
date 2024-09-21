/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:19:27 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/21 19:38:55 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;

	std::cout << "[";
	_displayTimestamp();
	std::cout << "] index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

// Destructor
Account::~Account(void)
{
	_nbAccounts--;
	_totalAmount -= _amount;

	std::cout << "[";
	_displayTimestamp();
	std::cout << "] index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

// Static methods
int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	std::cout << "[";
	_displayTimestamp();
	std::cout << "] accounts:" << getNbAccounts()
			  << ";total:" << getTotalAmount()
			  << ";deposits:" << getNbDeposits()
			  << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

// Instance methods
void Account::makeDeposit(int deposit)
{
	if (deposit > 0)
	{
		_amount += deposit;
		_nbDeposits++;
		_totalAmount += deposit;
		_totalNbDeposits++;

		std::cout << "[";
		_displayTimestamp();
		std::cout << "] index:" << _accountIndex << ";p_amount:" << _amount - deposit
				  << ";deposit:" << deposit << ";amount:" << _amount
				  << ";nb_deposits:" << _nbDeposits << std::endl;
	}
	else
	{
		std::cout << "Deposit must be a positive amount." << std::endl;
	}
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > 0 && withdrawal <= _amount)
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;

		std::cout << "[";
		_displayTimestamp();
		std::cout << "] index:" << _accountIndex << ";p_amount:" << (_amount + withdrawal)
				  << ";withdrawal:" << withdrawal << ";amount:" << _amount
				  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;

		return true;
	}
	else
	{
		std::cout << "[";
		_displayTimestamp();
		std::cout << "] index:" << _accountIndex << ";p_amount:" << _amount
				  << ";withdrawal:refused" << std::endl;
		return false;
	}
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	std::cout << "[";
	_displayTimestamp();
	std::cout << "] index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
}

// Private utility methods
void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(0);
	std::tm *ltm = std::localtime(&now);
	std::cout << 1900 + ltm->tm_year
			  << (ltm->tm_mon < 9 ? "0" : "") << 1 + ltm->tm_mon
			  << (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday << "_"
			  << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour
			  << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min
			  << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec;
}

// Disable default constructor (Private constructor with no implementation)
Account::Account(void) {}
