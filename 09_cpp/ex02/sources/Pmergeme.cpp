/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmergeme.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:12:45 by manujime          #+#    #+#             */
/*   Updated: 2023/10/31 17:06:17 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Pmergeme.hpp"

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
        this->_timeVec = source._timeVec;
        this->_timeLst = source._timeLst;
    }
    return (*this);
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
    if (vec.size() <= 1 || isSorted(vec))
        return; // Already sorted

    //If the list has an odd number of elements, remove one and set it aside.
    int oddElement = 0;
    bool hasOddElement = false;
    if (vec.size() % 2 != 0)
    {
        oddElement = vec.back();
        vec.pop_back();
        hasOddElement = true;
    }

    //Pair up the remaining elements in the list.
    //Sort each pair of elements.
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        if (vec[i] > vec[i + 1]) 
        {
            std::swap(vec[i], vec[i + 1]);
        }
    }

    //Merge the sorted pairs into a single sorted list.
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

    //If there was an odd element, insert it into the correct position.
    if (hasOddElement)
    {
        vec.insert(std::upper_bound(vec.begin(), vec.end(), oddElement), oddElement);
    }
}

void Pmergeme::sort(std::list<int> &lst)
{
    if (lst.size() <= 1 || isSorted(lst))
        return; // Already sorted

    //If the list has an odd number of elements, remove one and set it aside.
    int oddElement = 0;
    bool hasOddElement = false;
    if (lst.size() % 2 != 0)
    {
        oddElement = lst.back();
        lst.pop_back();
        hasOddElement = true;
    }

    //Pair up the remaining elements in the list.
    //Sort each pair of elements.
    std::list<int>::iterator it = lst.begin();
    while (it != lst.end())
    {
        std::list<int>::iterator nextIt = it;
        std::advance(nextIt, 1);
        if (*it > *nextIt)
        {
            std::swap(*it, *nextIt);
        }
        std::advance(it, 2);
    }

    //Merge the sorted pairs into a single sorted list.
    for (size_t width = 2; width <= lst.size(); width *= 2)
    {
        std::list<int>::iterator it = lst.begin();

        while (std::distance(it, lst.end()) > 0)
        {
            std::list<int>::iterator middle = it;
            std::advance(middle, std::min(width, static_cast<size_t>(std::distance(it, lst.end()))));

            std::list<int>::iterator end = middle;
            std::advance(end, std::min(width, static_cast<size_t>(std::distance(middle, lst.end()))));

            std::inplace_merge(it, middle, end);
            it = end;
        }
    }

    //Step 5: If there was an odd element, insert it into the correct position.
    if (hasOddElement)
    {
        lst.insert(std::upper_bound(lst.begin(), lst.end(), oddElement), oddElement);
    }
}

void       Pmergeme::sort(void)
{
    long long int   size = this->_vec.size();

    std::cout << "Before: ";
    this->printVec();
    
    _timeVec = clock();
    std::cout << "Vector sorted: ";
    this->sort(this->_vec);
    _timeVec = clock() - _timeVec;
    this->printVec();
   
    _timeLst = clock();
    this->sort(this->_lst);
    _timeLst = clock() - _timeLst;
    std::cout << "List sorted: ";
    this->printLst();

    std::cout << "Vector time: " << _timeVec / (double)CLOCKS_PER_SEC *1e6 << " microseconds for a size of " <<  size <<std::endl;
    std::cout << "List time: " << _timeLst / (double)CLOCKS_PER_SEC *1e6 << " microseconds for a size of " <<  size <<std::endl;

    if (!isSorted(this->_vec))
        std::cout << "Vector not sorted." << std::endl;
    if (!isSorted(this->_lst))
        std::cout << "List not sorted." << std::endl;
}
