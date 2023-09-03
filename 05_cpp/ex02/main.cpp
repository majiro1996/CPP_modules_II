/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:02:38 by manujime          #+#    #+#             */
/*   Updated: 2023/09/03 18:05:08 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
    Bureaucrat	b1("B1", 1);
    Bureaucrat	b2("B2", 150);
    AForm		f1("F1", 1, 1);
    AForm		f2("F2", 150, 150);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;

    b2.signForm(f1);
    std::cout << f1 << std::endl;
    b1.signForm(f1);
    std::cout << f1 << std::endl;
    b2.signForm(f2);
    std::cout << f2 << std::endl;

    return (0);
}