#include "BitcoinExchange.hpp"

/* Constructors */

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& other ) {
	if (this != &other) {
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
}


/* Getters + Erase */

std::map<std::string, double> BitcoinExchange::getUserDVM() {
	return userDVM;
}

double BitcoinExchange::getBitcoin() {
	return bitcoin;
}

void BitcoinExchange::eraseUserDVM() {
	userDVM.erase(userDVM.begin(), userDVM.end());;
}

/* STATISTIC FUNCTIONS */

/* Sub Functions */

// A year is a leap year if it is divisible by 4,
// but not divisible by 100, unless it is also divisible by 400.
int BitcoinExchange::daysInMonth(int year, int month) {
	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear ? 29 : 28;
        default:
            return 0;
    }
}

bool BitcoinExchange::regexFunc( std::string line, std::string strFormat ) {
	std::regex format(strFormat);
	return std::regex_match(line, format);
}

/* Functions used for genKeyValueForDVM && bitcoinValue */

bool	BitcoinExchange::keyFormat( std::string line ) {

	size_t pos1 = line.find('-');
	size_t pos2 = line.find('-', pos1 + 1);

	int year = 0;
	int month = 0;
	int day = 0;

	try {
		year = std::stoi(line.substr(0, pos1));
		month = std::stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
		day = std::stoi(line.substr(pos2 + 1));
	} catch ( std::invalid_argument &e ) {
		return false;
	}

	if (year < 0 || month < 1 || month > 12 || day < 0 || day > daysInMonth(year, month))
		return false;
	return true;
}

bool BitcoinExchange::setValues( bool DVM, std::string line ) {
	std::string key;
	double value;

	if (DVM) {
		key = line.substr(0, line.find(" "));
		try {
			value = std::stod(line.substr(line.find(" ") + 3));
		}
		catch ( std::invalid_argument &e ) {
			return false;
		}
		userDVM[key] = value;
	} else {
		key = line.substr(0, line.find(","));
		try { 
			value = std::stod(line.substr(line.find(",") + 1));
		}
		catch ( std::invalid_argument &e ) {
			return false;
		}
		csvCon[key] = value;
	}
	return true;
}

/* For User Input File */

bool BitcoinExchange::genKeyValueForDVM( const std::string line ) {
	if (!regexFunc(line, "\\d{4}-\\d{2}-\\d{2} \\| (-?\\d+(\\.\\d*)?|-?\\.\\d+)")
		|| !keyFormat(line))
		return false;

	return setValues(true, line);
}



/* Search and Calc his Pocket of Bitcoins Value */

std::tm BitcoinExchange::stringToDate(const std::string& dateStr) {
    std::tm tm = {};
    std::istringstream ss(dateStr);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    return tm;
}

int BitcoinExchange::dateDifference(const std::tm& date1, const std::tm& date2) {
    auto tp1 = std::chrono::system_clock::from_time_t(std::mktime(&const_cast<std::tm&>(date1)));
    auto tp2 = std::chrono::system_clock::from_time_t(std::mktime(&const_cast<std::tm&>(date2)));
    auto duration = std::chrono::duration_cast<std::chrono::hours>(tp2 - tp1).count();
    return std::abs(duration / 24);
}

bool BitcoinExchange::isClosest(std::map<std::string, double>::iterator it) {
	std::tm check = stringToDate(userDVM.begin()->first);
	std::tm first = stringToDate(it->first);
	std::tm second = stringToDate(std::next(it)->first);

	int diff1 = dateDifference(check, first);
	int diff2 = dateDifference(check, second);

	std::time_t check_time = std::mktime(&check);
	std::time_t second_time = std::mktime(&second);

	if (second_time > check_time)
		return true;
	if (diff1 > diff2)
		return false;
	return true;
}

int BitcoinExchange::searchPocketValue() {

	std::map<std::string, double>::iterator it = csvCon.begin();
	while (it != csvCon.end()) {
		if (isClosest(it))
			break;
		it++;
    }
	bitcoin = it->second;
	if (it == csvCon.end())
		return false;
	return true;
}

/* DATA.CSV */

bool	BitcoinExchange::bitcoinValue() {
	std::ifstream inFile("data.csv");
	if (!inFile)
		return false;
	std::string line;

	std::getline(inFile, line);
	if (line != "date,exchange_rate") {
		inFile.close();
		return false;
	}
	while (std::getline(inFile, line)) {
		if (!regexFunc(line, "\\d{4}-\\d{2}-\\d{2},(\\d+(\\.\\d*)?|\\.\\d+)")
			|| !keyFormat(line)) {
			inFile.close();
			return false;
		}
		setValues(false, line);
	}

	inFile.close();
	return searchPocketValue();
}