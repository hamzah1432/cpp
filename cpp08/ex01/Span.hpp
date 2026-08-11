/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 15:35:45 by halmuhis          #+#    #+#             */
/*   Updated: 2026/08/11 20:50:18 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iterator>

class Span
{
private:
	unsigned int _N;
	std::vector<int> vec;

public:
	Span();
	Span(unsigned int);
	Span(const Span &);
	Span &operator=(const Span &);
	~Span();

	void addNumber(int);
	size_t shortestSpan();
	size_t longestSpan();

	class SpanFullException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Error: Span is already full, cannot add more numbers!";
		}
	};

	class NotEnoughNumbersException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Error: Not enough numbers to calculate span!";
		}
	};

	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end)
	{
		size_t distance = std::distance(begin, end);

		if (distance > _N - vec.size())
		{
			throw SpanFullException();
		}

		vec.insert(vec.end(), begin, end);
	}
};

#endif