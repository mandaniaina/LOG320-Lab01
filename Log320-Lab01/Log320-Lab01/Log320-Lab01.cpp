// Log320-Lab01.cpp�: d�finit le point d'entr�e pour l'application console.
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

