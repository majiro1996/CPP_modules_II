/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:24:41 by manujime          #+#    #+#             */
/*   Updated: 2023/10/25 14:49:57 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

static bool tooBigNumber(std::string const &str)
{
	std::string			aux;

	if (str.length() > 11)
		return (true);
	if (str.length() == 11)
	{
		aux = str.substr(1, 11);
		if (aux.compare("2147483647") > 0)
			return (true);
	}
	return (false);
}

static float myStof(std::string const &str)
{
	std::stringstream	ss(str);
	float				ret;

	ss >> ret;
	return (ret);
}

static int myStoi(std::string const &str)
{
	std::stringstream	ss(str);
	int					ret;

	ss >> ret;
	return (ret);
}

BitcoinExchange::BitcoinExchange(void)
{
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &source)
{
	*this = source;
	return ;
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

std::map<std::string, float>	BitcoinExchange::getRates(void) const
{
	return (this->_rates);
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &source)
{
	if (this != &source)
	{
		this->_rates = source._rates;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, BitcoinExchange const &source)
{
	std::map<std::string, float> const	rates = source.getRates();

    for (std::map<std::string, float>::const_iterator it = rates.begin(); it != rates.end(); ++it)
    {
        o << it->first << ": " << it->second << std::endl;
    }
	return (o);
}

bool BitcoinExchange::dateSearch(std::string const &date) const
{
	std::map<std::string, float> const	rates = this->getRates();

	if (rates.count(date) > 0)
		return (true);
	return (false);
}

//checks that the date conforms to the format YYYY-MM-DD
bool	dateCheck(std::string date)
{
	int year = myStoi(date.substr(0, 4));
	int month = myStoi(date.substr(5, 2));
	int day = myStoi(date.substr(8, 2));
	
	if (/*date.length() != 9 || date.find("-") != 2 || */year < 2000
		|| year > 2023 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	return (true);
}

std::string BitcoinExchange::getDate(std::string const &date) const
{
	std::string ret = date.substr(0, date.find("|"));

	if (!dateCheck(ret))
		return ("NOT A VALID DATE");
	return (ret);
	
}

void	BitcoinExchange::takeRates(std::string const &filename)
{
	std::ifstream	rateData;
	std::string		line;
	std::string		key;
	float			value;

	rateData.open(filename.c_str());
	if (rateData.is_open())
	{
		while (std::getline(rateData, line))
		{
			key = line.substr(0, line.find(","));
			try
			{
				value = myStof(line.substr(line.find(",") + 1));
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			this->_rates.insert(std::pair<std::string, float>(key, value));
		}  
		rateData.close();
	} 
	else
	{
		std::cout << "Error: could not open " << filename << std::endl;
	}
}

static void reduceDate(int *year, int *month, int *day)
{
	if (*day > 1)
		(*day)--;
	else if (*month > 1)
	{
		(*month)--;
		(*day) = 31;
	}
	else
	{
		(*year)--;
		(*month) = 12;
		(*day) = 31;
	}
}

void  BitcoinExchange::closestDate(std::string const &date, float value) const
{
	std::stringstream	ss(date);
	std::string aux = date;
	int day = myStoi(date.substr(8, 2));
	int month = myStoi(date.substr(5, 2));
	int year = myStoi(date.substr(0, 4));

	while (!this->dateSearch(aux) && year > 2009)
	{
		ss.str("");
		reduceDate(&year, &month, &day);
		ss << year;
		if (month < 10)
			ss << "-0" << month;
		else
			ss << "-" << month;
		if (day < 10)
			ss << "-0" << day;
		else 
			ss << "-" << day;
		aux = ss.str();
	}
	if (this->dateSearch(aux))
		std::cout << date << "=> " << value << " = " << this->_rates.find(aux)->second * value << std::endl;
	else
		std::cout << date << "=> " << "no data" << std::endl;
}

void   BitcoinExchange::takeInput(std::string const &filename)
{
	std::ifstream	inputData;
	std::string		line;
	std::string		date;
	float			value;

	inputData.open(filename.c_str());
	if (inputData.is_open())
	{
		while (std::getline(inputData, line))
		{
			date = line.substr(0, line.find(" "));
			value = myStof(line.substr(line.find("|") + 1));
			if (line.find("|") == std::string::npos)
				std::cout << "Error: bad input => " << line << std::endl;
			else if (tooBigNumber(line.substr(line.find("|") + 1)))
				std::cout << "Error: too large" << std::endl;
			else if (!dateCheck(date))
				std::cout << "Error: bad date => " << date << std::endl;
			else if (value < 0)
				std::cout << "Error: negative value" << std::endl; 
			else if (this->dateSearch(date))
				std::cout << date << " => " << value << " = " << value * _rates[date] <<std::endl;
			else
				this->closestDate(date, value);
		}
		inputData.close();
	} 
	else
	{
		std::cout << "Error: could not open " << filename << std::endl;
	}
}
