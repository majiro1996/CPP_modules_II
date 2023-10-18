/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:50:00 by manujime          #+#    #+#             */
/*   Updated: 2023/10/18 12:25:04 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <list>
# include <numeric>
# include <algorithm>
# include <stdexcept>
# include <cstdlib>
//# include <random>

class Span
{
    private:
        unsigned int    _N;
        unsigned int    _size;
        std::list<int>  _arr;

    public:
        Span(void);
        Span(unsigned int n);
        Span(Span const &source);
        ~Span(void);

        Span    &operator=(Span const &source);

        void    addNumber(int n);
        int     shortestSpan(void);
        int     longestSpan(void);

        void    addRandom(int amount);
        std::list<int>  getArr(void) const;
};

std::ostream    &operator<<(std::ostream &o, Span const &source);

#endif