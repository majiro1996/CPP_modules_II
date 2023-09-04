/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:08:04 by manujime          #+#    #+#             */
/*   Updated: 2023/09/04 09:57:26 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string                _target;
        static int const           _signGrade = 25;
        static int const           _execGrade = 5;
        
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &source);
        ~PresidentialPardonForm(void);

        PresidentialPardonForm &operator=(PresidentialPardonForm const &source);

        std::string const   getTarget(void) const;
        void                execute(Bureaucrat const &executor) const;
}; 

#endif