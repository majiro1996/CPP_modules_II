/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:44:06 by manujime          #+#    #+#             */
/*   Updated: 2023/09/20 09:56:53 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Easy.hpp"

int	main(void)
{
    std::vector<int>	v;
    std::list<int>		l;

    fillContainer(v, 1, 5);
    fillContainer(l, 1, 5);

    std::cout << "Vector: " << std::endl;
    basicTest(v, 0, 6);
    std::cout << "List: " << std::endl;
    basicTest(l, 5, 8);

    return (0);
}