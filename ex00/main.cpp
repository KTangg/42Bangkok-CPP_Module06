/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 10:40:33 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/29 12:36:42 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "ConvertType.hpp"

void	usage(void)
{
	std::cerr << "Invalid arguments" << std::endl;
	std::cerr << "Usage: ./convert scalar_value" << std::endl;
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
		if (argc != 2)
		{
			usage();
		}
		char const	*str = argv[1];
		std::string	literal = std::string(str);
		ConvertType	convert = ConvertType(literal);
		convert.printAll();
}
