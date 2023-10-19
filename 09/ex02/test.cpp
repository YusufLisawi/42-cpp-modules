
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

void split_deque_into_pairs(std::deque<int>& d, size_t size);

static int comp=0;
bool Compare(const std::deque<int>& d1, const std::deque<int>& d2)
{
    comp++;
    return (d1.back() < d2.back());
}

void split_deque_into_pairs(std::deque<int>& d, size_t size)
{
    if (d.size() < size * 2)
        return;
    std::deque<std::pair<std::deque<int>, std::deque<int> > > pairs;
    std::deque<int> tmp;
    if (d.size() % (size * 2) != 0)
    {
        for (size_t i = d.size() - (d.size() % (size * 2)); i < d.size(); i++)
            tmp.push_back(d[i]);
        d.erase(d.end() - (d.size() % (size * 2)), d.end());
        std::cout << std::endl;
        // std::cout << "==> tmp" << std::endl;
    }
    for (std::deque<int>::iterator it = tmp.begin(); it != tmp.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    for (size_t i = 0; i < d.size(); i += size * 2)
    {
        std::deque<int> first_deque;
        std::deque<int> second_deque;
        if (d.size() - i < size * 2)
        {
            for (size_t j = i; j < d.size(); j++)
            {
                if (j < i + size)
                    first_deque.push_back(d[j]);
                else
                    second_deque.push_back(d[j]);
            }
        }
        else
        {
            for (size_t j = i; j < i + size; j++)
                first_deque.push_back(d[j]);
            for (size_t j = i + size; j < i + size * 2; j++)
                second_deque.push_back(d[j]);
            if (first_deque.back() > second_deque.back())
            {
                comp++;
                std::swap(first_deque, second_deque);
            }
        }
        pairs.push_back(std::make_pair(first_deque, second_deque));
    }
    d.clear();
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::deque<int>& first_subdeque = pairs[i].first;
        std::deque<int>& second_subdeque = pairs[i].second;
        for (size_t j = 0; j < size; j++)
            d.push_back(first_subdeque[j]);
        for (size_t j = 0; j < size; j++)
            d.push_back(second_subdeque[j]);
    }
    std::cout << "==> pairs in " << size << std::endl;
    for (std::deque<std::pair<std::deque<int>, std::deque<int> > >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        for (std::deque<int>::iterator it2 = it->first.begin(); it2 != it->first.end(); ++it2)
            std::cout << *it2 << " ";
        std::cout << " , ";
        for (std::deque<int>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            std::cout << *it2 << " ";
        std::cout << std::endl;
    }
    split_deque_into_pairs(d, size * 2);
    pairs.clear();
    std::cout << std::endl;
    // std::cout << "size = " << size << std::endl;
    std::deque<std::deque<int> > main_chain;
    std::deque<std::deque<int> > pend_chain;
    for (size_t i = 0; i < d.size(); i += size * 2)
    {
        if (size > d.size() - i)
        {
            std::deque<int> first_deque;
            std::deque<int> second_deque;
            for (size_t j = i; j < d.size(); j++)
            {
                if (j < i + size)
                    first_deque.push_back(d[j]);
                else
                    second_deque.push_back(d[j]);
            }
            pairs.push_back(std::make_pair(first_deque, second_deque));
        }
        else
        {
            std::deque<int> first_deque;
            std::deque<int> second_deque;
            for (size_t j = i; j < i + size; j++)
                first_deque.push_back(d[j]);
            for (size_t j = i + size; j < i + size * 2; j++)
                second_deque.push_back(d[j]);
            pairs.push_back(std::make_pair(first_deque, second_deque));
        }
        main_chain.push_back(pairs.back().second);
        pend_chain.push_back(pairs.back().first);
    }
    if(!tmp.empty())
        pend_chain.push_back(tmp);
    for (std::deque<std::deque<int> >::iterator p_it = pend_chain.begin(); p_it != pend_chain.end(); ++p_it)
    {
        std::deque<std::deque<int> >::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), *p_it, Compare);
        main_chain.insert(it, *p_it);
    }
    d.clear();
    for (std::deque<std::deque<int> >::iterator it = main_chain.begin(); it != main_chain.end(); ++it)
        d.insert(d.end(), it->begin(), it->end());
    std::cout << "==> main_chain" << std::endl;
    for (std::deque<std::deque<int> >::iterator it = main_chain.begin(); it != main_chain.end(); ++it)
    {
        for (std::deque<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
            std::cout << *it2 << " ";
        std::cout << " , ";
    }
    // std::cout << std::endl << "==> pend" << std::endl;
    // for (std::deque<std::deque<int> >::iterator it = pend_chain.begin(); it != pend_chain.end(); ++it)
    // {
    //     for (std::deque<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
    //         std::cout << *it2 << " ";
    //     std::cout << " , ";
    // }
    std::cout << std::endl;

}


int main (int ac, char **av)
{
	std::deque<int> d;
	std::deque<std::pair<std::deque<int>, std::deque<int> > > pairs;

	if (ac < 2)
	{
		std::cout << "Error : please give me a list of integers pleaaaseee" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
		d.push_back(atoi(av[i]));
	std::cout << "==> d : ";
	for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	split_deque_into_pairs(d, 1);

	std::cout << "comp :  " << comp << std::endl;
	return (0);
}