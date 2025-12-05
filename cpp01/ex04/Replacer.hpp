/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:03:45 by halmuhis          #+#    #+#             */
/*   Updated: 2025/12/05 17:55:16 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <string>

class Replacer
{
private:
    std::string _inputFilename;
    std::string _s1;
    std::string _s2;
    std::string _outputFilename;

    // Helper function to read the entire file content
    int _readFileContent(std::string& content);
    
    // Core logic: Performs the s1 to s2 replacement
    std::string _replaceContent(const std::string& content);

    // Helper function to write the processed content to the output file
    int _writeFileContent(const std::string& content);

public:
    Replacer(const std::string& filename, const std::string& s1, const std::string& s2, const std::string& output);
    int execute();
};

#endif