/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhesn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 12:05:32 by halmuhis          #+#    #+#             */
/*   Updated: 2026/06/07 12:12:08 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    Data data;
    data.x = 42;
    data.y = 84;
    std::cout << "Original data: " << data.x << ", " << data.y << std::endl;
    std::cout << "Address of original data: " << &data << std::endl;
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized data (uintptr_t): " << raw << std::endl;
    Data *deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized data: " << deserializedData->x << ", " << deserializedData->y << std::endl;
    std::cout << "Address of deserialized data: " << deserializedData << std::endl;

    if (deserializedData == &data)
        std::cout << "Deserialization successful: deserialized data is the same as original data." << std::endl;
    else
        std::cout << "Deserialization failed: deserialized data is not the same as original data." << std::endl;

    return (0);
}