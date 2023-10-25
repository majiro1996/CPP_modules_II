/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:50:00 by manujime          #+#    #+#             */
/*   Updated: 2023/10/25 14:49:05 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <sstream>
# include <fstream>
# include <limits>

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &source);
		~BitcoinExchange(void);

		BitcoinExchange &operator=(BitcoinExchange const &source);

		void   							takeInput(std::string const &filename);
		void   							takeRates(std::string const &filename);
		std::map<std::string, float>	getRates(void) const;

	private:
		std::map<std::string, float>	_rates;
		bool   							dateSearch(std::string const &date) const;
		void							closestDate(std::string const &date, float value) const;
		std::string						getDate(std::string const &date) const;
}; 

std::ostream	&operator<<(std::ostream &o, BitcoinExchange const &source);

#endif