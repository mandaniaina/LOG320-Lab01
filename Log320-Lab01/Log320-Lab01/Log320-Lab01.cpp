// Log320-Lab01.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void annagramesProf(vector<string> dictionnaire, vector<string> listeDeMot)
{
	
}
void annagrames(vector<string> dictionnaire, vector<string> listeDeMot)
{
	cout << "\n \n \n" << "dictionnaire";
	for(string mot: dictionnaire)
	{
		cout << "\n" << mot;
	}
	cout << "\n \n \n"<< "mots";
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

	cout << "1 - prof\n2- notre";
	cin >> b;

	if (b == 1)
		annagramesProf(dictionnaire, listeDeMots);
	if (b == 2)
		annagrames(dictionnaire, listeDeMots);
	return 0;
}

