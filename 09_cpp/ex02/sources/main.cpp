/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:44:06 by manujime          #+#    #+#             */
/*   Updated: 2023/10/31 00:02:57 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Pmergeme.hpp"

static bool inputCheck(std::string str)
{
    if (str.find_first_not_of(" 0123456789") != std::string::npos)
        return (false);
    return (true);
}

int	main(int argc, char **argv)
{
    Pmergeme  sortObj;
    if (argc == 1)
        return (0);
    for (int i = 1; i < argc; i++)
    {
        if (!inputCheck(argv[i]))
        {
            std::cout << "Invalid input." << std::endl;
            return (1);
        }
        sortObj.takeInput(argv[i]);
    }
    sortObj.sort();
    return (0);
}