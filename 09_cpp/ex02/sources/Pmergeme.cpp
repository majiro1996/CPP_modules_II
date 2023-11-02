/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmergeme.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:12:45 by manujime          #+#    #+#             */
/*   Updated: 2023/11/02 13:19:26 by manujime         ###   ########.fr       */
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

//----VECTOR SORTING ALGORITHM----

static std::vector<std::vector<int> > createPairs(std::vector<int> &vec)
{
    std::vector<std::vector<int> > pairs;
    std::vector<int>::iterator it = vec.begin();
    std::vector<int>::iterator nextIt = it;
    std::advance(nextIt, 1);
    while(it != vec.end())
    {
        std::vector<int> pair;
        pair.push_back(*it);
        pair.push_back(*nextIt);
        pairs.push_back(pair);
        std::advance(it, 2);
        std::advance(nextIt, 2);
    }
    return pairs;
}

static void sortPairVector(std::vector<int> &pair)
{
    if (pair[0] > pair[1])
    {
        std::swap(pair[0], pair[1]);
    }
}

static std::vector<std::vector<int> > sortPairs(std::vector<std::vector<int> > &pairs)
{
    if (pairs.size() <= 1)
        return pairs;

    for (std::vector<std::vector<int> >::iterator i = pairs.begin(); i != pairs.end(); ++i)
    {
        std::vector<std::vector<int> >::iterator insertion_point = std::upper_bound(pairs.begin(), i, *i);
        std::vector<std::vector<int> >::iterator next = i;
        ++next;
        std::rotate(insertion_point, i, next);
    }
    return pairs;
}

static void splitPairs(std::vector<std::vector<int> > &pairs, std::vector<int> &S, std::vector<int> &pending)
{
    std::vector<std::vector<int> >::iterator it = pairs.begin();
    while (it != pairs.end())
    {
        S.push_back(it->at(0));
        pending.push_back(it->at(1));
        it++;
    }
}

static void sortFinal(std::vector<int> &S, std::vector<int> &pending)
{   
    for (int i = 0; ; i++)
    {
        if (jacobsthal_diff[i] >= pending.size())
            break;
        std::vector<int>::iterator it = pending.begin();
        std::advance(it, jacobsthal_diff[i]);
        while (1)
        {
            std::vector<int>::iterator insertion_point = std::upper_bound(S.begin(), S.end(), *it);
            S.insert(insertion_point, *it);
            it = pending.erase(it);
            if (it == pending.begin())
                break;
            std::advance(it, -1);
        }
    }

    while (pending.size() > 0)
    {
        S.insert(std::upper_bound(S.begin(), S.end(), pending.front()), pending.front());
        pending.erase(pending.begin());
    }
}

void   Pmergeme::sort(std::vector<int> &vec)
{
    int oddElement = 0;
    bool hasOddElement = false;
    std::vector<std::vector<int> > pairs;
    std::vector<int> S;
    std::vector<int> pending;
    if (vec.size() <= 1 || isSorted(vec))
        return;
    if (vec.size() % 2 != 0)
    {
        oddElement = vec.back();
        vec.pop_back();
        hasOddElement = true;
    }
    pairs = createPairs(vec);
    std::for_each(pairs.begin(), pairs.end(), sortPairVector);
    pairs = sortPairs(pairs);
    splitPairs(pairs, S, pending);
    sortFinal(S, pending);
    if (hasOddElement)
        S.insert(std::upper_bound(S.begin(), S.end(), oddElement), oddElement);
    vec = S;
}

//----LIST SORTING ALGORITHM----

static  std::list<std::pair<int, int> > makePairs(std::list<int> &lst)
{
    std::list<std::pair<int, int> > pairs;
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator nextIt = it;
    std::advance(nextIt, 1);
    while(it != lst.end())
    {
        pairs.push_back(std::make_pair(*it, *nextIt));
        std::advance(it, 2);
        std::advance(nextIt, 2);
    }
    return pairs;
}

