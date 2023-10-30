/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmergeme.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:12:45 by manujime          #+#    #+#             */
/*   Updated: 2023/10/31 00:05:16 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Pmergeme.hpp"
/*
static bool    isSorted(std::vector<int> &vec)
{
    for (unsigned int i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i] > vec[i + 1])
            return (false);
    }
    return (true);
}

static bool    isSorted(std::list<int> &lst)
{
    std::list<int>::iterator    it = lst.begin();
    std::list<int>::iterator    ite = lst.end();
    int                         prev = *it;

    for (; it != ite; it++)
    {
        if (*it < prev)
            return (false);
        prev = *it;
    }
    return (true);
}
*/
unsigned int   myStoui(const std::string &str)
{
    unsigned int    num = 0;
    std::stringstream   ss(str);

    ss >> num;
    return (num);
}

Pmergeme::Pmergeme(void)
{
    return ;
}

Pmergeme::Pmergeme(Pmergeme const &source)
{
    *this = source;
    return ;
}

Pmergeme::~Pmergeme(void)
{
    return ;
}

Pmergeme &	Pmergeme::operator=(Pmergeme const &source)
{
    if (this != &source)
    {
        this->_vec = source._vec;
        this->_lst = source._lst;
    }
    return (*this);
}

void       Pmergeme::takeTime(void)
{
    _time = clock();
}

void       Pmergeme::printTime(void)
{
    std::cout << "Time: " << this->_time - clock() << std::endl;
    return ;
}

bool       Pmergeme::takeInput(std::string str)
{
    int     num = myStoui(str);

    if (num < 0)
        return (false);
    this->_vec.push_back(num);
    this->_lst.push_back(num);
    return (true);
}

void       Pmergeme::printVec(void)
{
    std::vector<int>::iterator    it = this->_vec.begin();
    std::vector<int>::iterator    ite = this->_vec.end();

    while (it != ite)
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

void       Pmergeme::printLst(void)
{
    std::list<int>::iterator    it = this->_lst.begin();
    std::list<int>::iterator    ite = this->_lst.end();

    while (it != ite)
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

/*the sorting algorithm is Ford-Johnson merge-insertion*/

void       Pmergeme::sort(std::vector<int> &vec)
{
    std::cout << "Before: ";
    this->printVec();
    (void)vec;

    std::cout << "Vector sorted: ";
    this->printVec();
    
}

void       Pmergeme::sort(std::list<int> &lst)
{
    std::cout << "Before: ";
    this->printLst();
    (void)lst;
    
    std::cout << "List sorted: ";
    this->printLst();
}

void       Pmergeme::sort(void)
{
    this->sort(this->_vec);
    this->sort(this->_lst);
}
