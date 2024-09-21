/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:07:46 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/21 14:12:27 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {

};

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
	this->first_name = fn;
	this->last_name = ln;
	this->nick_name = nn;
	this->darkest_secret = ds;
	this->phone_number = pn;
}



std::string Contact::get_first_name(){
	return this->first_name;
};
std::string Contact::get_last_name(){
	return this->last_name;
};

std::string Contact::get_nick_name(){
	return this->nick_name;
};
std::string Contact::get_darkest_secret(){
	return this->darkest_secret;
};
std::string Contact::get_phone_number(){
	return this->phone_number;
};


void Contact::set_first_name(std::string str){
	this->first_name = str;
};
void Contact::set_last_name(std::string str){
	this->last_name = str;
};
void Contact::set_nick_name(std::string str){
	this->nick_name = str;
};
void Contact::set_darkest_secret(std::string str){
	this->darkest_secret = str;
};
void Contact::set_phone_number(std::string str){
	this->phone_number = str;
};

void Contact::displayContact(){
	std::cout << "First name : " << this->first_name << std::endl;
	std::cout << "Last name : " << this->last_name << std::endl;
	std::cout << "Nick name : " << this->nick_name << std::endl;
	std::cout << "Phone number : " << this->phone_number << std::endl;
	std::cout << "Darkest Secret : " << this->darkest_secret << std::endl;
	// std::cout << std::endl;
};
Contact::~Contact()
{
}
