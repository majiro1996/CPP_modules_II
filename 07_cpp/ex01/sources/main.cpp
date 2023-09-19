/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:44:06 by manujime          #+#    #+#             */
/*   Updated: 2023/09/19 12:26:21 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Template.hpp"

int	main(void)
{
    int     a[5] = {1, 2, 3, 4, 5};

    iter(a, 5, testPrint);

    std::cout << std::endl;

    std::string b[5] = {"one", "two", "three", "four", "five"};

    iter(b, 5, testPrint);

    return (0);
}