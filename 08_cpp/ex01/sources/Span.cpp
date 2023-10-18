/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:38:37 by manujime          #+#    #+#             */
/*   Updated: 2023/10/18 12:36:04 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

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
    srand(time(NULL));
    for (int i = 0; i < amount; i++)
    {
        this->_arr.push_back(std::rand() % 100);
        this->_size++;
    }
}

int    Span::shortestSpan(void)
{
    if (this->_size <= 1)
        throw std::length_error("Not enough numbers");
    std::list<int>  tmp = this->_arr;
    tmp.sort();
    std::list<int> diff;
    std::adjacent_difference(tmp.begin(), tmp.end(), std::back_inserter(diff));
    return (std::abs(*std::min_element(diff.begin(), diff.end())));

}

int    Span::longestSpan(void)
{
    if (this->_size <= 1)
        throw std::length_error("Not enough numbers");
    std::list<int>  tmp = this->_arr;
    tmp.sort();
    return (std::abs(tmp.back() - tmp.front()));
}

std::list<int>  Span::getArr(void) const
{
    return (this->_arr);
}

std::ostream    &operator<<(std::ostream &o, Span const &source)
{
    std::list<int>  tmp = source.getArr();
    for (std::list<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
    {
        o << *it << " ";
    }
    return (o);
}
