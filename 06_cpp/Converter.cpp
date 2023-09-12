/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:12:52 by manujime          #+#    #+#             */
/*   Updated: 2023/09/12 15:37:01 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int  ScalarConverter::myStoi(std::string str)
{

}

bool	ScalarConverter::_isChar(std::string str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return (true);
	return (false);
}

bool	ScalarConverter::_isInt(std::string str)
{
	const char	*ptr = str.c_str();
	char		*endptr;
	std::strtol(ptr, &endptr, 10);

	if (*endptr != '\0')
		return (false);
	return (true);
}

bool	ScalarConverter::_isFloat(std::string str)
{
	
}

bool	ScalarConverter::_isDouble(std::string str)
{
	try
	{
		std::stod(str);
	}
	catch (std::exception &e)
	{
		return (false);
	}
	return (true);
}

void	ScalarConverter::_convertChar(std::string str)
{
	std::cout << "char: '" << str[0] << "'" << std::endl;
	char	c = str[0];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::_convertInt(std::string str)
{
	std::cout << "int: " << str << std::endl;
	int		i = std::stoi(str);

	if (i < 32 || i > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	ScalarConverter::_convertFloat(std::string str)
{
	std::cout << "float: " << str << "f" << std::endl;
	float	f = std::stof(str);

	if (f < 32 || f > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	ScalarConverter::_convertDouble(std::string str)
{
	std::cout << "double: " << str << std::endl;
	double	d = std::stod(str);

	if (d < 32 || d > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	if (_isChar(str))
		_convertChar(str);
	else if (_isInt(str))
		_convertInt(str);
	else if (_isFloat(str))
		_convertFloat(str);
	else if (_isDouble(str))
		_convertDouble(str);
	else
		std::cout << "impossible" << std::endl;
}
