/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:50:00 by manujime          #+#    #+#             */
/*   Updated: 2023/10/25 20:07:35 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNP_H
# define RNP_H

# include <iostream>
# include <sstream>
# include <string>
# include <stack>

class RPN
{
    public:
        RPN(void);
        RPN(RPN const &source);
        ~RPN(void);

        RPN &  operator=(RPN const &source);

        void    process(std::string input);
        
    private:
        std::stack<int> _stack;
        
       /* void    add(void);
        void    sub(void);
        void    mul(void);
        void    div(void);*/
};

#endif