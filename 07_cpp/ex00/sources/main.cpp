/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:44:06 by manujime          #+#    #+#             */
/*   Updated: 2023/09/19 09:43:52 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Templates.hpp"
#include <iostream>


int	main(void)
{   
    std::cout << "Test for int:" << std::endl;
    ::test(4, 2);
    std::cout << "Test for float:" << std::endl;
    ::test(4.2f, 2.4f);
    std::cout << "Test for double:" << std::endl;
    ::test(4.2, 2.4);
    std::cout << "Test for char:" << std::endl;
    ::test('a', 'b');
    std::cout << "Test for string:" << std::endl;
    ::test("a", "b");
    std::cout << "Test for bool:" << std::endl;
    ::test(true, false);

    std::cout << std::endl << "Subject test" << std::endl;
    /*  should output:
        a = 3, b = 2
        min(a, b) = 2
        max(a, b) = 3
        c = chaine2, d = chaine1
        min(c, d) = chaine1
        max(c, d) = chaine2*/
    
	int a = 2;
	int b = 3;

	::swap(a, b);

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
    
    return (0);
}