/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 15:35:45 by halmuhis          #+#    #+#             */
/*   Updated: 2026/07/18 10:56:38 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0) {}
Span::Span(unsigned int N) : _N(N) {}
Span::Span(const Span &other) : _N(other._N), vec(other.vec) {}
Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_N = other._N;
		vec = other.vec;
	}
	return *this;
}
Span::~Span() {}

void Span::addNumber(int number)
{
	if (vec.size() >= _N)
		throw SpanFullException();
	vec.push_back(number);
}

size_t Span::shortestSpan()
{
	if (vec.size() < 2)
	{
		throw NotEnoughNumbersException();
	}
	std::vector<int> sortedVec = vec;
	std::sort(sortedVec.begin(), sortedVec.end());

	size_t minSpan = static_cast<size_t>(sortedVec[1]) - static_cast<size_t>(sortedVec[0]);
	for (size_t i = 2; i < sortedVec.size(); ++i)
	{
		size_t span = static_cast<size_t>(sortedVec[i]) - static_cast<size_t>(sortedVec[i - 1]);
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

size_t Span::longestSpan()
{
	if (vec.size() < 2)
	{
		throw NotEnoughNumbersException();
	}
	std::vector<int>::const_iterator min_it = std::min_element(vec.begin(), vec.end());
	std::vector<int>::const_iterator max_it = std::max_element(vec.begin(), vec.end());
	return static_cast<size_t>(*max_it) - static_cast<size_t>(*min_it);
}