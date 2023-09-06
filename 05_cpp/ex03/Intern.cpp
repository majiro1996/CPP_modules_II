/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:38:54 by manujime          #+#    #+#             */
/*   Updated: 2023/09/06 12:20:52 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	return ;
}

Intern::Intern(Intern const &source)
{
	*this = source;
	return ;
}

Intern::~Intern(void)
{
	return ;
}

Intern	&Intern::operator=(Intern const &source)
{
	(void)source;
	return (*this);
}

AForm  *Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm  *Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm  *Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm   *Intern::makeForm(std::string name, std::string target)
{
	AForm  *form;

	std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm *(Intern::*funcs[3])(std::string) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			form = (this->*funcs[i])(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}

	std::cout << "The form " << name << " does not exist." << std::endl;
	std::cout << "Choose from: " << std::endl;
	for (int j = 0; j < 3; j++)
	{
		std::cout << " - " << names[j] << std::endl;
	}
	return (NULL);
}