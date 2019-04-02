#include <iostream>
#include <string>
#include <list>

#include "tache.h"
#include "categorie.h"

int main()
{
	Temps t1(6, 4, 2019);
	Categorie C1("test", t1);
	Temps dureeT1(6, 0, 0);
	Tache T1("Amine la tache", t1, dureeT1);
	C1.insererTache(T1, 0);
	C1.afficherListeTaches();
	return 0;
}