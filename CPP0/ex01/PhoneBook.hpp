/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:07:56 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/21 10:38:46 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int contact_count;
	void PhoneBook:: display_all_info();

public:
	PhoneBook();
	~PhoneBook();

	void PhoneBook::addContact();
	void PhoneBook::displayContact(int index);
	void PhoneBook::search_contact();
};




#endif