/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:12:50 by manujime          #+#    #+#             */
/*   Updated: 2023/09/03 21:12:47 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("PresidentialPardonForm", PresidentialPardonForm::_signGrade, PresidentialPardonForm::_execGrade)
{
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
    std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
    return ;
}
