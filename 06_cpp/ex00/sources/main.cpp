/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:44:06 by manujime          #+#    #+#             */
/*   Updated: 2023/09/18 15:53:42 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Converter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./Converter [string]" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}