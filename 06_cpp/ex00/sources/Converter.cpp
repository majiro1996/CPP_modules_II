/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:12:52 by manujime          #+#    #+#             */
/*   Updated: 2023/09/20 12:15:40 by manujime         ###   ########.fr       */
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

static int myStoi(std::string &str)
{
	int num;
	std::stringstream ss(str);

	ss >> num;
	return (num);
}

static int  myStof(std::string str)
{
	float n;
	std::stringstream ss(str);

	ss >> n;
	return (n);
}

static int myStod(std::string str)
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
	if (isPseudoFloat(str) || isPseudoDouble(str))
		return (false);
	if (str.at(0) == '-' || str.at(0) == '+' || isdigit(str.at(0)))
	{
		for (size_t i = 1; i < str.length(); i++)
		{
			if (!isdigit(str.at(i)))
				return (false);
		}
	}
	return (true);
}

static bool isFloat(std::string str)
{
	int pCount = 0;
	int fCount = 0;

	if (isPseudoFloat(str))
		return (true);
	if (str.at(str.length() - 1) != 'f')
		return (false);
	if (str.at(0) == '-' || str.at(0) == '+' || isdigit(str.at(0)))
	{
		for (size_t i = 1; i < str.length(); i++)
		{
			if (str.at(i) == '.')
				pCount++;
			if (str.at(i) == 'f')
				fCount++;
			else if (!isdigit(str.at(i)))
				return (false);
		}
	}
	if (pCount != 1 || fCount != 1)
		return (false);
	return (true);
}

static bool isDouble(std::string str)
{
	try
	{
		myStod(str);
	}
	catch (std::exception &e)
	{
		return (false);
	}
	return (true);
}

static void _convertChar(std::string str)
{
	std::cout << "char: '" << str[0] << "'" << std::endl;
	char	c = str[0];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void _convertInt(std::string str)
{
	std::cout << "int: " << str << std::endl;
	int		i = myStoi(str);

	if (i < 32 || i > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

static void _converFloatPL(std::string str)
{
	std::cout << "float: " << str << std::endl;
	float	f = myStof(str);

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
}

static void _convertFloat(std::string str)
{
	if (isPseudoFloat(str))
	{
		_converFloatPL(str);
		return ;
	}
	
	std::cout << "float: " << str << std::endl;
	float	f = myStof(str);

	if (f < 32 || f > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
}

static void _converDobublePL(std::string str)
{
	std::cout << "double: " << str << std::endl;
	double	d = myStod(str);

	if (d < 32 || d > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

static void _convertDouble(std::string str)
{
	if (isPseudoDouble(str))
	{
		_converDobublePL(str);
		return ;
	}
	std::cout << "double: " << str << std::endl;
	double	d = myStod(str);

	if (d < 32 || d > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "0.f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

enum Type
{
	_char,
	_int,
	_float,
	_double,
	_error
};

static Type getType(const std::string str)
{
	if (isChar(str))
		return (_char);
	if (isInt(str))
		return (_int);
	if (isFloat(str) || isPseudoFloat(str))
		return (_float);
	if (isDouble(str) || isPseudoDouble(str))
		return (_double);
	return (_error);
}

void ScalarConverter::convert(std::string str)
{
	switch (getType(str))
	{
		case _char:
			_convertChar(str);
			break;
		case _int:
			_convertInt(myStoi(str)); //fix this
			break;
		case _float:
			_convertFloat(str);
			break;
		case _double:
			_convertDouble(str);
			break;
		default:
			std::cout << "Error: invalid input" << std::endl;
			break;
	}
}
