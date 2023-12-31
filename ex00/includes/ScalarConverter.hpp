/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:52:50 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/12/06 06:35:16 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <limits>
# include <cstdlib>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const & src);
    ScalarConverter & operator=(ScalarConverter const &rhv);
public:
    static void convert(std::string const &literal);

    ScalarConverter(std::string const & literal);
    ~ScalarConverter();
};

#endif
