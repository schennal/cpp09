/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:27:23 by schennal          #+#    #+#             */
/*   Updated: 2024/08/17 14:42:24 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <ctime>
#include <iostream>

class PmergeMe {
public:
    PmergeMe();  // Default constructor
    PmergeMe(const PmergeMe& other);  // Copy constructor
    PmergeMe& operator=(const PmergeMe& other);  // Assignment operator
    ~PmergeMe();  // Destructor

    void sortVector(std::vector<int>& vec);
    void sortList(std::list<int>& lst);
    void printResults() const;

private:
    void insertionSort(std::vector<int>& vec);
    void insertionSort(std::list<int>& lst);
    double getElapsedTime(clock_t start, clock_t end) const;

    std::vector<int> inputVector;
    std::list<int> inputList;
    double vectorTime;
    double listTime;
};

#endif
