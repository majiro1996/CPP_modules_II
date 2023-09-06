/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:02:38 by manujime          #+#    #+#             */
/*   Updated: 2023/09/06 14:55:37 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"


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
    Intern  someRandomIntern;

    AForm*  presi = someRandomIntern.makeForm("presidential pardon", "Bender");
    AForm*  robo = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm*  shrub = someRandomIntern.makeForm("shrubbery creation", "Bender");

    std::cout << std::endl;

    formTest(*shrub, 137,145);
    formTest(*robo, 45, 72);
    formTest(*presi, 5,25);

    delete presi;
    delete robo;
    delete shrub;

    return (0);
}