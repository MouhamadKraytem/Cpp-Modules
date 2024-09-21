/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:53:41 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/21 21:06:57 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{

}
Zombie::Zombie(std::string n)
{
	this->name = n;
}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed." << std::endl;
}

void Zombie::annouce() 
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}