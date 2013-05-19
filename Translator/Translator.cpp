/*
 * Translator.cpp
 *
 *  Created on: 6 Apr 2013
 *      Author: James Coll
 */

#include "Translator.h"
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <string.h>



using namespace std;


Translator::Translator(const char filename[]) 
{
	
	// we don't want to do file io in the constructor
	this->LoadDictionary(filename);
      		
}

void Translator::LoadDictionary(const char filename[])
{

	//open the dictionary file
	fstream infile;
    	infile.open(filename, ios::in);
	
	   
	if (infile.fail())
    {
		cerr<<"Problem opening dictionary file";
		return;
    }
	
	string line, english, elfish;
	
	//go through the file line by line dealing with the problematic tabs and whitespaces
	//we're going to use two maps to store the dictionary
	//this turns out to be more efficient than using one map and a reverse find
	while(infile.good())
	{
		
		getline(infile, line);

		if(!line.empty())
		{
			//this gets me all the English words by hunting for whitespace and tabs		
			unsigned found = line.find_first_of(" \t");
			english = line.substr(0, found);
			//we'll dump what's left in elfish and then remove the whitespaces and tabs from it
			elfish = line.substr(found, string::npos);
			elfish.erase(remove(elfish.begin(), elfish.end(), '\t'), elfish.end());
			elfish.erase(remove(elfish.begin(), elfish.end(), ' '), elfish.end());
			//now place these into a map
			engtoelfdictionary.insert(std::pair<string, string>(english, elfish));
			elftoengdictionary.insert(std::pair<string, string>(elfish, english));
			//now create capital pairs
			english[0] = toupper(english[0]);
			elfish[0] = toupper(elfish[0]);
			//populate the map with capitalized pairs - this saves on work later
			engtoelfdictionary.insert(std::pair<string, string>(english, elfish));
			elftoengdictionary.insert(std::pair<string, string>(elfish, english));
		}
	}

	
	
	return;

}


	
	



void Translator::toElvish(char translatedLine[], const char lineToTranslate[])
{
	string inputLine(lineToTranslate);
	
	string tmp, trans;
	
	
	
		for(int i = 0; i<inputLine.size()+1; i++)
		{	
				if(isalpha(inputLine[i])||inputLine[i]=='-')
				{
					tmp += inputLine[i];
					
				}
				else
				{
				
					//probably need to check if this is empty or not
					if(!tmp.empty())
					{
									
						if(engtoelfdictionary.count(tmp)==1)
						{	
											
							trans += engtoelfdictionary[tmp];
							
						}//this is our special case words 'already translated'
						else
						{
							tmp.insert(tmp.begin(), '*');
							tmp.insert(tmp.end(), '*');
							trans += tmp;
							
						}
					}
					trans += inputLine[i];
					tmp.clear();
				}
			
		}
	


	//this translates our string back into a character array
	char *ch=new char[trans.size()+1];
	ch[trans.size()]=0;
	memcpy(ch,trans.c_str(),trans.size());
	strcpy(translatedLine, ch);

		
}

void Translator::toEnglish(char translatedLine[], const char lineToTranslate[])
{
	string inputLine(lineToTranslate);
	
	string tmp, trans;

	bool bTranslate = true;
	
	for(int i = 0; i<inputLine.size()+1; i++)
		{
			if(inputLine[i]=='*')
			{
				//we can flip this each time a first star is encountered
				//this saves on a look-up
				bTranslate = !bTranslate;
				
			}			
			else if(isalpha(inputLine[i])||inputLine[i]=='-')
			{
				tmp += inputLine[i];
				
			}
			else
			{
				
				//check if this is empty or not
				//we need to look up all of the words which have two meanings
				if(!tmp.empty())
				{
					if(elftoengdictionary.count(tmp)==1&&bTranslate)
					{					
						trans += elftoengdictionary[tmp];
					}
					else
					{
						trans += tmp;
					}
				}
				trans += inputLine[i];
				tmp.clear();
			}
			
		}

	//this translates our string back into a character array
	char *ch=new char[trans.size()+1];
	ch[trans.size()]=0;
	memcpy(ch,trans.c_str(),trans.size());
	strcpy(translatedLine, ch);	
}



