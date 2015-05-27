/* 
 * corrector.h
 * 
 * Author: Juan Huete
 * 
 * Version modificada del original de Felipe Farinon <felipe.farinon@gmail.com>
 * 
 */
#ifndef __CORRECTOR
#define __CORRECTOR

#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include "diccionario.h"

using namespace std;


char filterNonAlphabetic(char& letter) {
	if (isalpha(letter)) { return tolower(letter); }
	return '-';
}

class corrector
{
	
	diccionario  dictionary;

	/** @brief Genera todas las posibles modificaciones tras una "edicion" de la cadena word
	@param[in] word cadena de entrada
	@param[out] result vector con las posibles palabras que se obtienen al realizar borrados, transposiciones, alteraciones o inserciones en la cadena word.
	*/
	void edits(const std::string& word, std::vector<std::string>& result) {
		for (string::size_type i = 0;i < word.size();    i++) 
		  result.push_back(word.substr(0, i) + word.substr(i + 1)); //deletions
		for (string::size_type i = 0;i < word.size() - 1;i++) 
		   result.push_back(word.substr(0, i) + word[i+1] + word[i]+ word.substr(i + 2)); //transposition

		for (char j = 'a';j <= 'z';++j) {
			for (string::size_type i = 0;i < word.size();    i++) 
			  result.push_back(word.substr(0, i) + j + word.substr(i + 1)); //alterations
			for (string::size_type i = 0;i < word.size() + 1;i++) 
			  result.push_back(word.substr(0, i) + j + word.substr(i)     ); //insertion
		}	
	}
/** @brief busca ocurrencias en un diccionario
	@param[in]  results conjunto de palabras a buscar
	@param[in,out] candidates conjunto de palabras en results cuyas entradas tambien se encuentra en el diccionario
	*/
	void known(std::vector<std::string>& results, diccionario & candidates) {
		diccionario::entrada nula = dictionary.null();
		for (unsigned int i = 0;i < results.size();i++) {
			diccionario::entrada value = dictionary.find(results[i]);
		
			if (value != nula) candidates[value.first] = value.second;
		}
	}
public:
	/** @brief lectura del fichero de entrenamiento
	@param[in] filename nombre del fichero a leer
*/
	void load(const std::string& filename) {
		ifstream file(filename.c_str(), ios_base::binary | ios_base::in);

		file.seekg(0, ios_base::end);
		int length = file.tellg();
		file.seekg(0, ios_base::beg);
  
		string line(length, '0');

		file.read(&line[0], length);

		transform(line.begin(), line.end(), line.begin(), filterNonAlphabetic);

		string::size_type end = line.size();

		for (string::size_type i = 0;;) {
			while (line[++i] == '-' && i < end); //find first '-' character

			if (i >= end) { break; }

			string::size_type begin = i;
			while (line[++i] != '-' && i < end); //find first not of '-' character

			dictionary[line.substr(begin, i - begin)]++;
		}


	}
/** @brief  determina la palabra corregida
	@param[in] word palabra origen
	@return palabra que se sugiere como correccion.
*/
	std::string correct(const std::string& word) {
		std::vector<std::string> result;
		diccionario candidates;

		if (dictionary.find(word) != dictionary.null()) { return word; }

		edits(word, result); // distancia de edicion 1
		known(result, candidates);
  
		if (candidates.size() > 0) { 
			return candidates.max_element();		
		}
		for (unsigned int i=0; i < result.size();i++) {
			std::vector<std::string> subResult;
	
			edits(result[i], subResult); // distancia de edicion 2
			known(subResult, candidates);
			
		}
		
		if (candidates.size() > 0) { 
			return candidates.max_element();		
		}
		return "";
	}
};
#endif
