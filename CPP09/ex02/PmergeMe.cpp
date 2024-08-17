/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:27:11 by schennal          #+#    #+#             */
/*   Updated: 2024/08/17 14:42:37 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <iterator>

PmergeMe::PmergeMe() : vectorTime(0), listTime(0) {}

PmergeMe::PmergeMe(const PmergeMe& other) 
    : inputVector(other.inputVector), inputList(other.inputList),
      vectorTime(other.vectorTime), listTime(other.listTime) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        inputVector = other.inputVector;
        inputList = other.inputList;
        vectorTime = other.vectorTime;
        listTime = other.listTime;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::insertionSort(std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        int key = vec[i];
        size_t j = i;
        while (j > 0 && vec[j - 1] > key) {
            vec[j] = vec[j - 1];
            --j;
        }
        vec[j] = key;
    }
}

void PmergeMe::insertionSort(std::list<int>& lst) {
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        int key = *it;
        std::list<int>::iterator j = it;
        while (j != lst.begin() && key < *(--j)) {
            *std::next(j) = *j;
        }
        *std::next(j) = key;
    }
}

void PmergeMe::sortVector(std::vector<int>& vec) {
    inputVector = vec;
    clock_t start = clock();
    insertionSort(inputVector);
    clock_t end = clock();
    vectorTime = getElapsedTime(start, end);
}

void PmergeMe::sortList(std::list<int>& lst) {
    inputList = lst;
    clock_t start = clock();
    insertionSort(inputList);
    clock_t end = clock();
    listTime = getElapsedTime(start, end);
}

double PmergeMe::getElapsedTime(clock_t start, clock_t end) const {
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;  // Convert to microseconds
}

void PmergeMe::printResults() const {
    std::cout << "Before: ";
    for (std::vector<int>::const_iterator it = inputVector.begin(); it != inputVector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "After: ";
    for (std::vector<int>::const_iterator it = inputVector.begin(); it != inputVector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << inputVector.size() << " elements with std::vector: "
              << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << inputList.size() << " elements with std::list: "
              << listTime << " us" << std::endl;
}
