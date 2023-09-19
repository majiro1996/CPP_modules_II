/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:50:00 by manujime          #+#    #+#             */
/*   Updated: 2023/09/19 09:40:29 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

# include <iostream>
# include <string>

template <typename T>
void	swap(T &a, T &b)
{
    T	tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T	min(T a, T b)
{
    if (a < b)
        return (a);
    return (b);
}

template <typename T>
T	max(T a, T b)
{
    if (a > b)
        return (a);
    return (b);
}

template <typename T>
void    test(T a, T b)
{
    std::cout << "a: " << a << " b: " << b << std::endl;
    swap(a, b);
    std::cout << "a: " << a << " b: " << b << std::endl;
    std::cout << "min: " << ::min(a, b) << std::endl;
    std::cout << "max: " << ::max(a, b) << std::endl;
    std::cout << std::endl;
}
#endif