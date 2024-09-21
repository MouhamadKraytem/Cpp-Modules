/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:07:01 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/21 22:15:54 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 5; // Number of zombies
	std::string name = "Zombie";

	// Create a horde of zombies
	Zombie *horde = zombieHorde(N, name);

	// Call announce() for each zombie
	for (int i = 0; i < N; ++i)
	{
		horde[i].annouce();
	}

	// Clean up memory
	delete[] horde; // Deletes the allocated array of zombies

	return 0;
}