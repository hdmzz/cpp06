/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:17:58 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/12/06 11:50:15 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main() {
    Data test = {.value = 43, .str = "Test"};
    uintptr_t returnValue = Serializer::serialize(&test);
    Data* deserialValue = Serializer::deserialize(returnValue);
    std::cout << *deserialValue << std::endl;
    std::cout << "Address of Deserialized value " << deserialValue << std::endl; 
}
