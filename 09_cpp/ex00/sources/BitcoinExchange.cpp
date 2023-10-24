/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:24:41 by manujime          #+#    #+#             */
/*   Updated: 2023/10/24 13:41:00 by manujime         ###   ########.fr       */
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
		std::cout << "Error: could not open file" << std::endl;
	}
}
