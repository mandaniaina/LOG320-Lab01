// Log320-Lab01.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	double b(15);
	std::ifstream file("dict.txt");
	std::string str;
	int nbr(0);
	while (std::getline(file, str))
	{
		nbr++;
		cout << "Mot numéro: " << nbr << " " << str << endl;
	}
	cin >> b;
	return 0;

}

