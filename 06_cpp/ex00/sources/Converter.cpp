/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:12:52 by manujime          #+#    #+#             */
/*   Updated: 2023/09/18 01:13:41 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Converter.hpp"

static bool isPseudoDouble(std::string str)
{
	if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf")
		return (true);
	return (false);
}

static bool isPseudoFloat(std::string str)
{
	if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff")
		return (true);
	return (false);
}

int  ScalarConverter::myStoi(std::string str)
{
	int result = 0;
	int sign = 1;
	std::string::iterator it = str.begin(); 

	if (*it == '-')
	{
		sign = -1;
		it++;
	}
	while (it != str.end())
	{
		if (!isdigit(*it))
			throw ScalarConverter::BadArgumentException();
		result = result * 10 + (*it - '0');
		it++;
	}
	if (result * sign < std::numeric_limits<int>::min() ||
		result * sign > std::numeric_limits<int>::max())
		throw ScalarConverter::OutOfRangeException();
	return (result * sign);
}

int  ScalarConverter::myStof(std::string str)
{
	float result = 0;
	float sign = 1;
	std::string::iterator it = str.begin();

	if (*it == '-')
	{
		sign = -1;
		it++;   
	}

	while (isdigit(*it))
	{
		result = result * 10 + (*it - '0');
		it++;
	}
	if (*it == '.')
	{
		it++;
		float dec = 1;
		while (isdigit(*it))
		{
			dec /= 10;
			result += dec * (*it - '0');
			it++; 
		}
	}
	if (result * sign < std::numeric_limits<float>::min() ||
		result * sign > std::numeric_limits<float>::max())
		throw ScalarConverter::OutOfRangeException();
	return (result * sign);
}

int  ScalarConverter::myStod(std::string str)
{
	double n;
	std::stringstream ss(str);

	ss >> n;
	return (n);
}

bool	ScalarConverter::_isChar(std::string str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return (true);
	return (false);
}

bool	ScalarConverter::_isInt(std::string str)
{
	try
	{
		ScalarConverter::myStoi(str);
	}
	catch (std::exception &e)
	{
		return (false);
	}
	return (true);
}

bool	ScalarConverter::_isFloat(std::string str)
{
	try
	{
		ScalarConverter::myStof(str);
	}
	catch (std::exception &e)
	{
		return (false);
	}
	return (true);
}

bool	ScalarConverter::_isDouble(std::string str)
{
	try
	{
		ScalarConverter::myStod(str);
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
