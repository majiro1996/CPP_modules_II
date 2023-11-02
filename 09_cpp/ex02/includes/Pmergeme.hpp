/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmergeme.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:50:00 by manujime          #+#    #+#             */
/*   Updated: 2023/11/02 13:10:16 by manujime         ###   ########.fr       */
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

static unsigned long long int jacobsthal_diff[] = 
{
    2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
    2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
    1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
    178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
    11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
    366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
    11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
    375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
    6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
    96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
    1537228672809129216u, 3074457345618258432u, 6148914691236516864u
};

#endif