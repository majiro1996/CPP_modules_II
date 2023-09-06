/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:02:38 by manujime          #+#    #+#             */
/*   Updated: 2023/09/06 08:32:48 by manujime         ###   ########.fr       */
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

    PresidentialPardonForm	presi("presi");
    RobotomyRequestForm		robo("robo");
    ShrubberyCreationForm	shrub("shrub");

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    std::cout << presi << std::endl;
    std::cout << robo << std::endl;
    std::cout << shrub << std::endl;

    b1.signForm(presi);
    b1.signForm(robo);
    b1.signForm(shrub);

    b1.executeForm(presi);
    b1.executeForm(robo);
    b1.executeForm(shrub);
    return (0);
}