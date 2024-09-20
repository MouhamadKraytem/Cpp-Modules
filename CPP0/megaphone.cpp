/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:55:49 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/20 11:22:53 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		int i = 1 , j = 0;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				if (isalpha(argv[i][j]))
					argv[i][j] = (char)toupper(argv[i][j]);
				j++;
			}
			if (i == argc - 1)
				std::cout << argv[i];
			else
				std::cout << argv[i] << " ";
			i++;
		}
		
	}
	std::cout << std::endl ;
	return 0;
}
