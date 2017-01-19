// Log320-Lab01.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void annagramesProf(vector<string> dictionnaire, vector<string> listeDeMot)
{
	
}


void annagrames(vector<string> dictionnaire, vector<string> listeDeMot)
{
	vector<string> resutlats;
	int nbAnnagrame(0);
	int nbAnagrammesTotal(0);
	string avantSort;
	for (string mot : listeDeMot)
	{
		nbAnnagrame = 0;
		for (string motduDict : dictionnaire)
		{
		}
		resutlats.push_back("Il y a " + to_string(nbAnnagrame) + " anagrammes du mot " + mot);
	}
	for (string mot : resutlats)
	{
		cout << "\n" << mot;
	}
	resutlats.clear();
	listeDeMot.clear();
	dictionnaire.clear();
	int a(0);
	cin >> a;
}
void annagramesBase(vector<string> dictionnaire, vector<string> listeDeMot)
{
	vector<string> resutlats;
	int nbAnnagrame(0);
	string avantSort;
	for (string mot : listeDeMot)
	{
		nbAnnagrame = 0;
		for (string motduDict : dictionnaire)
		{
			avantSort = mot;
			mot.erase(remove_if(mot.begin(), mot.end(), isspace));
			motduDict.erase(remove_if(motduDict.begin(), motduDict.end(), isspace));
			std::sort(mot.begin(), mot.end());
			std::sort(motduDict.begin(), motduDict.end());
			if(mot == motduDict)
				nbAnnagrame++;
		}
		resutlats.push_back(avantSort + " - " + to_string(nbAnnagrame));
	}
	for (string mot : resutlats)
	{
		cout << "\n" << mot;
	}
	resutlats.clear();
	listeDeMot.clear();
	dictionnaire.clear();
	int a(0);
	cin >> a;
}

void test(vector<string> dictionnaire, vector<string> listeDeMot)
{
	cout << "\n \n \n" << "dictionnaire";
	for (string mot : dictionnaire)
	{
		cout << "\n" << mot;
	}
	cout << "\n \n \n" << "mots";
	for (string mot : listeDeMot)
	{
		cout << "\n" << mot;
	}
	int a(0);
	cin >> a;
}

int main()
{
	double b(0);
	ifstream dict("dict.txt");
	ifstream mots("words.txt");

	string str;
	vector<string> dictionnaire;
	vector<string> listeDeMots;

	while (getline(dict, str))
	{
		dictionnaire.push_back(str);
	}
	while (getline(mots, str))
	{
		listeDeMots.push_back(str);
	}

	cout << "1 - prof\n2- notre\n3- base\n";
	cin >> b;

	if (b == 1)
		annagramesProf(dictionnaire, listeDeMots);
	if (b == 2)
		annagrames(dictionnaire, listeDeMots);
	if (b == 3)
		annagramesBase(dictionnaire, listeDeMots);
	return 0;
}

