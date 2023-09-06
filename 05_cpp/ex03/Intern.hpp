/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:38:52 by manujime          #+#    #+#             */
/*   Updated: 2023/09/06 20:32:54 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &source);
		~Intern(void);

		Intern 	&operator=(Intern const &source);

		AForm	*makeForm(std::string name, std::string target);
		
		class   NotAFormException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif