#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
private:
	std::string _filePath;
	// map ois for key value pair
	// map will self sort 
	std::map<std::string, float> _bitcoinRate;
	std::string	_date;
	float _value;
public:
	BitcoinExchange(std::string file);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();
	int 	processInput();
	int		parseRate();
	int		checkDate(std::string date);
	int		checkValue(std::string valueStr);
	void	getResult();
	int		strdigit(std::string str);
	int		strdigit2(std::string str);
    void	printRates() const;
};

#endif