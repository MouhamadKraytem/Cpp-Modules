/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:45:32 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/23 11:34:33 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HELPER_HPP
#define HELPER_HPP

#include <iostream>
#include <fstream>
#include <string>

// Function declaration
std::string replaceString(const std::string &original, const std::string &s1, const std::string &s2);
std::string getOutputFilename(const std::string &filename);
#endif