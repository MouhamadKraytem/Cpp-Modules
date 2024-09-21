/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:02:33 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/21 13:54:15 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <string>

// Function to print options
void print_options()
{
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "-- ADD to add a new contact         --" << std::endl;
	std::cout << "-- SEARCH to search a contact       --" << std::endl;
	std::cout << "-- EXIT to exit                     --" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << std::endl;
}

// Custom function to convert a string to uppercase
void to_uppercase(std::string &input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] >= 'a' && input[i] <= 'z')
		{
			input[i] = input[i] - ('a' - 'A'); // Convert lowercase to uppercase
		}
	}
}

std::string trim_whitespace(const std::string &str)
{
	size_t start = str.find_first_not_of(' ');
	size_t end = str.find_last_not_of(' ');

	if (start == std::string::npos || end == std::string::npos)
	{
		return ""; // Return empty string if input is all whitespace
	}

	return str.substr(start, end - start + 1);
}

int main()
{
	std::string input;
	PhoneBook phone_book; // Assuming the PhoneBook class is defined elsewhere

	print_options();

	while (true)
	{
		std::cout << "Enter command: \n";
		std::getline(std::cin, input); // Use getline to capture full command

		// Convert the input to uppercase for case-insensitive comparison
		input = trim_whitespace(input);
		to_uppercase(input);

		if (input.empty())
		{
			continue;
		}
		else if (input == "ADD")
		{
			phone_book.addContact(); // Add a new contact
		}
		else if (input == "SEARCH")
		{
			phone_book.search_contact(); // Show contact info (assuming display_all_info exists)
		}
		else if (input == "EXIT")
		{
			std::cout << "Exiting program..." << std::endl;
			break; // Exit the loop
		}
		else
		{
			std::cout << "Invalid command. Please try again." << std::endl;
			print_options(); // Show the options again for clarity
		}
		input.clear();
		std::cout << std::endl;
	}

	return 0;
}