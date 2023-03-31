/**
 * @file Lequel.cpp
 * @author Lequel? language identification based on trigrams.
 * @brief 
 * @version 0.2
 * 
 * @copyright Copyright (c) 2022-2023
 * 
 * @cite https://towardsdatascience.com/understanding-cosine-similarity-and-its-application-fd42f585296a
 * 
 */

#include <cmath>
#include <codecvt>
#include <locale>
#include <iostream>

#include "Lequel.h"

using namespace std;

#define TESTING 1

/**
 * @brief Builds a trigram profile from a given text.
 * 
 * @param text List of lines (Text)
 * @return TrigramProfile The trigram profile
 */
TrigramProfile buildTrigramProfile(const Text &text)
{
    wstring_convert<std::codecvt_utf8_utf16<wchar_t> > converter;

    //SANTINO
    // Breve analisis de codigo:
    // el programa itera en n textos con m caracteres por texto, por lo tanto, realiza m*n iteraciones.
    // Sin embargo, la logica principal se orienta a los caracteres, por lo que el algoritmo tiene 
    // complejidad computacional O(m). 


    TrigramProfile trigramProfile;
    string aux = "aaa"; // Se inicializa string auxiliar para gurdar los trigramas


    for (string str : text)
    {
        int aux_index = 0;  // Indice de paso de string auxiliar

        wstring auxiliar_wString = converter.from_bytes(aux);
        wstring unicodeString = converter.from_bytes(str);

        for (int i = 0; i < unicodeString.length(); i++) {   //Como no se cuantas letras hay por string, debo seguir iterando hasta encontrarme con un terminador.

            if (iswupper(unicodeString[i])) {   // Si es una mayuscula, entonces la cambio a minuscula para considerarla igual a su trigrama designado
                unicodeString[i] = towlower(unicodeString[i]);
            }

            if (iswpunct(unicodeString[i])) {   // Si es algun tipo de puntuacion, la ignoro y paso a la siguiente letra.
                continue;
            }

            auxiliar_wString[aux_index] = unicodeString[i];  // En el caso de que no se llege a la longitud de 3 caracteres, no se entra al while loop, y por ende se termina.
            aux_index++;

            if (aux_index % 3 == 0) {   // Si ya se leyeron tres caracteres
                string trigram_string = converter.to_bytes(auxiliar_wString);   // se vuelve a pasar el valor a un string


                if (trigramProfile.count(trigram_string)) {
                    trigramProfile.at(trigram_string)++;  // Aumento el valor de la clave del trigrama encontrado
                    
                }
                else {
                    trigramProfile.emplace(trigram_string, 1); // Creacion de Nuevo Trigrama con contador 1
                }

                aux_index = 0;
                i -= 2;
            }
        }
    }
    return trigramProfile;
}

/**
 * @brief Normalizes a trigram profile.
 * 
 * @param trigramProfile The trigram profile.
 */
void normalizeTrigramProfile(TrigramProfile &trigramProfile)
{
    // Your code goes here...

    return;
}

/**
 * @brief Calculates the cosine similarity between two trigram profiles
 * 
 * @param textProfile The text trigram profile
 * @param languageProfile The language trigram profile
 * @return float The cosine similarity score
 */
float getCosineSimilarity(TrigramProfile &textProfile, TrigramProfile &languageProfile)
{
    // Your code goes here...

    return 0; // Replace...
}

/**
 * @brief Identifies the language of a text.
 * 
 * @param text A Text (list of lines)
 * @param languages A list of Language objects
 * @return string The language code of the most likely language
 */
string identifyLanguage(const Text &text, Languages &languages)
{
    // Your code goes here...

    return ""; // Replace...
}
