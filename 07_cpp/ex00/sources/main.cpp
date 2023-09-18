/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:44:06 by manujime          #+#    #+#             */
/*   Updated: 2023/09/19 01:01:24 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Templates.hpp"
#include <iostream>


int	main(void)
{
    int a = 4;
    int b = 2;
    std::cout << "a: " << a << " b: " << b << std::endl;
    swap(a, b);
    std::cout << "a: " << a << " b: " << b << std::endl;
    std::cout << "min: " << ::min(a, b) << std::endl;
    std::cout << "max: " << ::max(a, b) << std::endl;
    std::cout << std::endl;

    std::string c = "something";
    std::string d = "else";
    std::cout << "c: " << c << " d: " << d << std::endl;
    swap(c, d);
    std::cout << "c: " << c << " d: " << d << std::endl;
    std::cout << "min: " << ::min(c, d) << std::endl;
    std::cout << "max: " << ::max(c, d) << std::endl;
    std::cout << std::endl;
    
    return (0);
}