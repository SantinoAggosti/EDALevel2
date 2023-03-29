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
    //Personlamente, se me ocurre iterar a lo largo de la lista de strings, accediendo al elemento en el que estoy parado, y a los dos siguientes, en el caso de que
    //Alguno de los elementos sea cero, paso a la siguiente posicion de la lista e intento completar las tres letras. Asi hasta que se acaben las posiciones de la lista
    //
    TrigramProfile trigramProfile;
    map<std::string, float>::iterator aux_iterator;    // Iterador utilizado para mejorar la velocidad de busqueda de "emplace_hint". Es constante, dado que
    string aux = "aaa";

    for (string str : text)
    {
        wstring auxiliar_wString = converter.from_bytes(aux);
        wstring unicodeString = converter.from_bytes(str);

        int reading_index = 0;
        int unicode_index = 0;

        while (unicodeString[unicode_index] != 0) {   //Como no se cuantas letras hay por string, debo seguir iterando hasta encontrarme con un terminador.

            auxiliar_wString[reading_index] = unicodeString[unicode_index];  // En el caso de que no se llege a la longitud de 3 caracteres, no se entra al while loop, y por ende se termina.
            
            reading_index++;
            unicode_index++;

            if (reading_index % 3 == 0) {   // Si ya se leyeron tres caracteres
                string trigram_string = converter.to_bytes(auxiliar_wString);   // se vuelve a pasar el valor a un string


                if (trigramProfile.count(trigram_string)) {
                    trigramProfile.at(trigram_string)++;  // Aumento el valor de la clave del trigrama encontrado
                    

                }
                else {
                    trigramProfile.emplace(trigram_string, 1); // Creacion de Nuevo Trigrama con contador 1
                }

                #ifdef TESTING
                cout << trigram_string << endl;
                cout << trigramProfile.at(trigram_string) << endl;
                #endif

                reading_index = 0;
                unicode_index -= 2;
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
