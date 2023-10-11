/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:44:06 by manujime          #+#    #+#             */
/*   Updated: 2023/10/11 17:57:23 by manujime         ###   ########.fr       */
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

    std::cout << "arr2 = arr" << std::endl;
    arr = arr2;
    std::cout << "arr: ";
    for (int i = 0; i < 5; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    arr[0] = 42;
    std::cout << "arr[0] = 42" << std::endl;
    std::cout << "arr: " << arr[0] << std::endl;

    try
    {
        std::cout << "arr[5]: " << std::endl;
        std::cout << arr[5] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "arr[5]: " << e.what() << std::endl;
    }

}