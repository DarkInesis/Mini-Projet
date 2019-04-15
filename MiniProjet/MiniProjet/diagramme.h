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
	void insererCategorie() { Categorie nouvCategorie; listeCategorie.push_front(nouvCategorie); } // Permet d'inserer une catégorie déja crée
	void supprimerCategorie();
	list<Categorie>::iterator getIteratorCategorie(string nomCategorie);
};