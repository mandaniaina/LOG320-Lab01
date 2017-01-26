// Log320-Lab01.cpp : définit le point d'entrée pour l'application console.
//


#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <map>

using namespace std;

bool estAnagrammeProf(string chaine1, string chaine2)
{
	int i = 0;
	for each (char c in chaine1)
	{
		bool trouve = false;
		i = 0;
		while (trouve == false && i < chaine2.length())
		{
			if (chaine2[i] == 32)
			{
				chaine2.erase(chaine2.begin() + i);
			}
			if (c == chaine2[i])
			{
				chaine2.erase(chaine2.begin() + i);
				trouve = true;
			}
			i++;
		}
		if (trouve == false)
		{
			return false;
		}
	}
	if (!chaine2.empty())
	{
		return false;
	}
	return true;
}

void annagramesProf(vector<string> dictionnaire, vector<string> listeDeMot)
{
	int b(15);
	int total = 0;
	vector<string> resutlats;
	auto t1 = std::chrono::high_resolution_clock::now();

	for each(string mot in listeDeMot)
	{
		int i = 0;
		for each(string dict in dictionnaire)
		{
			if (estAnagrammeProf(mot, dict))
			{
				i++;
				total += 1;
			}

		}
		resutlats.push_back("Il y a " + to_string(i) + " anagrammes du mot " + mot);
	}

	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = t2 - t1;

	for (string mot : resutlats)
	{
		cout << "\n" << mot;
	}

	cout << "\n" <<"Il y a un total de " << total << " anagrammes";
	cout << "\n";
	cout << "Temps d'execution: " << fp_ms.count() / 1000 << " sec";
	resutlats.clear();
	listeDeMot.clear();
	dictionnaire.clear();

	cin >> b;
}

void annagrames(vector<string> dictionnaire, vector<string> listeDeMot)
{
	vector<string> resutlats;
	map<int, multimap<int, vector<int>>> TheMapV2;
	int nbAnnagrame(0);
	int nbAnagrammesTotal(0);
	

	auto t1 = std::chrono::high_resolution_clock::now();

	for (string s : dictionnaire)
	{
		vector<int> lettres(36);
		int pos(0);
		int sum(0);
		int nbChar(0);
		for (char& c : s) {
			if (48 <= c && c <= 57)//nombres
			{
				sum+= pos = c - 22;
				lettres[pos]++;
				nbChar++;
			}
			else if (97 <= c && c <= 122)//lettres
			{
				sum += pos = c - 97;
				lettres[pos]++;
				nbChar++;
			}
		}
		if (TheMapV2.find(sum) == TheMapV2.end()) {
			multimap<int, vector<int>> theMap;
			theMap.insert(make_pair(nbChar, lettres));
			TheMapV2.insert(make_pair(sum, theMap));
		}
		else {
			(TheMapV2.find(sum)->second).insert(make_pair(nbChar, lettres));//////////////////////////verifier

		}

	}
	
	for (string motDeLaListe : listeDeMot)
	{
		vector<int> mot(36);
		int pos(0);
		int nbChar(0);
		int sum(0);
		for (char& c : motDeLaListe) {
			if (48 <= c && c <= 57)//nombres
			{
				sum+=pos = c - 22;
				mot[pos]++;
				nbChar++;
			}
			else if (97 <= c && c <= 122)//lettres
			{
				sum+=pos = c - 97;
				mot[pos]++;
				nbChar++;
			}
		}
		nbAnnagrame = 0;

		multimap<int, vector<int>> theMap = TheMapV2.find(sum)->second;

		std::pair <std::multimap<int, vector<int>>::iterator, std::multimap<int, vector<int>>::iterator> ret;
		ret = theMap.equal_range(nbChar);

		for (std::multimap<int, vector<int>>::iterator it = ret.first; it != ret.second; ++it)
		{
			if (mot == it->second)
			{
				nbAnnagrame++;
			}
		}
		nbAnagrammesTotal += nbAnnagrame;
		resutlats.push_back("Il y a " + to_string(nbAnnagrame) + " anagrammes du mot " + motDeLaListe);
	}

	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
	
	for (string mot : resutlats)
	{
		cout << "\n" << mot;
	}
	cout << "\n" << "Il y a un total de " << nbAnagrammesTotal << " anagrammes";
	cout << "\n";
	cout << "Temps d'execution: " << fp_ms.count() / 1000 << " sec";
	TheMapV2.clear();
	resutlats.clear();
	listeDeMot.clear();
	dictionnaire.clear();
	int a(0);
	cin >> a;
}

int main()
{
	double b(1);
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

	cout << "1 - prof\n2 - notre\n";
	cin >> b;

	if (b == 1)
		annagramesProf(dictionnaire, listeDeMots);
	if (b == 2)
		annagrames(dictionnaire, listeDeMots);

	return 0;
}

