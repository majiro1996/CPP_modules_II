/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:02:38 by manujime          #+#    #+#             */
/*   Updated: 2023/09/01 17:05:27 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat  b1("b1", 1);
    Bureaucrat  b2("b2", 150);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    try
    {
        Bureaucrat  b3("b3", 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat  b4("b4", 151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat  b5("b5", 1);
        b5.incrementGrade();
        std::cout << b5 << std::endl;
        b5.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat  b6("b6", 150);
        b6.decrementGrade();
        std::cout << b6 << std::endl;
        b6.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}