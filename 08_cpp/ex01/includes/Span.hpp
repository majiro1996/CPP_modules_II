/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:50:00 by manujime          #+#    #+#             */
/*   Updated: 2023/09/19 22:03:19 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>

class Span
{
    private:
        unsigned int    _n;
        unsigned int    _size;
        int             *_arr;

    public:
        Span(void);
        Span(unsigned int n);
        Span(Span const &source);
        ~Span(void);

        Span &	operator=(Span const &source);

        void    addNumber(int n);
        int     shortestSpan(void);
        int    longestSpan(void);
};

#endif