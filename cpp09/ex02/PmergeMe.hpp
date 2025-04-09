/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:36:53 by schennal          #+#    #+#             */
/*   Updated: 2024/08/20 17:47:56 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <ctime>
#include <iostream>
#include <limits>

class PmergeMe 
{
public:
    PmergeMe(int* arr, int size);
    ~PmergeMe();

    void sort(void);

private:
    std::vector<int> _array;
    std::list<int> _list;

    void _sortArray(void);
    void _sortList(void);

    template <typename container>
    void print(container& con);

    template <typename container>
    int _binarySearch(container& con, int target);

	//making it private [object cannot be created without creating an array to sort]

    PmergeMe();
    PmergeMe(PmergeMe const& copy);
    PmergeMe& operator=(PmergeMe const& copy);
};

#endif

