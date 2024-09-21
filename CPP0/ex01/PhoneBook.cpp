/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:07:29 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/21 14:08:52 by mkraytem         ###   ########.fr       */
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
		i++;
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
		i++;
	}
	return 1;
};

void truncate_str(std::string &str)
{
	if (str.length() > 10)
	{
		str = str.substr(0, 9) + "."; // Truncate to 9 characters + "."
	}
}

void PhoneBook::display_all_info()
{
	std::cout << std::setw(6) << "Index"
			  << " | " << std::setw(11) << "First Name"
			  << " | " << std::setw(11) << "Last Name"
			  << " | " << std::setw(11) << "Nick Name"
			  << std::endl;

	for (int i = 0; i < this->contact_count; i++)
	{
		// Get contact details
		std::string fn = this->contacts[i].get_first_name();
		std::string ln = this->contacts[i].get_last_name();
		std::string nn = this->contacts[i].get_nick_name();

		// Truncate long strings to fit within the column
		truncate_str(fn);
		truncate_str(ln);
		truncate_str(nn);

		// Print row with formatted output
		std::cout << std::setw(6) << i
				  << " | " << std::setw(11) << fn
				  << " | " << std::setw(11) << ln
				  << " | " << std::setw(11) << nn
				  << std::endl;
	}
	std::cout << std::endl;
}

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
	std::string fn, ln, nn, ds, pn;

	// First Name
	do
	{
		std::cout << "Enter the first name: ";
		std::cin >> fn;
		if (validate_str(fn) == 0 || fn.empty())
		{
			std::cout << "Invalid first name. Please enter alphabetic characters only." << std::endl;
		}
	} while (validate_str(fn) == 0 || fn.empty());

	// Last Name
	do
	{
		std::cout << "Enter the last name: ";
		std::cin >> ln;
		if (validate_str(ln) == 0 || ln.empty())
		{
			std::cout << "Invalid last name. Please enter alphabetic characters only." << std::endl;
		}
	} while (validate_str(ln) == 0 || ln.empty());

	// Nickname
	do
	{
		std::cout << "Enter the nickname: ";
		std::cin >> nn;
		if (validate_str(nn) == 0 || nn.empty())
		{
			std::cout << "Invalid nickname. Please enter alphabetic characters only." << std::endl;
		}
	} while (validate_str(nn) == 0 || nn.empty());

	// Darkest Secret (using getline to allow spaces)
	std::cin.ignore(); // Ignore leftover newline from previous input
	do
	{
		std::cout << "Enter the darkest secret: ";
		std::getline(std::cin, ds); // Allow spaces
		if (ds.empty())				// Check if empty
		{
			std::cout << "Invalid secret. Please enter a valid string." << std::endl;
		}
	} while (ds.empty());

	// Phone Number
	do
	{
		std::cout << "Enter the phone number: ";
		std::cin >> pn;
		if (!validate_nbr(pn) || pn.empty())
		{
			std::cout << "Invalid phone number. Please enter a valid phone number." << std::endl;
		}
	} while (!validate_nbr(pn) || pn.empty());
	// Add the contact
	contacts[contact_count % 8] = Contact(fn, ln, nn, pn, ds); // Assuming an array of size 8
	this->contact_count++;

	std::cin.ignore();
	std::cout << "Contact added successfully!";
}

void PhoneBook::displayContact(int index)
{
	if (index >= 0 && index < this->contact_count)
	{
		this->contacts[index].displayContact();
	}
};

void PhoneBook::search_contact()
{
	int i;

	if (this->contact_count == 0)
	{
		std::cout << "no contact " << std::endl;
	}
	else
	{
		this->display_all_info();
		do
		{
			std::cout << "select an index" << std::endl;
			std::cin >> i;
			if (i < 0 || i >= this->contact_count)
			{
				std::cout << "Invalid input, Please enter a valide index" << std::endl;
			}
			std::cin.ignore();
		} while (i < 0 || i >= this->contact_count);
		// std::cin.ignore();
		this->displayContact(i);
	}
};

PhoneBook::~PhoneBook() {
};
