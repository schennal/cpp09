/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:27:32 by schennal          #+#    #+#             */
/*   Updated: 2024/08/17 14:42:47 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <vector>
#include <list>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe sorter;
    std::vector<int> vec;
    std::list<int> lst;

    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        if (num <= 0) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        vec.push_back(num);
        lst.push_back(num);
    }

    sorter.sortVector(vec);
    sorter.sortList(lst);
    sorter.printResults();

    return 0;
}
