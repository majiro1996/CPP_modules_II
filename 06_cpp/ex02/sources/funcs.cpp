/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 00:46:52 by manujime          #+#    #+#             */
/*   Updated: 2023/09/18 01:05:52 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

Base *generate(void)
{
    srand(time(NULL));
    int rand = std::rand() % 3;
    switch (rand)
    {
        case 0:
            return (new A);
        case 1:
            return (new B);
        case 2:
            return (new C);
        default:
            return (NULL);
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Not valid" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        (void)a;
    }
    catch (std::exception &e)
    {
        try
        {
            B &b = dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
            (void)b;
        }
        catch (std::exception &e)
        {
            try
            {
                C &c = dynamic_cast<C &>(p);
                std::cout << "C" << std::endl;
                (void)c;
            }
            catch (std::exception &e)
            {
                std::cout << "Not valid" << std::endl;
            }
        }
    }
}