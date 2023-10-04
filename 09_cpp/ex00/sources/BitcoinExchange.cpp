/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:24:41 by manujime          #+#    #+#             */
/*   Updated: 2023/10/04 19:01:53 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

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

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &source)
{
	if (this != &source)
	{
		this->_rates = source._rates;
	}
	return (*this);
}

//a valid date shoudl be Year-Month-Day
bool	BitcoinExchange::validDate(std::string const &str)
{
	return (true);
}

// a valid rate should be either a float or a positive integer ranged 0-1000
bool	BitcoinExchange::validValue(std::string const &str)
{
	std::stringstream	ss(str);
	float				num;

	ss >> num;
}

// the format should be "date | value"
bool	BitcoinExchange::validFormat(std::string const &str)
{
	return (true);
}
