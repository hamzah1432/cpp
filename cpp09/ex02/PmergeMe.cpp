/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 08:50:32 by halmuhis          #+#    #+#             */
/*   Updated: 2026/08/12 08:50:33 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }
PmergeMe::~PmergeMe() {}

long long PmergeMe::getTimeMicroseconds() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000000LL) + time.tv_usec;
}

unsigned int PmergeMe::getJacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    unsigned int prev2 = 0;
    unsigned int prev1 = 1;
    unsigned int curr = 0;
    
    for (int i = 2; i <= n; ++i) {
        curr = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

void PmergeMe::printSequence(const std::string& prefix, const std::vector<int>& arr) {
    std::cout << prefix;
    size_t limit = arr.size() > 5 ? 5 : arr.size();
    for (size_t i = 0; i < limit; ++i) {
        std::cout << arr[i] << " ";
    }
    if (arr.size() > 5) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

void PmergeMe::parseInput(int argc, char** argv, std::vector<int>& vec, std::deque<int>& deq) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.empty()) {
            throw std::runtime_error("Error");
        }
        for (size_t j = 0; j < arg.length(); ++j) {
            if (!isdigit(arg[j])) {
                throw std::runtime_error("Error");
            }
        }
        
        long long val = std::atoll(arg.c_str());
        if (val < 0 || val > 2147483647) {
            throw std::runtime_error("Error");
        }
        
        vec.push_back(static_cast<int>(val));
        deq.push_back(static_cast<int>(val));
    }
}

void PmergeMe::sortVector(std::vector<int>& arr) {
    if (arr.size() <= 1) return;

    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;

    if (arr.size() % 2 != 0) {
        straggler = arr.back();
        hasStraggler = true;
        arr.pop_back();
    }

    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    for (size_t i = 0; i < pairs.size(); ++i) {
        for (size_t j = i + 1; j < pairs.size(); ++j) {
            if (pairs[i].first > pairs[j].first) {
                std::swap(pairs[i], pairs[j]);
            }
        }
    }

    std::vector<int> mainChain;
    std::vector<int> pend;

    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    if (!pend.empty()) {
        mainChain.insert(mainChain.begin(), pend[0]);
    }

    size_t pendSize = pend.size();
    size_t numInserted = 1;
    int jacobIndex = 3;

    while (numInserted < pendSize) {
        size_t currentJacob = getJacobsthal(jacobIndex);
        size_t prevJacob = getJacobsthal(jacobIndex - 1);
        
        size_t start = std::min(currentJacob, pendSize);
        size_t end = prevJacob;

        for (size_t i = start; i > end; --i) {
            int valueToInsert = pend[i - 1];
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), valueToInsert);
            mainChain.insert(pos, valueToInsert);
            numInserted++;
        }
        jacobIndex++;
    }

    if (hasStraggler) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}

void PmergeMe::sortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) return;

    std::deque<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;

    if (arr.size() % 2 != 0) {
        straggler = arr.back();
        hasStraggler = true;
        arr.pop_back();
    }

    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    for (size_t i = 0; i < pairs.size(); ++i) {
        for (size_t j = i + 1; j < pairs.size(); ++j) {
            if (pairs[i].first > pairs[j].first) {
                std::swap(pairs[i], pairs[j]);
            }
        }
    }

    std::deque<int> mainChain;
    std::deque<int> pend;

    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    if (!pend.empty()) {
        mainChain.insert(mainChain.begin(), pend[0]);
    }

    size_t pendSize = pend.size();
    size_t numInserted = 1;
    int jacobIndex = 3;

    while (numInserted < pendSize) {
        size_t currentJacob = getJacobsthal(jacobIndex);
        size_t prevJacob = getJacobsthal(jacobIndex - 1);
        
        size_t start = std::min(currentJacob, pendSize);
        size_t end = prevJacob;

        for (size_t i = start; i > end; --i) {
            int valueToInsert = pend[i - 1];
            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), valueToInsert);
            mainChain.insert(pos, valueToInsert);
            numInserted++;
        }
        jacobIndex++;
    }

    if (hasStraggler) {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}

void PmergeMe::process(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    try {
        parseInput(argc, argv, vec, deq);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return;
    }

    printSequence("Before: ", vec);

    long long startVec = getTimeMicroseconds();
    sortVector(vec);
    long long endVec = getTimeMicroseconds();

    long long startDeq = getTimeMicroseconds();
    sortDeque(deq);
    long long endDeq = getTimeMicroseconds();

    printSequence("After:  ", vec);

    double timeVec = static_cast<double>(endVec - startVec);
    double timeDeq = static_cast<double>(endDeq - startDeq);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}