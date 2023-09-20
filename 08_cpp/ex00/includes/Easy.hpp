/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easy.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:50:00 by manujime          #+#    #+#             */
/*   Updated: 2023/09/20 09:55:46 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_HPP
# define EASY_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <list>

template <typename T>
bool    easyfind(T &container, int n)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), n);
    if (it != container.end())
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