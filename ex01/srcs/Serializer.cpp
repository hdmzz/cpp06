/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:09:49 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/12/06 11:46:46 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

Serializer::Serializer(void) {
    
}

Serializer::Serializer(Serializer & src) {
    *this = src;
}

Serializer::~Serializer() {

}

Serializer & Serializer::operator=(Serializer const & rhv) {
    (void)rhv;
    return *this;
}

std::ostream &	operator<<(std::ostream & os, const Data & obj) {
	os << "Data structure stored at address [" << &obj << "]"
		<< "\n\t- value : " << obj.value
		<< "\n\t- str: " << obj.str << std::endl;
	return (os);
}
