/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:44:06 by manujime          #+#    #+#             */
/*   Updated: 2023/09/19 16:04:12 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

int	main(void)
{
    Array<int>		arr(5);
    Array<int>		arr2(5);

    for (int i = 0; i < 5; i++)
    {
        arr[i] = i;
        arr2[i] = i * 2;
    }

    std::cout << "arr: ";
    for (int i = 0; i < 5; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    std::cout << "arr2: ";
    for (int i = 0; i < 5; i++)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;
}