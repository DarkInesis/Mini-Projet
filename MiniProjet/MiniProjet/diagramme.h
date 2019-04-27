#pragma once
#include "categorie.h"
#include <list>
class Diagramme
{
	list<Categorie> listeCategorie;

public:
	Diagramme();
	void afficherDiagramme();
	void afficherTacheCategorie(string nomCategorie);
	void insererCategorie() { Categorie nouvCategorie; listeCategorie.push_back(nouvCategorie); } // Permet d'inserer une catégorie déja crée
	void supprimerCategorie();
	list<Categorie>::iterator getIteratorCategorie(string nomCategorie);
	void sauver(ofstream& ofs);
	void charger(ifstream& ifs);
};