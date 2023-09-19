/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:58:08 by manujime          #+#    #+#             */
/*   Updated: 2023/09/19 11:21:08 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

# include <iostream>

template <typename T>
void   testPrint(T &a)
{
    std::cout << a << std::endl;
}

template <typename T>
void   iter(T *a, int len, void (*f)(T &))
{
    for (int i = 0; i < len; i++)
        f(a[i]);
}

#endif