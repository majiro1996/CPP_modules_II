/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:44:06 by manujime          #+#    #+#             */
/*   Updated: 2023/10/24 17:53:04 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
    BitcoinExchange	btc;

    if (argc != 2)
    {
        std::cout << "Usage: ./bitcoin [filename]" << std::endl;
        return (1);
    }

    btc.takeRates("data.csv");
    btc.takeInput(argv[1]);
    //std::cout << "BTC/USD: " << btc << std::endl;
    return (0);
}