/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:10:39 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/21 12:12:38 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;


public:
	Contact();
	Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
	~Contact();

	std::string get_first_name();
	std::string get_last_name();
	std::string get_nick_name();
	std::string get_darkest_secret();
	std::string get_phone_number();

	void set_first_name(std::string str);
	void set_last_name(std::string str);
	void set_nick_name(std::string str);
	void set_darkest_secret(std::string str);
	void set_phone_number(std::string str);

	void displayContact();
};

#endif