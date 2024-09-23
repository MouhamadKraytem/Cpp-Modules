/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:45:35 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/23 11:36:23 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty." << std::endl;
		return 1;
	}

	// Read the file content
	std::ifstream infile(filename.c_str()); // Use c_str() to convert std::string to const char*
	if (!infile)
	{
		std::cerr << "Error: Cannot open file " << filename << std::endl;
		return 1;
	}

	std::string content((std::istreambuf_iterator<char>(infile)),
						std::istreambuf_iterator<char>());
	infile.close();

	// Perform the replacement
	std::string replaced_content = replaceString(content, s1, s2);

	// Construct the output filename by replacing the extension with ".replace"
	std::string output_filename = getOutputFilename(filename);

	// Write the new content to the file
	std::ofstream outfile(output_filename.c_str()); // Use c_str() to convert std::string to const char*
	if (!outfile)
	{
		std::cerr << "Error: Cannot create output file." << std::endl;
		return 1;
	}
	outfile << replaced_content;
	outfile.close();

	return 0;
}
