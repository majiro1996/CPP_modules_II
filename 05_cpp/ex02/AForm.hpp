/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:54:37 by manujime          #+#    #+#             */
/*   Updated: 2023/09/03 18:03:15 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class AForm
{
    private:
        std::string const   _name;
        bool                _signed;
        int const           _gradeToSign;
        int const           _gradeToExec;
    
    public:
        AForm(void);
        AForm(std::string name, int grade_to_sign, int grade_to_exec);
        AForm(AForm const &source);
        ~AForm(void);

        AForm &operator=(AForm const &source);

        std::string const   getName(void) const;
        bool                getSigned(void) const;
        int                 getGradeToSign(void) const;
        int                 getGradeToExec(void) const;

        void                beSigned(const Bureaucrat &bur);
        virtual void                execute(Bureaucrat const &executor) const = 0;

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

        class NotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &o, AForm const &source);

#endif