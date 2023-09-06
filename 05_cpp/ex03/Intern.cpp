/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:38:54 by manujime          #+#    #+#             */
/*   Updated: 2023/09/06 20:33:20 by manujime         ###   ########.fr       */
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

static AForm  *makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm  *makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm  *makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

const char* Intern::NotAFormException::what() const throw()
{
	return ("Not a form");
}

AForm   *Intern::makeForm(std::string name, std::string target)
{
	AForm  *form;

	std::string names[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*funcs[3])(std::string) = 
	{
		makeShrubberyCreationForm,
		makeRobotomyRequestForm,
		makePresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			form = (*funcs[i])(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}

	std::cout << "Choose from: " << std::endl;
	for (int j = 0; j < 3; j++)
	{
		std::cout << " - " << names[j] << std::endl;
	}
	return (NULL);
}