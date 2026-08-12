/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 08:50:05 by halmuhis          #+#    #+#             */
/*   Updated: 2026/08/12 08:50:20 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
public:
    static void process(int argc, char** argv);

private:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    static void parseInput(int argc, char** argv, std::vector<int>& vec, std::deque<int>& deq);
    static void printSequence(const std::string& prefix, const std::vector<int>& arr);
    static long long getTimeMicroseconds();
    static unsigned int getJacobsthal(int n);

    static void sortVector(std::vector<int>& arr);
    static void sortDeque(std::deque<int>& arr);
};

#endif