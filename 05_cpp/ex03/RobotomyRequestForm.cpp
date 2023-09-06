/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:19:58 by manujime          #+#    #+#             */
/*   Updated: 2023/09/06 09:19:34 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) :
    AForm("RobotomyRequestForm", RobotomyRequestForm::_signGrade, RobotomyRequestForm::_execGrade)
{
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
    AForm("RobotomyRequestForm", RobotomyRequestForm::_signGrade, RobotomyRequestForm::_execGrade),
    _target(target)
{
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &source) :
    AForm(source)
{
    *this = source;
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &source)
{
    if (this != &source)
    {
        this->_target = source.getTarget();
    }
    return (*this);
}

std::string const   RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    srand(time(NULL));
    if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
    if (this->getSigned() == false)
        throw AForm::NotSignedException();
    int rand = std::rand() % 2 + 1;
    if (rand == 1)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << _target << " has NOT been robotomized successfully." << std::endl;
}