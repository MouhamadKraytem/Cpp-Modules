/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:29:00 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/21 23:33:00 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

Weapon::Weapon(){
	
}
Weapon ::Weapon (std::string type){
	this->type = type;
};

const std::string &Weapon::getType() const
{
	return type;
}

void Weapon::setType(std::string type) {
	this->type = type;
};

Weapon::~Weapon()
{
	// std::cout << this->getType() << " lost..." << std::endl;
}
