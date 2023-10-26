/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:51:57 by manujime          #+#    #+#             */
/*   Updated: 2023/10/26 16:52:58 by manujime         ###   ########.fr       */
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
    long long           res;

    while (ss >> str)
    {
        if (str.find_first_not_of("+-*/") == std::string::npos)
        {
/*             if (this->_stack.size() < 2)
            {
                std::cout << "Error: Not enough operands" << std::endl;
                return ;
            } */
            while (this->_stack.size() > 1)
            {
                res = this->_stack.top();
                this->_stack.pop();
                std::cout << this->_stack.top() << " ";
                std::cout << str << " ";
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
        else if (str.find_first_not_of("0123456789") == std::string::npos)
            this->_stack.push(myStoi(str));
        else
        {
            std::cout << "Error: Invalid input" << std::endl;
            return ;
        }
    }
    std::cout << "Result: " << this->_stack.top() << std::endl;
}