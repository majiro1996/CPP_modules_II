/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 00:54:38 by manujime          #+#    #+#             */
/*   Updated: 2023/09/18 01:02:50 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main(void)
{
    Base *base = generate();
    identify(base);
    identify(*base);
    return (0);
}