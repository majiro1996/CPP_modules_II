/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:38:52 by manujime          #+#    #+#             */
/*   Updated: 2023/09/06 11:06:41 by manujime         ###   ########.fr       */
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
	private:
		AForm   *makeShrubberyCreationForm(std::string target);
		AForm   *makeRobotomyRequestForm(std::string target);
		AForm   *makePresidentialPardonForm(std::string target);

	public:
		Intern(void);
		Intern(Intern const &source);
		~Intern(void);

		Intern 	&operator=(Intern const &source);

		AForm	*makeForm(std::string name, std::string target);
};

#endif