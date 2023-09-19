/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easy.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:50:00 by manujime          #+#    #+#             */
/*   Updated: 2023/09/19 18:39:24 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_HPP
# define EASY_HPP

# include <iostream>
# include <string>
# include <algorithm>

template <typename T>
bool  easyfind(T &container, int n)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), n);
    if (it != container.end())
        return (true);
    else
        return (false);
}

#endif