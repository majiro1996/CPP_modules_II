/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:50:00 by manujime          #+#    #+#             */
/*   Updated: 2023/10/02 16:13:56 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(MutantStack const &src);
		~MutantStack(void);

		MutantStack &operator=(MutantStack const &source);

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin(void);
		iterator	end(void);
};

template<typename T>
MutantStack<T>::MutantStack(void)
{
	std::cout << "MutantStack default constructor called" << std::endl;
	return ;
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const &src)
{
	std::cout << "MutantStack copy constructor called" << std::endl;
	*this = src;
	return ;
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{
	std::cout << "MutantStack destructor called" << std::endl;
	return ;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &source)
{
	std::cout << "MutantStack assignation operator called" << std::endl;
	if (this != &source)
	{
		std::stack<T>::operator=(source);
	}
	return (*this);
}

template<typename T>
typename MutantStack<T>::iterator  MutantStack<T>::begin(void)
{
	return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::iterator  MutantStack<T>::end(void)
{
	return (std::stack<T>::c.end());
}

#endif