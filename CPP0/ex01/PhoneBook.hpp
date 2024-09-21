/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:07:56 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/21 12:43:53 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>
#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
private:
	Contact contacts[8];
	int contact_count;
	void display_all_info();

public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void displayContact(int index);
	void search_contact();
};




#endif