/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:53:47 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/21 21:06:13 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	Zombie(std::string n);
	~Zombie();
	void annouce();
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

