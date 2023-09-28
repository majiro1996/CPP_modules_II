/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:44:06 by manujime          #+#    #+#             */
/*   Updated: 2023/09/28 18:42:40 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int	main(void)
{   
    Span    sp = Span(5);

    sp.addNumber(0);
    sp.addNumber(1);
    sp.addNumber(2);
    sp.addNumber(3);
    sp.addNumber(4);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << std::endl;
    std::cout << sp << std::endl;

    Span    sp2 = Span(10000);
    sp2.addRandom(10000);
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    std::cout << std::endl;
    std::cout << sp2 << std::endl;
    return (0);
}