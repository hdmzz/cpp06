/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 06:06:36 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/12/09 01:36:17 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string const & literal) {
    this->convert(literal);
}

ScalarConverter::~ScalarConverter() {

}

ScalarConverter::ScalarConverter(ScalarConverter const & src) {
    *this = src;
}

ScalarConverter::ScalarConverter() {
    
}

/**************************************************************************
 *                          operator
***************************************************************************/

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &rhv)
{
    (void)rhv;
    return (*this);
}

void ScalarConverter::convert(std::string const & literal) 
{
	std::string specialTypes[6] = 
	{
		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"
	};
	std::string toChar = "";
    char *endPtr;
	long long toInt = 0;
	float toFloat = 0;
	double toDouble = 0;

	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) 
	{
		toChar = literal[0];
		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << static_cast<int>(toChar[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(toChar[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(toChar[0]) << ".0" << std::endl;
		return;
	}

	toInt = std::strtoll(literal.c_str(), &endPtr, 10);

	if (*endPtr == 'f') 
	{
		toFloat = std::atof(literal.c_str());
		toDouble = static_cast<double>(toFloat);
	} else {
        char *endPtrDouble;
		toDouble = std::strtod(literal.c_str(), &endPtrDouble);
        if (endPtrDouble == literal.c_str() || toDouble > std::numeric_limits<char>::max() || toDouble < std::numeric_limits<char>::min())
            toChar = "impossible";
		else
			toChar = static_cast<char>(toDouble);
		toDouble = static_cast<double>(toDouble);
		toFloat = static_cast<float>(toDouble);
	}

	for (int i = 0; i < 6; ++i) 
	{
		if (literal == specialTypes[i]) 
		{
			toChar = "impossible"; break;
		}
	}
	if (toChar == "") 
		toChar = "Non displayable";

	std::cout << "char: " << toChar << std::endl;
	if (toInt > std::numeric_limits<int>::max() || toInt < std::numeric_limits<int>::min()) 
	{
		std::cout << "int: impossible" << std::endl;
	} 
	else 
	{
		std::cout << "int: " << toInt << std::endl;
	}

	if (toChar == "impossible" && toFloat == 0) 
	{
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	} 
	else 
	{
		if (toChar != "impossible" && toFloat - static_cast<int>(toFloat) == 0) 
		{
			std::cout << "float: " << toFloat << ".0f" << std::endl;
			std::cout << "double: " << toDouble << ".0" << std::endl;
		} 
		else 
		{
			std::cout << "float: " << toFloat << "f" << std::endl;
			std::cout << "double: " << toDouble << std::endl;
		}
	}
}
