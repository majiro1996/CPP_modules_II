/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easy.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:50:00 by manujime          #+#    #+#             */
/*   Updated: 2023/10/16 21:37:53 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_HPP
# define EASY_HPP

# include <iostream>
# include <string>
# include <algorithm>

template <typename T>
bool    easyfind(T &container, int n)
{
    if (std::find(container.begin(), container.end(), n) != container.end())
        return (true);
    else
        return (false);
}

template <typename T>
void    fillContainer(T &container, int start, int end)
{
    for (int i = start; i < end; i ++)
        container.push_back(i);
}

template <typename T>
void    basicTest(T &container, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        if (easyfind(container, i))
            std::cout << "Found " << i << std::endl;
        else
            std::cout << "Did not find " << i << std::endl;
    }
}

#endif