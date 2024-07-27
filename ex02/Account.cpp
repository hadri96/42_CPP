/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:06:46 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/27 17:06:46 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	std::chrono::system_clock::time_point	now;
	std::time_t								now_time;
	std::tm 								*local_time;

	now = std::chrono::system_clock::now();
	now_time = std::chrono::system_clock::to_time_t(now);
	local_time = std::localtime(&now_time);
	std::cout << std::put_time(local_time, "[%Y%m%d_%H%M%S] ");
}

Account::Account() {}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << initial_deposit << ";created" << std::endl;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

Account::~Account()
{
	_displayTimestamp();
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
	_nbAccounts--;
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "deposits:" << _nbDeposits << ";"
			  << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			  << "total:" << getTotalAmount() << ";"
			  << "deposits:" << getNbDeposits() << ";"
			  << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_totalNbDeposits++;
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";"
			  << "deposit:" << deposit << ";"
			  << "amount:" << _amount + deposit << ";"
			  << "nb_deposits:" << ++_nbDeposits << std::endl;
	_amount += deposit;
}
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";";
	if (withdrawal >= _amount)
	{
		std::cout << "withdrawal: refused" << std::endl;
		return (false);
	}
	_totalNbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ";"
			  << "amount:" << _amount - withdrawal << ";"
			  << "nb_withdrawals:" << ++_nbWithdrawals << std::endl;
	_amount -= withdrawal;
	return (true);
}
int Account::checkAmount(void) const
{
	return (_amount);
}
