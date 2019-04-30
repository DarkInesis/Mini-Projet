#pragma once
#include <iostream>
#include <list>
#include <string>
#include "temps.h"
#include "tache.h"
#include <fstream>
#include "CImg.h"
using namespace cimg_library;
class Categorie  //Creation de la classe cat�gorie
{
	string nom_;
	int dureeTotale;
	Temps dateDebut;
	Temps dateFin_;
	list<Tache> listeTaches;  // est la liste des t�ches associ�es � une cat�gorie
	CImg<unsigned char> imageCategorie;
public:
	Categorie(bool estChargee=false);  // constructeur
	void modifierNom(string nom) {nom_ = nom; } //permet de modifier le nom de la categorie
	void afficherListeTaches(); //permet d'afficher les t�ches li�es � la cat�gorie
	void afficherCategorie(); //Affiche le nom, la dur�e, la date de debut de la cat�gorie
	void insererTache(); // Permet d'inserer une t�che d�ja cr�e dans la cat�gorie (met � jour la dur�e totale de la cat�gorie)
	void supprimerTache(); //Permet de supprimer une tache en s�lectionnant la cat�gorie
	string getNom() { return nom_; }; // Retourne le nom de la cat�gorie
	Temps getDebut() { return dateDebut; }
	Temps getFin() { return dateFin_; }
	~Categorie() { listeTaches.clear(); }
	void sauver(ofstream& ofs);
	void charger(ifstream& ifs);
	void changementDates();
	list<Tache> getListeTache() { return listeTaches; }

	void imgCategorie();
};