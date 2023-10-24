/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:24:41 by manujime          #+#    #+#             */
/*   Updated: 2023/10/24 19:48:58 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

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
	if (date.length() != 10)
		return (false);
	if (date.find("-") != 2)
		return (false);
	int year = myStoi(date.substr(0, 4));
	if (year < 2000 || year > 2023)
		return (false);
	int month = myStoi(date.substr(5, 2));
	if (month < 1 || month > 12)
		return (false);
	int day = myStoi(date.substr(8, 2));
	if (day < 1 || day > 31)
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

static bool isHigherDate(std::string const &date1, std::string const &date2)
{
	int	year1 = myStoi(date1.substr(0, 4));
	int	year2 = myStoi(date2.substr(0, 4));
	int	month1 = myStoi(date1.substr(5, 2));
	int	month2 = myStoi(date2.substr(5, 2));
	int	day1 = myStoi(date1.substr(8, 2));
	int	day2 = myStoi(date2.substr(8, 2));

	if (year1 > year2)
		return (true);
	else if (year1 == year2)
	{
		if (month1 > month2)
			return (true);
		else if (month1 == month2)
		{
			if (day1 > day2)
				return (true);
		}
	}
	return (false);
}

void  BitcoinExchange::closestDate(std::string const &date) const
{
	std::string aux = date;
	while (!this->dateSearch(aux))
	{
		if (isHigherDate(aux, date))
			aux = aux.substr(0, 4) + "-" + aux.substr(5, 2) + "-" + std::to_string(myStoi(aux.substr(8, 2)) - 1);
		else
			aux = aux.substr(0, 4) + "-" + aux.substr(5, 2) + "-" + std::to_string(myStoi(aux.substr(8, 2)) + 1);
	}
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
			
			if (value < 0)
				std::cout << "Error: negative value" << std::endl;
			else if (this->dateSearch(date))
				std::cout << date << "=> " << value << std::endl;
			else
				std::cout << date << ": " << "no data" << std::endl;
		}
		inputData.close();
	} 
	else
	{
		std::cout << "Error: could not open " << filename << std::endl;
	}
}
