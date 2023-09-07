/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:38:54 by manujime          #+#    #+#             */
/*   Updated: 2023/09/07 09:44:32 by manujime         ###   ########.fr       */
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

static int formPos(std::string name)
{
	std::string names[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
			return (i);
	}

	throw Intern::NotAFormException();
}

AForm   *Intern::makeForm(std::string name, std::string target)
{
	AForm  *form;

	try 
	{
		AForm* (*funcs[3])(std::string) = 
		{
			makeShrubberyCreationForm,
			makeRobotomyRequestForm,
			makePresidentialPardonForm
		};
		
		formPos(name);
		form = funcs[formPos(name)](target);
		std::cout << "Intern creates " << form->getName() << " for " << target << std::endl;
		return (form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (NULL);
	}

}