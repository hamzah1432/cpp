/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 16:21:22 by halmuhis          #+#    #+#             */
/*   Updated: 2026/08/11 20:54:55 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &data, int target)
{
	return std::find(data.begin(), data.end(), target);
}

template <typename T>
typename T::const_iterator easyfind(const T &data, int target)
{
	return std::find(data.begin(), data.end(), target);
}

#endif