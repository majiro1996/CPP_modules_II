/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:49:21 by manujime          #+#    #+#             */
/*   Updated: 2023/09/01 17:08:27 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(Bureaucrat::minGrade)
{
    return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &source) : _name(source.getName())
{
    *this = source;
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < Bureaucrat::maxGrade)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > Bureaucrat::minGrade)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
    return ;
}

Bureaucrat::~Bureaucrat(void)
{
    return ;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &source)
{
    if (this != &source)
    {
        this->_grade = source.getGrade();
    }
    return (*this);
}

std::string const  &Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
    if (this->_grade - 1 < Bureaucrat::maxGrade)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade--;
    return ;
}

void Bureaucrat::decrementGrade(void)
{
    if (this->_grade + 1 > Bureaucrat::minGrade)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;
    return ;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &source)
{
    o << source.getName() << ", bureaucrat grade " << source.getGrade();
    return (o);
}