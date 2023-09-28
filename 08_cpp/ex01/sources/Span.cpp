/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:38:37 by manujime          #+#    #+#             */
/*   Updated: 2023/09/28 17:58:46 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <random>

Span::Span(void) : _N(0), _size(0)
{
    return ;
}

Span::Span(unsigned int n) : _N(n), _size(0)
{
    return ;
}

Span::Span(Span const &source)
{
    *this = source;
    return ;
}

Span::~Span(void)
{
    return ;
}

Span &Span::operator=(Span const &source)
{
    if (this != &source)
    {
        this->_N = source._N;
        this->_size = source._size;
        this->_arr = source._arr;
    }
    return (*this);
}

void   Span::addNumber(int n)
{
    if (this->_size >= this->_N)
        throw std::length_error("Not enough space");
    this->_arr.push_back(n);
    this->_size++;
}

void   Span::addRandom(int amount)
{
    if (this->_size + amount > this->_N)
        throw std::length_error("Not enough space");
    for (int i = 0; i < amount; i++)
    {
        srand(time(NULL));
        this->_arr.push_back(std::rand());
        this->_size++;
    }
}
