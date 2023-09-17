/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:44:02 by manujime          #+#    #+#             */
/*   Updated: 2023/09/18 00:31:29 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include <iostream>

int	main(void)
{
    Data test;
    uintptr_t raw;
    Data *dataPtr;

    test.somestr = "Hello there";
    test.someint = 42;

    std::cout << "Original: " << &test << std::endl;
    std::cout << test.somestr << std::endl;
    std::cout << test.someint << std::endl;

    raw = Serializer::serialize(&test);
    std::cout << "Serialized: " << raw << std::endl;
    std::cout << test.somestr << std::endl;
    std::cout << test.someint << std::endl;

    dataPtr = Serializer::deserialize(raw);
    std::cout << "Deserialized: " << dataPtr << std::endl;
    std::cout << dataPtr->somestr << std::endl;
    std::cout << dataPtr->someint << std::endl;
}