// Log320-Lab01.cpp : définit le point d'entrée pour l'application console.
//


#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>

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
	auto t1 = std::chrono::high_resolution_clock::now();

	for each(string mot in listeDeMot)
	{
		int i = 0;
		for each(string dict in dictionnaire)
		{
			if (estAnagrammeProf(mot, dict))
			{
				i++;
			}

		}
		cout << "Il y a " << i << " anagrammes du mot " << mot;
		cout << "\n";
		total += i;

	}

	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = t2 - t1;

	cout << "Il y a un total de " << total << " anagrammes";
	cout << "\n";
	cout << "Temps d'execution: " << fp_ms.count() / 1000 << " sec";
	listeDeMot.clear();
	dictionnaire.clear();

	cin >> b;
}

bool estAnagramme(string s1, string s2)
{
	vector<int> lettres(36);
	int pos(0);
	for (char& c : s1) {
		if (48 <= c && c <= 57)//nombres
		{
			pos = c - 22;
			lettres[pos] = lettres[pos] + 1;
		}
		else if (97 <= c && c <= 122)//lettres
		{
			pos = c - 97;
			lettres[pos] = lettres[pos] + 1;
		}
		else if (c != 32)
			cout << "ERREUR caractere non supporte " << c << " no: " << static_cast<int>(c) << "dans le mot" << s1 << "du dictionnaire\n";
	}
	for (char& c : s2) {

		if (48 <= c && c <= 57)//nombres
		{
			pos = c - 22;
			if (lettres[pos] == 0)
				return false;
			lettres[pos] = lettres[pos] - 1;
		}
		else if (97 <= c && c <= 122)//lettres
		{
			pos = c - 97;
			if (lettres[pos] == 0)
				return false;
			lettres[pos] = lettres[pos] - 1;
		}
		else if (c != 32)
			cout << "ERREUR caractere non supporte " << c << " no: " << static_cast<int>(c) << "dans le mot" << s2 << "de la banque de mot\n";
	}
	for (int i : lettres)
	{
		if (i != 0)
			return false;
	}
	return true;
}

void annagrames(vector<string> dictionnaire, vector<string> listeDeMot)
{
	vector<string> resutlats;
	int nbAnnagrame(0);
	int nbAnagrammesTotal(0);
	auto t1 = std::chrono::high_resolution_clock::now();

	for (string mot : listeDeMot)
	{
		nbAnnagrame = 0;
		for (string motduDict : dictionnaire)
		{
			if (estAnagramme(mot, motduDict))
			{
				nbAnnagrame++;
				nbAnagrammesTotal++;
			}
		}
		resutlats.push_back("Il y a " + to_string(nbAnnagrame) + " anagrammes du mot " + mot);
	}

	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
	for (string mot : resutlats)
	{
		cout << "\n" << mot;
	}
	cout << "\n" << "Il y a un total de " << nbAnagrammesTotal << " anagrammes\n" << "Temps d'execution: " << fp_ms.count() / 1000 << " secondes";
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

