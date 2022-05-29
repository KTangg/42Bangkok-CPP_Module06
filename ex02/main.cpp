/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:06:00 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/29 16:26:12 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

enum {A_e, B_e, C_e};


Base	*generate(void)
{
	int	i = rand() % 3;
	switch (i)
	{
		case (A_e):
			std::cout << "Generate: A" << std::endl;
			return (new A());
			break ;
		case (B_e):
			std::cout << "Generate: B" << std::endl;
			return (new B());
			break ;
		case (C_e):
			std::cout << "Generate: C" << std::endl;
			return (new C());
			break ;
		default:
			throw std::exception();
	}
}

void	identify(Base *p)
{
	A	*ptrA = NULL;
	B	*ptrB = NULL;
	C	*ptrC = NULL;

	ptrA = dynamic_cast<A *> (p);
	ptrB = dynamic_cast<B *> (p);
	ptrC = dynamic_cast<C *> (p);

	if (ptrA)
		std::cout << "A" << std::endl;
	if (ptrB)
		std::cout << "B" << std::endl;
	if (ptrC)
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A	&instance = dynamic_cast<A &> (p);
		(void) instance;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		(void) e;
	}

	try
	{
		B	&instance = dynamic_cast<B &> (p);
		(void) instance;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e)
	{
		(void) e;
	}

	try
	{
		C	&instance = dynamic_cast<C &> (p);
		(void) instance;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e)
	{
		(void) e;
	}
}

int	main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Base	*testPtr = generate();
		std::cout << "Identify Pointer: ";
		identify(testPtr);
		std::cout << "Identify Reference: ";
		identify(*testPtr);
		delete testPtr;
		std::cout << std::endl;
	}
	return (0);
}
