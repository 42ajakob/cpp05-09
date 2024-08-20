#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <regex>
#include <sstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>

class BitcoinExchange {
	private:
		std::map<std::string, double> csvCon;
		std::map<std::string, double> userDVM;
		double bitcoin;

		BitcoinExchange( const BitcoinExchange& other );
		BitcoinExchange& operator=( const BitcoinExchange& other );

	public:
		BitcoinExchange();
		~BitcoinExchange();

		std::map<std::string, double> getUserDVM();
		double getBitcoin();

		void eraseUserDVM();

		static int daysInMonth(int year, int month);
		static bool regexFunc( std::string line, std::string strFormat );
		static bool	keyFormat( std::string line );
		bool setValues( bool DVM, std::string line );
		static std::tm stringToDate(const std::string& dateStr);
		static int dateDifference(const std::tm& date1, const std::tm& date2);
		bool isClosest(std::map<std::string, double>::iterator it);
		int searchPocketValue();

		bool genKeyValueForDVM( const std::string line );
		bool bitcoinValue();
};

#endif