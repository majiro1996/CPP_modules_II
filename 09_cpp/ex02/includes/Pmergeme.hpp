/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmergeme.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:50:00 by manujime          #+#    #+#             */
/*   Updated: 2023/10/31 17:04:52 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <vector>
# include <list>
# include <algorithm>
# include <iomanip>

class Pmergeme
{
    public:
        Pmergeme(void);
        Pmergeme(Pmergeme const &source);
        ~Pmergeme(void);

        Pmergeme &	operator=(Pmergeme const &source);

        bool       takeInput(std::string str);
        void       takeTime(void);
        void       printTime(void);
        void       printVec(void);
        void       printLst(void);
        void       sort(void);
        void       sort(std::vector<int> &vec);
        void       sort(std::list<int> &lst);

    private:
        std::vector<int>    _vec;
        std::list<int>      _lst;
        clock_t             _timeVec;
        clock_t             _timeLst;
};

#endif