// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

// init static vars
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// default constructor
Account::Account(void)
    : _accountIndex(_nbAccounts), _amount(0), _nbDeposits(0),
      _nbWithdrawals(0) {
  Account::_nbAccounts++;
  return;
}

// constructor
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0),
      _nbWithdrawals(0) {
  Account::_nbAccounts++;
  Account::_totalAmount += _amount;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created"
            << std::endl;
  return;
}

// destructor
Account::~Account(void) {
  Account::_nbAccounts--;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed"
            << std::endl;
  return;
}

// getters
int Account::getNbAccounts(void) { return (_nbAccounts); }
int Account::getTotalAmount(void) { return (_totalAmount); }
int Account::getNbDeposits(void) { return (_totalNbDeposits); }
int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }

// print info of all accounts combined
void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals() << std::endl;
  return;
}

// make a deposit into the account
// p_amount: previous amount
// deposit: amount to be deposited
// amount: new amount
// nb_deposits: number of deposits
void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
            << ";deposit:";
  this->_amount += deposit;
  Account::_totalAmount += deposit;
  this->_nbDeposits++;
  Account::_totalNbDeposits++;
  std::cout << deposit << ";amount:" << this->_amount
            << ";nb_deposits:" << this->_nbDeposits << std::endl;
  return;
}

// make a withdrawal into the account
// p_amount: previous amount
// deposit: amount to be withdrawed
// amount: new amount
// nb_withdrawals: number of withdrawals
bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
            << ";withdrawal:";
  if (withdrawal > this->_amount) {
    std::cout << "refused" << std::endl;
    return (false);
  } else {
    this->_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
  }
  return (true);
}

// returns amount of the current object
int Account::checkAmount(void) const { return (this->_amount); }

// display account info of an Account object
void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount
            << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
            << std::endl;
  return;
}

// print a timestamp of the current date and time
// format: [YYYYMMDD_HHMMSS]
void Account::_displayTimestamp(void) {
	std::time_t timeNow;
	struct tm *timeStruct;
	
	std::time(&timeNow);
	timeStruct = std::localtime(&timeNow);
	
	std::cout << "[" << timeStruct->tm_year + 1900 <<
	std::setfill('0') << std::setw(2) << timeStruct->tm_mon + 1 <<
	std::setfill('0') << std::setw(2) << timeStruct->tm_mday <<
	"_" <<
	std::setfill('0') << std::setw(2) << timeStruct->tm_hour <<
	std::setfill('0') << std::setw(2) << timeStruct->tm_min <<
	std::setfill('0') << std::setw(2) << timeStruct->tm_sec <<
	"] ";
	// std::cout << "[19920104_091532] ";
}
