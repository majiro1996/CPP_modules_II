/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:12:52 by manujime          #+#    #+#             */
/*   Updated: 2023/09/11 13:33:47 by manujime         ###   ########.fr       */
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

//Q:Does stof() handle -inff, +inff, nanf, -inf, +inf, nan?
//A:Yes, it does. It will throw an exception if the string is not the correct type

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

//Q: how do I handle -inff, +inff, nanf, -inf, +inf, nan?
//A: use std::isinf() and std::isnan() to check if the float is infinite or nan
