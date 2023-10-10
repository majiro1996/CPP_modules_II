/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:07:01 by manujime          #+#    #+#             */
/*   Updated: 2023/10/10 15:22:44 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream> // std::cout
# include <string> // std::string
# include <sstream> // std::stringstream

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &source);
		~ScalarConverter(void);
		ScalarConverter &operator=(ScalarConverter const &source);

	public:
		static void	convert(std::string str);
};

#endif