/*
 * Translator.h
 *
 *  Created on: 6 Apr 2013
 *      Author: James Coll
 */

#ifndef TRANSLATOR_H_
#define TRANSLATOR_H_
#include <iostream>
#include <cstdlib>
#include <map>
#include <string>

using namespace std;

class Translator {
public:
	Translator(const char filename[]);
	void LoadDictionary(const char filename[]);
	void toElvish(char translatedLine[], const char lineToTranslate[]);
	void toEnglish(char translatedLine[], const char lineToTranslate[]);
	map<string, string> engtoelfdictionary;
	map<string, string> elftoengdictionary;
};




#endif /* TRANSLATOR_H_ */


