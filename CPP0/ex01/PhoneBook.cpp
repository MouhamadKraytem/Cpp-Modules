/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:07:29 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/21 11:47:38 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int validate_str(std::string str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (!isalpha(str[i]))
			return 0;
	}
	return 1;
};

int validate_nbr(std::string nbr)
{
	int i = 0;
	while (nbr[i] != '\0')
	{
		if (!isdigit(nbr[i]))
			return 0;
	}
	return 1;
};

void truncate_str(std::string str)
{
	int i = 0;
	while (str[i] != '\0' && i < 10)
	{
		std::cout << str[i];
	}
	if (i == 10)
	{
		std::cout << ".";
	}
}

void PhoneBook::display_all_info() {
	int i = 0;
	std::cout << "index | first name | last name | nick name" << std::endl;
	while (i < this->contact_count)
	{
		std::string fn = this->contacts[i].get_first_name();
		std::string ln = this->contacts[i].get_first_name();
		std::string nn = this->contacts[i].get_first_name();
		std::cout << "  " << i << "  "<< "|" ;
		truncate_str(fn);
		std::cout  << "|" ;
		truncate_str(ln);
		std::cout  << "|" ;
		truncate_str(nn);
		std::cout << std::endl;
		i++;
	}
	std::cout << std::endl;
};

PhoneBook::PhoneBook(/* args */)
{
	int i = 0;
	this->contact_count = 0;
	while (i < 8)
	{
		this->contacts[i] = Contact();
		i++;
	}
};

void PhoneBook::addContact()
{
	std::string fn, ln, ds, pn, nn;
	do
	{
		std::cout << "enter the first name";
		std::cin >> fn;
	} while (!validate_str(fn) || fn == "");
	do
	{
		std::cout << "enter the last name";
		std::cin >> ln;
	} while (!validate_str(ln) || ln == "");
	do
	{
		std::cout << "enter the nick name";
		std::cin >> nn;
	} while (!validate_str(nn) || nn == "");
	do
	{
		std::cout << "enter the darkest secret";
		std::cin >> ds;
	} while (!validate_str(ds) || ds == "");
	do
	{
		std::cout << "enter the phone number";
		std::cin >> pn;
	} while (!validate_str(pn) || pn == "");
	contacts[contact_count % 8] = Contact(fn, ln, nn, pn, ds);
	this->contact_count++;
	std::cout << "Contact added successfully" << std::endl;
};

void PhoneBook::displayContact(int index) {
	if (index >= 0 && index < 8)
	{
		this->contacts[index].displayContact();
	}
	
};

void PhoneBook::search_contact() {
	int i;

	this->display_all_info();
	std::cout << "select an index" << std::endl;
	std::cin >> i;
	if (i < 0 || i >= 8)
		std::cout << "wrong input !!" << std::endl;
	else
		this->displayContact(i);
};

PhoneBook::~PhoneBook() {
};
