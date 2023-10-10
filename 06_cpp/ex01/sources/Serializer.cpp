/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:09:52 by manujime          #+#    #+#             */
/*   Updated: 2023/10/10 15:36:40 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer(void)
{
    return ;
}

Serializer::~Serializer(void)
{
    return ;
}

Serializer::Serializer(Serializer const &source)
{
    *this = source;
    return ;
}

Serializer & Serializer::operator=(Serializer const &source)
{
    (void)source;
    return (*this);
}

uintptr_t    Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*        Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}