/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:44:06 by manujime          #+#    #+#             */
/*   Updated: 2023/10/18 13:18:01 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int	main(void)
{   
    try
    {
        Span    sp = Span(5);

        sp.addRandom(5);

        std::cout << "test 1 ints: " << sp << std::endl;
        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp.longestSpan() << std::endl;
        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        std::cout << std::endl;
    }

    try
    {
        Span    sp3 = Span(10);

        sp3.addNumber(42);
        std::cout << "test 2 ints: " << sp3 << std::endl;
        std::cout << sp3.shortestSpan() << std::endl;
        std::cout << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }

    try
    {
        Span    sp3 = Span(10);

        sp3.addNumber(42);
        std::cout << "test 3 ints: " << sp3 << std::endl;
        std::cout << sp3.longestSpan() << std::endl;
        std::cout << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << std::endl;
    }
}