/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:51:44 by manujime          #+#    #+#             */
/*   Updated: 2023/09/05 20:22:43 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include "AForm.hpp"
# include <cstdlib> // std::rand()

class RobotomyRequestForm : public AForm
{
    private:
        std::string                _target;
        static int const           _signGrade = 72;
        static int const           _execGrade = 45;
        
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &source);
        ~RobotomyRequestForm(void);

        RobotomyRequestForm &operator=(RobotomyRequestForm const &source);

        std::string const   getTarget(void) const;
        void                execute(Bureaucrat const &executor) const;
};

#endif 