/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:05:56 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/12/06 13:06:28 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>

Base * generate(void) {
    int randomNb = std::rand() % 3;
    switch (randomNb) {
        case 0:
            return (new A);
        case 1:
            return (new B);
        case 2:
            return (new C);
    }   
    return NULL;
}

void identify(Base* p) {
    std::cout << "identified as a pointer: ";
    if (dynamic_cast<A *>(p))
        std::cout << "A " ;
    else if (dynamic_cast<B *>(p))
        std::cout << "B ";
    else if (dynamic_cast<C *>(p))
        std::cout << "C ";
    else
        std::cout << "Unknow ";
}

void identify(Base& p) {
    std::cout << "identified as a reference: ";

    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "A ";
    } catch (std::bad_cast&) {}
    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "B ";
    } catch (std::bad_cast&) {}
    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "C ";
    } catch (std::bad_cast&) {}
}

int main() {
    Base *	p;
	std::srand(std::time(NULL));

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Test [" << i << "]:\t";
		p = generate();
		std::cout << ", ";
		identify(p);
		std::cout << ", ";
		identify(*p);
		delete (p);
		std::cout << std::endl;
	}
	return (0);
}
