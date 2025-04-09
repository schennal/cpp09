/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:35:00 by schennal          #+#    #+#             */
/*   Updated: 2024/08/20 17:37:05 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>

int main(int argc, char **argv)
{
	BitcoinExchange	btc;

	if (argc != 2)
	{
		std::cout << "Usage: ./btc [filename]" << std::endl;
		return (1);
	
	}

	try
	{
		btc.loadDataBase();
		btc.processInput(argv[1]);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
