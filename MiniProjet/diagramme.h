#pragma once
#include "categorie.h"
#include <list>
class Diagramme
{
	list<Categorie> listeCategorie;
	Temps dateDebut;
	Temps dateFin;
	int duree;
	CImg <unsigned char> frise;

public:
	Diagramme();
	void changementDates();
	void afficherDiagramme();
	void afficherTacheCategorie(string nomCategorie);
	void insererCategorie() { Categorie nouvCategorie; listeCategorie.push_back(nouvCategorie); } // Permet d'inserer une catégorie déja crée
	void supprimerCategorie();
	void insererTacheCategorie(string nomCategorie);
	void supprimerTacheCategorie(string nomCategorie);
	void sauver(ofstream& ofs);
	void charger(ifstream& ifs);
	void modifierTache();


	void calculDuree() { duree=dateDebut - dateFin; }
};

