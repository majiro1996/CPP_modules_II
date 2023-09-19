/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:44:06 by manujime          #+#    #+#             */
/*   Updated: 2023/09/19 18:42:00 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Easy.hpp"
#include <vector>
#include <list>

int	main(void)
{
    std::vector<int>	v;
    std::list<int>		l;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    std::cout << "Vector: " << std::endl;
    std::cout << easyfind(v, 1) << std::endl;
    std::cout << easyfind(v, 2) << std::endl;
    std::cout << easyfind(v, 3) << std::endl;
    std::cout << easyfind(v, 4) << std::endl;
    std::cout << easyfind(v, 5) << std::endl;

    std::cout << "List: " << std::endl;
    std::cout << easyfind(l, 1) << std::endl;
    std::cout << easyfind(l, 2) << std::endl;
    std::cout << easyfind(l, 3) << std::endl;
    std::cout << easyfind(l, 4) << std::endl;
    std::cout << easyfind(l, 5) << std::endl;

    return (0);
}