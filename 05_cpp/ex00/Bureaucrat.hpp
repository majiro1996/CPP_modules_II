/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:44:10 by manujime          #+#    #+#             */
/*   Updated: 2023/09/01 17:05:08 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>

class Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat(Bureaucrat const &source);
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat(void);
        
        Bureaucrat          &operator=(Bureaucrat const &source);

        std::string const   &getName(void) const;
        int                 getGrade(void) const;

        void                incrementGrade(void);
        void                decrementGrade(void);

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

        static int const           maxGrade = 1;
        static int const           minGrade = 150;


    private:
        std::string const   _name;
        int                 _grade;
};

std::ostream    &operator<<(std::ostream &o, Bureaucrat const &source);

#endif