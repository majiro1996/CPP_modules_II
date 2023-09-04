/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:41:58 by manujime          #+#    #+#             */
/*   Updated: 2023/09/04 10:10:02 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
    return ;
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_exec) : _name(name), _signed(false), _gradeToSign(grade_to_sign), _gradeToExec(grade_to_exec)
{
    if (grade_to_sign < 1 || grade_to_exec < 1)
        throw AForm::GradeTooHighException();
    else if (grade_to_sign > 150 || grade_to_exec > 150)
        throw AForm::GradeTooLowException();
    return ;
}

AForm::AForm(AForm const &source) : _name(source.getName()), _signed(source.getSigned()), _gradeToSign(source.getGradeToSign()), _gradeToExec(source.getGradeToExec())
{
    *this = source;
    return ;
}

AForm::~AForm(void)
{
    return ;
}

AForm &AForm::operator=(AForm const &source)
{
    if (this != &source)
    {
        this->_signed = source.getSigned();
    }
    return (*this);
}

std::string const  AForm::getName(void) const
{
    return (this->_name);
}

bool    AForm::getSigned(void) const
{
    return (this->_signed);
}

int     AForm::getGradeToSign(void) const
{
    return (this->_gradeToSign);
}

int     AForm::getGradeToExec(void) const
{
    return (this->_gradeToExec);
}

void    AForm::beSigned(Bureaucrat const &bur)
{
    if (bur.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    else
        this->_signed = true;
    return ;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("too high of a grade.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("too low of a grade.");
}

const char* AForm::NotSignedException::what() const throw()
{
    return ("not signed.");
}

std::ostream &operator<<(std::ostream &o, AForm const &source)
{
    o << "AForm: " << source.getName() << ", signed: " << source.getSigned() << ", grade to sign: " << source.getGradeToSign() << ", grade to exec: " << source.getGradeToExec();
    return (o);
}