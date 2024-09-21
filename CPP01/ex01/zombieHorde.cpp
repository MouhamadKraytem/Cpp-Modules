/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:07:05 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/21 22:15:03 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	// Allocate an array of Zombies
	Zombie *horde = new Zombie[N];
	// Initialize each Zombie with the given name
	for (int i = 0; i < N; ++i)
	{
		new (&horde[i]) Zombie(name); // Placement new to call constructor
	}
	return horde;
}