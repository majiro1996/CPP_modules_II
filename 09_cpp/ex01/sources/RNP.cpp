/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:51:57 by manujime          #+#    #+#             */
/*   Updated: 2023/10/26 12:02:17 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN(void)
{
    return ;
}

RPN::RPN(RPN const &source)
{
    *this = source;
    return ;
}

RPN::~RPN(void)
{
    return ;
}

RPN &  RPN::operator=(RPN const &source)
{
    if (this != &source)
    {
        this->_stack = source._stack;
    }
    return (*this);
}

static int myStoi(std::string input)
{
    std::stringstream ss(input);
    int i;

    ss >> i;
    return (i);
}

void   RPN::process(std::string input)
{
    std::stringstream   ss(input);
    std::string         str;
    int                 res;

    while (ss >> str)
    {
        if (str == "+" || str == "-" || str == "/" || str == "*")
        {
            if (this->_stack.size() < 2)
            {
                std::cout << "Error: Not enough operands" << std::endl;
                return ;
            }
            while (this->_stack.size() > 1)
            {
                std::cout << str << " ";
                res = this->_stack.top();
                this->_stack.pop();
                std::cout << this->_stack.top() << " ";
                std::cout << res << " = ";
                if (str == "+")
                    res += this->_stack.top();
                else if (str == "-") 
                    res = this->_stack.top() - res;
                else if (str == "*")
                    res = this->_stack.top() * res;
                else if (str == "/")
                {
                    if (res == 0)
                    {
                        std::cout << "Error: Division by zero" << std::endl;
                        return ;
                    }
                    res = this->_stack.top() / res;
                }
                this->_stack.pop();
                this->_stack.push(res);
                std::cout << this->_stack.top() << std::endl;
            }
        }
        else
            this->_stack.push(myStoi(str));
    }
    std::cout << "Result: " << this->_stack.top() << std::endl;
}