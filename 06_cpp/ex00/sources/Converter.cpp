/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:12:52 by manujime          #+#    #+#             */
/*   Updated: 2023/10/04 18:06:05 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Converter.hpp"

ScalarConverter::ScalarConverter(void)
{
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
	return ;
}

ScalarConverter::~ScalarConverter(void)
{
	return ;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &source)
{
	(void)source;
	return (*this);
}

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

static int myStoi(std::string &str)
{
	int num;
	std::stringstream ss(str);

	ss >> num;
	return (num);
}

static float  myStof(std::string str)
{
	float n;
	std::stringstream ss(str);

	ss >> n;
	return (n);
}

static double myStod(std::string str)
{
	double n;
	std::stringstream ss(str);

	ss >> n;
	return (n);
}

static bool isChar(std::string str)
{
	if (str.length() == 1 && str.at(0) >= 32 && str.at(0) <= 126)
		return (true);
	return (false);
}

static bool isInt(std::string str)
{
	int c = 0;
	if (str.at(0) == '-' || str.at(0) == '+')
		c = 1;
	for (size_t i = c; i < str.length(); i++)
	{
		if (!isdigit(str.at(i)))
			return (false);
	} 
	return (true);
}

static bool isFloat(std::string str)
{
	int pCount = 0;
	int fCount = 0;

	if (str.at(str.length() - 1) != 'f')
		return (false);
	if (str.at(0) == '-' || str.at(0) == '+' || isdigit(str.at(0)))
	{
		for (size_t i = 1; i < str.length(); i++)
		{
			if (str.at(i) == '.')
			{
				pCount++;
				continue;
			}
			if (str.at(i) == 'f')
				fCount++;
			else if (!isdigit(str.at(i)))
				return (false);
		}
	}
	if (pCount > 1 || fCount > 1)
		return (false); 
	return (true);
}

static bool isDouble(std::string str)
{
	int pCount = 0;

	if (str.at(str.length() - 1) == 'f')
		return (false);
	if (str.at(0) == '-' || str.at(0) == '+' || isdigit(str.at(0)))
	{
		for (size_t i = 1; i < str.length(); i++)
		{
			if (str.at(i) == '.')
				pCount++;
			else if (!isdigit(str.at(i)))
				return (false);
		}
	}
	if (pCount != 1)
		return (false); 
	return (true);
}

static void _convertChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void _convertInt(int nbr)
{
	std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	std::cout << "int: " << nbr << std::endl;
	std::cout << "float: " << static_cast<float>(nbr) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(nbr) << ".0" << std::endl;
}

static void _converFloatPL(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << std::endl;
	std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
}

static void _convertFloat(float f)
{
	if (f < 32 || f > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static void _converDobublePL(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
}

static void _convertDouble(double d)
{
	if (d < 32 || d > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

enum Type
{
	_char,
	_int,
	_float,
	_double,
	_error,
	_pseudo
};

static Type getType(const std::string str)
{
	if (isPseudoFloat(str) || isPseudoDouble(str))
		return (_pseudo);
	if (isChar(str))
		return (_char);
	if (isInt(str))
		return (_int);
	if (isFloat(str))
		return (_float);
	if (isDouble(str))
		return (_double);
	return (_error);
}

void ScalarConverter::convert(std::string str)
{
	switch (getType(str))
	{
		case _char:
			_convertChar(str[0]);
			break;
		case _float:
			_convertFloat(myStof(str));
			break;
		case _double:
			_convertDouble(myStod(str));
			break;
		case _pseudo:
			if (isPseudoFloat(str))
				_converFloatPL(str);
			else
				_converDobublePL(str);
			break;
		case _int:
			_convertInt(myStoi(str));
			break;
		default:
			std::cout << "Error: invalid input" << std::endl;
			break;
	}
	//std::cout << getType(str) << std::endl;
}
