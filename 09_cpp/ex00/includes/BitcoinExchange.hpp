/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:50:00 by manujime          #+#    #+#             */
/*   Updated: 2023/10/19 19:08:34 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <sstream>
# include <fstream>

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &source);
		~BitcoinExchange(void);

		BitcoinExchange &operator=(BitcoinExchange const &source);

		bool   validFormat(std::string const &str);
		bool   validDate(std::string const &str);
		bool   validValue(std::string const &str);
		void   takeRates(std::string const &filename);

	private:
		std::map<std::string, float>	_rates;
};

#endif