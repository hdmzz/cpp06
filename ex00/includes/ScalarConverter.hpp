/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:52:50 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/11/28 21:42:48 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const & src);
    ScalarConverter & operator=(ScalarConverter const & rhv);

    int _type;

    bool _isChar(std::string const & literal);
    bool _isInt(std::string const & literal);
    bool _isDouble(std::string const & literal);
    bool _isFloat(std::string const & literal);

    void _extractType(std::string const & literal);    

    int _errorFlag;
//stocker les valeur dans ces variables apres conversion avec static_cast
    std::string _toChar;
    int _toInt;
    float _toFloat;
    double _toDouble;

    enum e_types {
        DEFAULT,
        CHAR,
        INT,
        FLOAT,
        DOUBLE
    };
    
    enum e_error {
        CHARACTER,
    };
public:
    static void convert(std::string const & literal);
    ~ScalarConverter();
};

ScalarConverter::ScalarConverter() : _toChar(""), _toInt(0), _toDouble(0), _toFloat(0), _errorFlag(0), _type(DEFAULT)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const & src) : _toChar(src._toChar), _toInt(src._toInt), _toDouble(src._toDouble), _toFloat(src._toFloat)
{
    *this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhv) {
    (void) rhv;
    return (*this);
}

bool ScalarConverter::_isChar(std::string const & literal) {
    if (literal.length() == 1){
        if (!std::isprint(literal[0]))
               _errorFlag = CHARACTER;
        return (true);
    }
    return (false);
}

bool ScalarConverter::_isInt(std::string const & literal) {
    long nb
}

void ScalarConverter::_extractType(std::string const & literal) {
    if (_isChar(literal))
        this->_type = CHAR;
    else if () 
}

void ScalarConverter::convert(std::string const & literal) {
    //Identifier le type du literal
    
}

#endif
