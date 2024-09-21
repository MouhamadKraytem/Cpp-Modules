/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:02:33 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/21 11:51:03 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void print_options(){
	std::cout << "----------------------------------" << std::endl;
	std::cout << "--write ADD to add a new contact--" << std::endl;
	std::cout << "--write SEARCH a contact        --" << std::endl;
	std::cout << "--write EXIT to finish          --" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
}
int main()
{
	std::string input;
	print_options();
	PhoneBook phone_book = PhoneBook();
	while (1)
	{
		std::cout << "Enter a command" << std::endl;
		std::cin >> input;
		if (input == "ADD")
		{
			phone_book.addContact();
		}
		else if(input == "SEARCH")
		{
			phone_book.search_contact();
		}
		else if(input == "EXIT")
		{
			std::cout << "exit" <<std::endl;
			break;
		}else
		{
			std::cout << "Invalide Input" << std::endl;
		}
		
	}
	
	return 0;
}
