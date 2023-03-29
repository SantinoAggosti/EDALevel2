/**
 * @file Lequel.h
 * @author Lequel? language identification based on trigrams.
 * @brief 
 * @version 0.2
 * 
 * @copyright Copyright (c) 2022-2023
 * 
 * @cite https://towardsdatascience.com/understanding-cosine-similarity-and-its-application-fd42f585296a
 * 
 */

#ifndef _LEQUEL_H
#define _LEQUEL_H

#include <list>
#include <map>
#include <string>

#include "Text.h"

// TrigramProfile: Map of trigram -> frequency
typedef std::map<std::string, float> TrigramProfile;

// TrigramList: list of trigrams
typedef std::list<std::string> TrigramList;

struct Language
{
    std::string languageCode;
    TrigramProfile trigramProfile;
};

typedef std::list<Language> Languages;

// Functions
TrigramProfile buildTrigramProfile(const Text &text);
void normalizeTrigramProfile(TrigramProfile &trigramProfile);
float getCosineSimilarity(TrigramProfile &textProfile, TrigramProfile &languageProfile);
std::string identifyLanguage(const Text &text, Languages &languages);

#endif
