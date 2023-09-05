/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:56:15 by manujime          #+#    #+#             */
/*   Updated: 2023/09/05 20:20:46 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("ShrubberyCreationForm", ShrubberyCreationForm::_signGrade, ShrubberyCreationForm::_execGrade)
{
	this->_target = "default";
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreationForm", ShrubberyCreationForm::_signGrade, ShrubberyCreationForm::_execGrade)
{
	this->_target = target;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &source) :
	AForm(source)
{
	*this = source;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &source)
{
	if (this != &source)
	{
		this->_target = source.getTarget();
	}
	return (*this);
}

std::string const	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void				ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();

	std::ofstream ofs;
	std::string filename = this->getTarget();
	filename.append("_shrubbery");
	ofs.open(filename.c_str());
	
	ofs << "      ###" << std::endl;
	ofs << "     #o###" << std::endl;
	ofs << "   #####o###" << std::endl;
	ofs << "  #o#\\#|#/###" << std::endl;
	ofs << "   ###\\|/#o#" << std::endl;
	ofs << "    # }|{  #" << std::endl;
	ofs << "      }|{  " << std::endl;
	ofs << "      }|{  " << std::endl;
	ofs << std::endl;
	ofs << "      ###" << std::endl;
	ofs << "     #o###" << std::endl;
	ofs << "   #####o###" << std::endl;
	ofs << "  #o#\\#|#/###" << std::endl;
	ofs << "   ###\\|/#o#" << std::endl;
	ofs << "    # }|{  #" << std::endl;
	ofs << "      }|{  " << std::endl;

	ofs.close();
	
	return ;
}