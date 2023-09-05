/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:02:38 by manujime          #+#    #+#             */
/*   Updated: 2023/09/05 20:10:27 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp" 

int main(void)
{
    Bureaucrat	b1("B1", 1);
    Bureaucrat	b2("B2", 150);

    PresidentialPardonForm	ppf("PPF");
    RobotomyRequestForm		rrf("RRF");
    ShrubberyCreationForm	scf("SCF");

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    std::cout << ppf << std::endl;
    std::cout << rrf << std::endl;
    std::cout << scf << std::endl;
    return (0);
}