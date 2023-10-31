/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmergeme.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:12:45 by manujime          #+#    #+#             */
/*   Updated: 2023/10/31 10:53:13 by manujime         ###   ########.fr       */
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
    
    if (vec.size() <= 1)
        return; // Already sorted

    // Step 1: If the list has an odd number of elements, remove one and set it aside.
    int oddElement = 0;
    bool hasOddElement = false;
    if (vec.size() % 2 != 0)
    {
        oddElement = vec.back();
        vec.pop_back();
        hasOddElement = true;
    }

    // Step 2: Pair up the remaining elements in the list.
    // Step 3: Sort each pair of elements.
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        if (vec[i] > vec[i + 1]) 
        {
            std::swap(vec[i], vec[i + 1]);
        }
    }

    // Step 4: Merge the sorted pairs into a single sorted list.
    std::vector<int> temp(vec.size());
    for (size_t width = 2; width < vec.size(); width *= 2)
    {
        for (size_t i = 0; i < vec.size(); i += 2 * width) 
        {
            std::merge(vec.begin() + i, vec.begin() + std::min(i + width, vec.size()),
                       vec.begin() + std::min(i + width, vec.size()), vec.begin() + std::min(i + 2 * width, vec.size()),
                       temp.begin() + i);
        }
        std::copy(temp.begin(), temp.end(), vec.begin());
    }

    // Step 5: If there was an odd element, insert it into the correct position.
    if (hasOddElement)
    {
        vec.insert(std::upper_bound(vec.begin(), vec.end(), oddElement), oddElement);
    }
    std::cout << "Vector sorted: ";
    this->printVec();
    
}

void Pmergeme::sort(std::list<int> &lst)
{
    std::cout << "Before: ";
    this->printLst();

    if (lst.size() <= 1)
        return; // Already sorted
    
    // Step 1: If the list has an odd number of elements, remove one and set it aside.
    int oddElement = 0;
    bool hasOddElement = false;

    if (lst.size() % 2 != 0)
    {
        oddElement = lst.back();
        lst.pop_back();
        hasOddElement = true;
    }

    // Step 2: Pair up the remaining elements in the list.
    // Step 3: Sort each pair of elements.
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); std::advance(it, 2))
    {
        std::list<int>::iterator next = it;
        std::advance(next, 1);
        if (next != lst.end() && *it > *next)
        {
            std::swap(*it, *next);
        }
    }

    // Step 4: Merge the sorted pairs into a single sorted list.
    std::list<int> temp(lst);
    for (size_t width = 2; width < lst.size(); width *= 2)
    {
        for (size_t i = 0; i < lst.size(); i += width) 
        {
            std::list<int>::iterator first = temp.begin();
            std::advance(first, i);
            size_t mid = i + width < lst.size() ? i + width : lst.size();
            size_t end = i + 2 * width < lst.size() ? i + 2 * width : lst.size();
            std::list<int>::iterator middle = first;
            std::advance(middle, mid - i);
            std::list<int>::iterator last = middle;
            std::advance(last, end - mid);
            std::list<int> merged(first, middle);
            std::list<int> temp_list(middle, last);
            merged.merge(temp_list);
            std::copy(merged.begin(), merged.end(), first);
        }
    }

    // Step 5: If there was an odd element, insert it into the correct position.
    if (hasOddElement)
    {
        std::list<int>::iterator pos = std::upper_bound(lst.begin(), lst.end(), oddElement);
        lst.insert(pos, oddElement);
    }

    std::cout << "List sorted: ";
    this->printLst();
}

void       Pmergeme::sort(void)
{
    this->sort(this->_vec);
    this->sort(this->_lst);
}
