// Log320-Lab01.cpp�: d�finit le point d'entr�e pour l'application console.
//

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
	std::ifstream file("C://dict.txt");
	std::string str;
	int cpt(0);
	while (std::getline(file, str))
	{
	    std::cout << str;
		cpt++;
	}

	std::cin >> b;

	return 0;
}

