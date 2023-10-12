/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:44:06 by manujime          #+#    #+#             */
/*   Updated: 2023/10/12 14:27:38 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Easy.hpp"
# include <vector>
# include <list>
# include <deque>


int	main(void)
{
    std::vector<int>	v;
    std::list<int>		l;
    std::deque<int>		d;

    fillContainer(v, 1, 5);
    fillContainer(l, 1, 5);
    fillContainer(d, 1, 5);

    std::cout << "Vector: " << std::endl;
    basicTest(v, 0, 6);
    std::cout << "List: " << std::endl;
    basicTest(l, 5, 8);
    std::cout << "Deque: " << std::endl;
    basicTest(d, 0, 3);

    return (0);
}