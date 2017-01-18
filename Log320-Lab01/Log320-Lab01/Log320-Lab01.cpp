// Log320-Lab01.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void annagramesProf(string dictionnaire[], string listeDeMot[])
{
	
}

int main()
{
	double b(15);
	ifstream file("dict.txt");
	string str;
	int cpt(0);
	string dictionnaire[10000];
	while (getline(file, str))
	{
		//cout << str;
		dictionnaire[cpt++] = str;
	}
	for (string mot : dictionnaire)
	{
		cout << mot;
	}
	cin >> b;
	delete cpt;
	return 0;
}

