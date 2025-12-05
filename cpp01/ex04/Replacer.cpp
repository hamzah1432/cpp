/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:04:07 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/05 17:53:21 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Replacer::Replacer(const std::string &filename, const std::string &s1, const std::string &s2, const std::string &output)
    : _inputFilename(filename), _s1(s1), _s2(s2), _outputFilename(output) {}

// --- File Reading Helper ---
int Replacer::_readFileContent(std::string &content)
{
    // Use std::ifstream (C++ standard library)
    std::ifstream inputFile(this->_inputFilename.c_str());

    if (!inputFile.is_open())
    {
        std::cerr << "Error: Cannot open input file: " << this->_inputFilename << std::endl;
        return 1;
    }

    // Read the entire file content into the string 'content'
    // This is the efficient C++ way using iterators:
    content.assign(
        (std::istreambuf_iterator<char>(inputFile)),
        (std::istreambuf_iterator<char>()));

    inputFile.close();
    return 0;
}

// --- Replacement Logic (Core of the exercise) ---
std::string Replacer::_replaceContent(const std::string &content)
{
    // If s1 is empty, replacement is trivial (or ill-defined, choosing to return original)
    if (this->_s1.empty())
    {
        return content;
    }

    std::string replacedContent;
    size_t pos = 0;
    size_t found_pos;

    // Loop: Find all occurrences of _s1
    while ((found_pos = content.find(this->_s1, pos)) != std::string::npos)
    {
        // 1. Append the segment of the content BEFORE the found occurrence
        replacedContent += content.substr(pos, found_pos - pos);

        // 2. Append the replacement string (_s2)
        replacedContent += this->_s2;

        // 3. Advance the position PAST the replaced string
        pos = found_pos + this->_s1.length();
    }

    // 4. Append any remaining content after the last replacement
    replacedContent += content.substr(pos);

    return replacedContent;
}

// --- File Writing Helper ---
int Replacer::_writeFileContent(const std::string &content)
{
    // Use std::ofstream (C++ standard library)
    std::ofstream outputFile(this->_outputFilename.c_str());

    if (!outputFile.is_open())
    {
        std::cerr << "Error: Cannot create/open output file: " << this->_outputFilename << std::endl;
        return 1;
    }

    // Write the content to the output file
    outputFile << content;

    outputFile.close();
    std::cout << "Success: Content written to " << this->_outputFilename << std::endl;
    return 0;
}

// --- Main Execution ---
int Replacer::execute()
{
    std::string content;
    std::string replaced;

    if (this->_readFileContent(content) != 0)
        return 1;

    // Check if the input file was empty
    if (content.empty())
    {
        std::cout << "Warning: Input file is empty. Creating empty .replace file." << std::endl;
    }

    replaced = this->_replaceContent(content);

    if (this->_writeFileContent(replaced) != 0)
        return 1;

    return 0;
}