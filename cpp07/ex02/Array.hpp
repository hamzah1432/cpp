/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 15:35:45 by halmuhis          #+#    #+#             */
/*   Updated: 2026/07/07 17:40:25 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
    T *_elements;
    unsigned int _size;

public:
    Array() : _elements(NULL), _size(0) {}

    Array(unsigned int n) : _size(n)
    {
        _elements = new T[n]();
    }

    Array(const Array &other) : _size(other._size)
    {
        if (_size > 0)
        {
            _elements = new T[_size]();
            for (unsigned int i = 0; i < _size; i++)
            {
                _elements[i] = other._elements[i];
            }
        }
        else
        {
            _elements = NULL;
        }
    }

    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] _elements;

            _size = other._size;
            if (_size > 0)
            {
                _elements = new T[_size]();
                for (unsigned int i = 0; i < _size; i++)
                {
                    _elements[i] = other._elements[i];
                }
            }
            else
            {
                _elements = NULL;
            }
        }
        return *this;
    }

    ~Array()
    {
        delete[]
    }

    class OutOfBoundsException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Index is out of bounds!";
        }
    };

    T &operator[](unsigned int index)
    {
        if (index >= _size)
        {
            throw OutOfBoundsException();
        }
        return _elements[index];
    }

    const T &operator[](unsigned int index) const
    {
        if (index >= _size)
        {
            throw OutOfBoundsException();
        }
        return _elements[index];
    }

    unsigned int size() const
    {
        return _size;
    }
};

#endif