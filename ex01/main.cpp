/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:24:42 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/29 15:55:52 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "serial.hpp"

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t> (ptr));
}

Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *> (raw));
}

int	main(void)
{
	Data	testData;

	testData.i = 42;
	testData.str = std::string("Bangkok");

	Data	*testPtr = deserialize(serialize(&testData));

	std::cout << testPtr->i << testPtr->str << std::endl << std::endl;

	std::cout << "Changing data value via pointer" << std::endl << std::endl;
	testPtr->i = 43;
	testPtr->str = std::string("Nothing");

	std::cout << testData.i << testData.str << std::endl;
}
