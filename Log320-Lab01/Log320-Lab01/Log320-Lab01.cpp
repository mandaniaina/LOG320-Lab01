// Log320-Lab01.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double a(0), b(0); //D�claration des variables utiles

	cout << "Bienvenue dans le programme de calcul de a^b !" << endl;

	cout << "Donnez une valeur pour a : "; //On demande le premier nombre
	cin >> a;

	cout << "Donnez une valeur pour b : "; //On demande le deuxi�me nombre
	cin >> b;

	double const resultat(pow(a, b)); //On effectue l'op�ration
									  //On peut aussi �crire comme avant :
									  //double const resultat = pow(a,b);
									  //Souvenez-vous des deux formes possibles
									  //De l'initialisation d'une variable

	cout << a << " ^ " << b << " = " << resultat << endl;
	//On affiche le r�sultat
	cin >> b;
	return 0;

}

