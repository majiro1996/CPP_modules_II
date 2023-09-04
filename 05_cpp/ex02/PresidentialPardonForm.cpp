/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:12:50 by manujime          #+#    #+#             */
/*   Updated: 2023/09/04 10:10:22 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("PresidentialPardonForm", PresidentialPardonForm::_signGrade, PresidentialPardonForm::_execGrade)
{
    this->_target = "default";
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", PresidentialPardonForm::_signGrade, PresidentialPardonForm::_execGrade)
{
    this->_target = target;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &source)
    : AForm(source)
{
    *this = source;
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &source)
{
    if (this != &source)
    {
        this->_target = source.getTarget();
    }
    return (*this);
}

std::string const   PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

void                PresidentialPardonForm::execute(Bureaucrat const &executor) const
{   
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    if (this->getSigned() == false)
        throw AForm::NotSignedException();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    return ;
}
