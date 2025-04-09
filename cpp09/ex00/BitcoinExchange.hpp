/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:34:44 by schennal          #+#    #+#             */
/*   Updated: 2024/08/20 17:39:37 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <exception>
#include <iomanip>
#include <sstream>

class BitcoinExchange
{
private:
	std::map<std::string, double>	map;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange	&operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();

	int		validateInputDate(std::string &line, std::string &date);
	int		validateInputValue(std::string &line, std::string &value);
	bool	isValidDate(std::string date);

	bool 	isLeapYear(int year);
	void	printExchange(std::string date, double value, double exchangeRate);


	void	loadDataBase();
	void	processInput(const char *filename);
	void	processValidInput(std::string &date, std::string &value);
	void	displayDataBase() const;


	class InvalidLineException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
	class FailedToOpenDataException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
	class FailedToOpenInputException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
};

#endif
