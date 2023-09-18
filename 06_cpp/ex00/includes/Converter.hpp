/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:07:01 by manujime          #+#    #+#             */
/*   Updated: 2023/09/18 15:03:23 by manujime         ###   ########.fr       */
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
	public:
		static void	convert(std::string str);
};

#endif