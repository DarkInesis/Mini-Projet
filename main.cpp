#include <iostream>
#include <string>
#include <list>

#include "tache.h"
#include "categorie.h"
#include "menu.h"


int main()
{

	Temps t1(6, 4, 2019);
	Categorie C1;
	Temps dureeT1(6, 0, 0);
	Tache T1;
	Tache T2;
	C1.insererTache(T1, 0);
	C1.insererTache(T2, 1);
	C1.afficherListeTaches();
	cout<<"saisir la position de la tache a supprimer"<<endl;
	int positionsupprimer = -1;
	cin >> positionsupprimer;
	C1.supprimerTache(positionsupprimer);
	return 0;
}