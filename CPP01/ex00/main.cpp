/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:54:44 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/21 21:05:21 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *heapZombie = newZombie("HeapZombie");
	heapZombie->annouce();

	randomChump("StackZombie");
	delete heapZombie;
	return (0);
}