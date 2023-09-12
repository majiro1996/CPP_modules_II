/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:07:01 by manujime          #+#    #+#             */
/*   Updated: 2023/09/12 13:16:47 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream> // std::cout
# include <string> // std::string
# include <cmath> // std::isnan
# include <limits> // std::numeric_limits
# include <iomanip> // std::setprecision
# include <sstream> // std::stringstream

class ScalarConverter
{
	private:

		static int myStoi(std::string str);
		static int myStof(std::string str);
		static int myStod(std::string str);
		static int myStold(std::string str);

		static bool	_isChar(std::string str);
		static bool	_isInt(std::string str);
		static bool	_isFloat(std::string str);
		static bool	_isDouble(std::string str);

		static void	_convertChar(std::string str);
		static void	_convertInt(std::string str);
		static void	_convertFloat(std::string str);
		static void	_convertDouble(std::string str);

		class NotConvertibleException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("impossible");
				}
		};

	public:
		static void	convert(std::string str);
};

#endif