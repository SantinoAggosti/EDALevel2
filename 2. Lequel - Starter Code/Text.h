/**
 * @file Text.h
 * @author Marc S. Ressl
 * @brief Reads text files.
 * @version 0.2
 * 
 * @copyright Copyright (c) 2022-2023
 * 
 */

#ifndef _TEXT_H
#define _TEXT_H

#include <list>
#include <string>

// Data type: list of text lines
typedef std::list<std::string> Text;

// Functions
bool getText(const std::string &s, Text &text);
bool getTextFromFile(const std::string path, Text &text);

#endif
