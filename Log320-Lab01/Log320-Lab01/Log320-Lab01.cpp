// Log320-Lab01.cpp�: d�finit le point d'entr�e pour l'application console.
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
	auto t1 = chrono::high_resolution_clock::now();

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

	auto t2 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> fp_ms = t2 - t1;

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
	map<vector<int>, int> TheMapV4;
	int nbAnnagrame(0);
	int nbAnagrammesTotal(0);
	

	auto t1 = chrono::high_resolution_clock::now();

	for(string s : dictionnaire)
	{
		vector<int> lettres(36);
		int pos;
		for (char& c : s) {
			if (48 <= c && c <= 57)//nombres
			{
				pos = c - 22;
				lettres[pos]++;
			}
			else if (97 <= c && c <= 122)//lettres
			{
				pos = c - 97;
				lettres[pos]++;
			}
		}
		map<vector<int>, int>::iterator it = TheMapV4.find(lettres);
		if (it != TheMapV4.end())
			it->second++;
		else
			TheMapV4.insert(make_pair(lettres, 1));

	}
	
	for (string motDeLaListe: listeDeMot)
	{
		vector<int> mot(36);
		int pos(0);
		for (char& c : motDeLaListe) {
			if (48 <= c && c <= 57)//nombres
			{
				pos = c - 22;
				mot[pos]++;
			}
			else if (97 <= c && c <= 122)//lettres
			{
				pos = c - 97;
				mot[pos]++;
			}
		}

		nbAnagrammesTotal += nbAnnagrame = TheMapV4.find(mot)->second;

		resutlats.push_back("Il y a " + to_string(nbAnnagrame) + " anagrammes du mot " + motDeLaListe);
	}

	auto t2 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> fp_ms = t2 - t1;
	
	for(string mot: resutlats)
	{
		cout << "\n" << mot;
	}
	cout << "\n" << "Il y a un total de " << nbAnagrammesTotal << " anagrammes";
	cout << "\n";
	cout << "Temps d'execution: " << fp_ms.count() / 1000 << " sec";
	TheMapV4.clear();
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

