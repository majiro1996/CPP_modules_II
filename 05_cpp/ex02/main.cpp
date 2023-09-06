/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:02:38 by manujime          #+#    #+#             */
/*   Updated: 2023/09/06 10:22:14 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp" 


void formTest(AForm &f, int gradeA, int gradeB)
{

    Bureaucrat	b("B", gradeB);
    Bureaucrat	a("A", gradeA);
    
    std::cout << f << std::endl;
    std::cout << b << std::endl;
    std::cout << a << std::endl;

    b.signForm(f);
    b.executeForm(f);
    std::cout << f << std::endl;
    a.signForm(f);
    a.executeForm(f);
    std::cout << f << std::endl;

    std::cout << std::endl;
}

int main(void)
{
    PresidentialPardonForm	presi("presi");
    PresidentialPardonForm  presi2(presi);
    RobotomyRequestForm		robo("robo");
    RobotomyRequestForm     robo2(robo);
    ShrubberyCreationForm	shrub("shrub");
    ShrubberyCreationForm   shrub2(shrub);

    formTest(shrub, 137,145);
    formTest(shrub2, 144, 150);
    formTest(robo, 45, 72);
    formTest(robo2, 71, 137);
    formTest(presi, 5,25);
    formTest(presi2, 26, 137);

    return (0);
}