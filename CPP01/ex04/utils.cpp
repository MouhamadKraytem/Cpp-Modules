/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:45:38 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/23 11:34:26 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

std::string replaceString(const std::string &original, const std::string &s1, const std::string &s2)
{
	std::string result;
	std::size_t pos = 0, found;

	while ((found = original.find(s1, pos)) != std::string::npos)
	{
		result.append(original, pos, found - pos); // Add text before match
		result.append(s2);						   // Add replacement string
		pos = found + s1.length();				   // Move past the match
	}

	result.append(original, pos); // Add remaining text
	return result;
}

std::string getOutputFilename(const std::string &filename)
{
	std::size_t lastDot = filename.find_last_of('.');
	if (lastDot == std::string::npos)
	{
		// No extension found, append ".replace" to the full filename
		return filename + ".replace";
	}
	else
	{
		// Replace the extension with ".replace"
		return filename.substr(0, lastDot) + ".replace";
	}
}
