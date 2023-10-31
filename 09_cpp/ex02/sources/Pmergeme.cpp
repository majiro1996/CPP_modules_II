/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmergeme.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:12:45 by manujime          #+#    #+#             */
/*   Updated: 2023/10/31 14:39:25 by manujime         ###   ########.fr       */
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
    }
    return (*this);
}

void       Pmergeme::takeTime(void)
{
    _time = clock();
}

void       Pmergeme::printTime(void)
{
    std::cout << "Time: " << (clock() - _time) / (double)CLOCKS_PER_SEC * 1e6 << " microseconds" << std::endl;
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
    
    if (vec.size() <= 1 || isSorted(vec))
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
    if (lst.size() <= 1 || isSorted(lst))
        return; // Already sorted

    std::list<int> left;
    std::list<int> right;
    std::list<int>::iterator middle = lst.begin();
    std::advance(middle, lst.size() / 2);

    // Divide the list into two
    std::copy(lst.begin(), middle, std::back_inserter(left));
    std::copy(middle, lst.end(), std::back_inserter(right));

    //recursively sort the sublists
    sort(left);
    sort(right);

    //merge the two sorted lists
    std::merge(left.begin(), left.end(), right.begin(), right.end(), lst.begin());
}

void       Pmergeme::sort(void)
{
    this->takeTime();
    this->sort(this->_vec);
    this->printTime();
    this->takeTime();
    std::cout << "Before: ";
    this->printLst();
    this->sort(this->_lst);
    std::cout << "List sorted: ";
    this->printLst();
    this->printTime();
    if (!isSorted(this->_vec))
        std::cout << "Vector not sorted." << std::endl;
    if (!isSorted(this->_lst))
        std::cout << "List not sorted." << std::endl;
}
