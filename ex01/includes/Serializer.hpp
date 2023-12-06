/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:08:22 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/12/06 11:46:30 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <iostream>
struct Data
{
    int value;
    std::string str;
};

class Serializer
{
public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);

    Serializer(void);
    Serializer(Serializer &src);
    ~Serializer();
    Serializer & operator=(Serializer const &rhv);
};

std::ostream &operator<<(std::ostream &os, const Data &obj);

#endif
