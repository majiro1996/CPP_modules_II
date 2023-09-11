/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:12:52 by manujime          #+#    #+#             */
/*   Updated: 2023/09/11 17:02:58 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

bool	ScalarConverter::_isChar(std::string str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return (true);
	return (false);
}

//To check if a string is a float or double, use std::stof() and std::stod()
//they will throw an exception if the string is not the correct type

bool	ScalarConverter::_isInt(std::string str)
{
	try
	{
		std::stoi(str);
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
		std::stof(str);
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
		std::stod(str);
	}
	catch (std::exception &e)
	{
		return (false);
	}
	return (true);
}



void ScalarConverter::_convert(std::string str)
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
