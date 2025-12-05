/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:04:07 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/05 17:57:14 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Replacer::Replacer(const std::string &filename, const std::string &s1, const std::string &s2, const std::string &output)
    : _inputFilename(filename), _s1(s1), _s2(s2), _outputFilename(output) {}

int Replacer::_readFileContent(std::string &content)
{
    std::ifstream inputFile(this->_inputFilename.c_str());

    if (!inputFile.is_open())
    {
        std::cerr << "Error: Cannot open input file: " << this->_inputFilename << std::endl;
        return 1;
    }

    content.assign(
        (std::istreambuf_iterator<char>(inputFile)),
        (std::istreambuf_iterator<char>()));

    inputFile.close();
    return 0;
}

std::string Replacer::_replaceContent(const std::string &content)
{
    if (this->_s1.empty())
    {
        return content;
    }

    std::string replacedContent;
    size_t pos = 0;
    size_t found_pos;


    while ((found_pos = content.find(this->_s1, pos)) != std::string::npos)
    {
        replacedContent += content.substr(pos, found_pos - pos);

        replacedContent += this->_s2;

        pos = found_pos + this->_s1.length();
    }

    replacedContent += content.substr(pos);

    return replacedContent;
}

int Replacer::_writeFileContent(const std::string &content)
{
    std::ofstream outputFile(this->_outputFilename.c_str());

    if (!outputFile.is_open())
    {
        std::cerr << "Error: Cannot create/open output file: " << this->_outputFilename << std::endl;
        return 1;
    }

    outputFile << content;

    outputFile.close();
    std::cout << "Success: Content written to " << this->_outputFilename << std::endl;
    return 0;
}

int Replacer::execute()
{
    std::string content;
    std::string replaced;

    if (this->_readFileContent(content) != 0)
        return 1;

    if (content.empty())
    {
        std::cout << "Warning: Input file is empty. Creating empty .replace file." << std::endl;
    }

    replaced = this->_replaceContent(content);

    if (this->_writeFileContent(replaced) != 0)
        return 1;

    return 0;
}