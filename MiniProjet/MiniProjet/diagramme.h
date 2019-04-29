#pragma once
#include "categorie.h"
#include <list>
class Diagramme
{
	list<Categorie> listeCategorie;
	Temps dateDebut;
	Temps dateFin;
	int duree=0;
	int echelle=0;
	int nombreElements=0;

	CImg<unsigned char> imgDiagramme;

	CImg<unsigned char> imgMenu;
	int positionMenu[2] = { 0,0 };
	CImg <unsigned char> imgFrise;
	int positionFrise[2] = { imgMenu.height(), 0 };
	CImg<unsigned char> imgCalendrier;
	int positionCalendrier[2] = { positionFrise[0], imgFrise.height() };


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

	int getNbElement() { return nombreElements; }
	void setNbElement(int nbElements) { nombreElements = nbElements; }

	void calculDuree() { duree = dateDebut - dateFin; };


	void refreshFrise();
	void refreshMenu();
	
};

