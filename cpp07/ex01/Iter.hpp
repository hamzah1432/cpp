/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 15:35:45 by halmuhis          #+#    #+#             */
/*   Updated: 2026/07/07 17:40:59 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T *array, const std::size_t length, void (*func)(T &)) {
    for (std::size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

template <typename T>
void iter(const T *array, const std::size_t length, void (*func)(const T &)) {
    for (std::size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

#endif