static void sortPair(std::pair<int, int> &pair)
{
    if (pair.first > pair.second)
    {
        std::swap(pair.first, pair.second);
    }
}

static bool pairCompare(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    return a.first < b.first;
}

static void SortPairs(std::list<std::pair<int, int> > &pairs)
{
    if (pairs.size() <= 1)
        return;

    for (std::list<std::pair<int, int> >::iterator i = pairs.begin(); i != pairs.end(); ++i)
    {
        std::list<std::pair<int, int> >::iterator insertion_point = std::upper_bound(pairs.begin(), i, *i, pairCompare);
        std::list<std::pair<int, int> >::iterator next = i;
        ++next;
        std::rotate(insertion_point, i, next);
    }
}

static void splitPairs(std::list<std::pair<int, int> > &pairs, std::list<int> &S, std::list<int> &pending)
{
    std::list<std::pair<int, int> >::iterator it = pairs.begin();
    while (it != pairs.end())
    {
        S.push_back(it->first);
        pending.push_back(it->second);
        it++;
    }
}

static void sortFinal(std::list<int> &S, std::list<int> &pending)
{
   
    for (int i = 0; ; i++)
    {
        if (jacobsthal_diff[i] >= pending.size())
            break;
        std::list<int>::iterator it = pending.begin();
        std::advance(it, jacobsthal_diff[i]);
        while (1)
        {
            std::list<int>::iterator insertion_point = std::upper_bound(S.begin(), S.end(), *it);
            S.insert(insertion_point, *it);
            it = pending.erase(it);
            if (it == pending.begin())
                break;
            std::advance(it, -1);
        }
    }

    while (pending.size() > 0)
    {
        S.insert(std::upper_bound(S.begin(), S.end(), pending.front()), pending.front());
        pending.pop_front();
    }
}

void Pmergeme::sort(std::list<int> &lst)
{
    int oddElement = 0;
    bool hasOddElement = false;
    std::list<std::pair<int, int> > pairs;
    std::list<int> S;
    std::list<int> pending;
    if (lst.size() <= 1 || isSorted(lst))
        return;
    if (lst.size() % 2 != 0)
    {
        oddElement = lst.back();
        lst.pop_back();
        hasOddElement = true;
    }
    pairs = makePairs(lst);
    std::for_each(pairs.begin(), pairs.end(), sortPair);
    SortPairs(pairs);
    splitPairs(pairs, S, pending);
    sortFinal(S, pending);
    if (hasOddElement)
        S.insert(std::upper_bound(S.begin(), S.end(), oddElement), oddElement);
    lst = S;
}

//----OUTPUT----

void       Pmergeme::sort(void)
{
    long long int   size = this->_vec.size();
    std::list<int>  control = this->_lst;

    std::cout << "Before: ";
    this->printVec();
    
    _timeVec = clock();
    std::cout << std::endl << "Vector sorted: ";
    this->sort(this->_vec);
    _timeVec = clock() - _timeVec;
    this->printVec();
    
    _timeLst = clock();
    this->sort(this->_lst);
    _timeLst = clock() - _timeLst;
    std::cout << std::endl << "List sorted: ";
    this->printLst();

    control.sort();
    std::cout << std::endl << "Control: ";
    std::list<int>::iterator    it = control.begin();
    std::list<int>::iterator    ite = control.end();
    while (it != ite)
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;

    std::cout << std::endl << "Vector time: " << _timeVec / (double)CLOCKS_PER_SEC *1e3 << " milliseconds for a size of " <<  size <<std::endl;
    std::cout << "List time: " << _timeLst / (double)CLOCKS_PER_SEC *1e3 << " milliseconds for a size of " <<  size <<std::endl;

    if (!isSorted(this->_vec))
        std::cout << "Vector not sorted." << std::endl;
    if (!isSorted(this->_lst))
        std::cout << "List not sorted." << std::endl;
}
