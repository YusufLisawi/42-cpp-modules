/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 23:08:38 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/30 00:04:16 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main()
{
    Data* data = new Data;

    data->s1 = "Hello";
    data->s2 = "World";

    uintptr_t serialized = Serialize::serialize(data);

    std::cout << "Serialized value: " << serialized << std::endl;

    Data* deserialized = Serialize::deserialize(serialized);

    std::cout << "Deserialized value: " << deserialized->s1 << deserialized->s2 << std::endl;

    delete data;
    return 0;
}
