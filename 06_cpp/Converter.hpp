/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:07:01 by manujime          #+#    #+#             */
/*   Updated: 2023/09/11 10:41:14 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <iomanip>
# include <sstream>

class ScalarConverter
{
	private:
		static bool	_isChar(std::string str);
		static bool	_isInt(std::string str);
		static bool	_isFloat(std::string str);
		static bool	_isDouble(std::string str);

		static void	_convertChar(std::string str);
		static void	_convertInt(std::string str);
		static void	_convertFloat(std::string str);
		static void	_convertDouble(std::string str);

	public:
		static void	convert(std::string str);
};

#endif