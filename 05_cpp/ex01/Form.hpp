/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:54:37 by manujime          #+#    #+#             */
/*   Updated: 2023/09/03 14:03:56 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
    private:
        std::string const   _name;
        bool                _signed;
        int const           _gradeToSign;
        int const           _gradeToExec;
    public:
        Form(void);
        Form(std::string name, int grade_to_sign, int grade_to_exec);
        Form(Form const &source);
        ~Form(void);

        Form &operator=(Form const &source);

        std::string const   getName(void) const;
        bool                getSigned(void) const;
        int                 getGradeToSign(void) const;
        int                 getGradeToExec(void) const;

        void                beSigned(const Bureaucrat &bur);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &o, Form const &source);

#endif