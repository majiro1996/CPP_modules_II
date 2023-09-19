/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:07:01 by manujime          #+#    #+#             */
/*   Updated: 2023/09/19 16:02:35 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <exception>

template <typename T>
class Array
{
    private:
        T	*_arr;
        int	_size;

    public:
        Array(void);
        Array(unsigned int n);
        Array(Array const &source);
        ~Array(void);

        Array &	operator=(Array const &source);

        T &		operator[](int i);
        unsigned int		size(void) const;
};

template <typename T>
Array<T>::Array(void) : _arr(new T[0]), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(Array const &source) : _arr(new T[source.size]), _size(source.size)
{
    for (int i = 0; i < source._size; i++)
        this->_arr[i] = source._arr[i];
}

template <typename T>
Array<T>::~Array(void)
{
    delete [] this->_arr;
}

template <typename T>
Array<T> &	Array<T>::operator=(Array const &source)
{
    if (this != &source)
    {
        delete [] this->_arr;
        this->_arr = new T[source.size];
        this->_size = source.size;
        for (int i = 0; i < source._size; i++)
            this->_arr[i] = source._arr[i];
    }
    return (*this);
}

template <typename T>
T &	Array<T>::operator[](int i)
{
    if (i < 0 || i >= this->_size)
        throw std::exception();
    return (this->_arr[i]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
    return (this->_size);
}


#endif