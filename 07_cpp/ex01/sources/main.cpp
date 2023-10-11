/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:44:06 by manujime          #+#    #+#             */
/*   Updated: 2023/10/11 17:01:43 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Template.hpp"

void   testString(std::string &a)
{
    a = a.substr(0, 2);
}

int	main(void)
{
    int     a[5] = {1, 2, 3, 4, 5};

    iter(a, 5, testPrint);
    iter(a, 5, testAdd);
    std::cout << std::endl;
    iter(a, 5, testPrint);

    std::cout << std::endl;

    std::string b[5] = {"one", "two", "three", "four", "five"};

    iter(b, 5, testPrint);
    iter(b, 5, testString);
    std::cout << std::endl;
    iter(b, 5, testPrint);
    
    return (0);
}