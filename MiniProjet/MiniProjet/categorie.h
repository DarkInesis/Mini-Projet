#pragma once
#include <iostream>
#include <list>
#include <string>
#include "temps.h"
#include "tache.h"
#include <fstream>
#include "CImg.h"
using namespace cimg_library;
class Categorie  //Creation de la classe catégorie
{
	string nom_;
	int dureeTotale;
	Temps dateDebut;
	Temps dateFin_;
	list<Tache> listeTaches;  // est la liste des tâches associées à une catégorie
	CImg<unsigned char> imageCategorie;
public:
	Categorie(bool estChargee=false);  // constructeur
	void modifierNom(string nom) {nom_ = nom; } //permet de modifier le nom de la categorie
	void afficherListeTaches(); //permet d'afficher les tâches liées à la catégorie
	void afficherCategorie(); //Affiche le nom, la durée, la date de debut de la catégorie
	void insererTache(); // Permet d'inserer une tâche déja crée dans la catégorie (met à jour la durée totale de la catégorie)
	void supprimerTache(); //Permet de supprimer une tache en sélectionnant la catégorie
	string getNom() { return nom_; }; // Retourne le nom de la catégorie
	Temps getDebut() { return dateDebut; }
	Temps getFin() { return dateFin_; }
	~Categorie() { listeTaches.clear(); }
	void sauver(ofstream& ofs);
	void charger(ifstream& ifs);
	void changementDates();
	list<Tache> getListeTache() { return listeTaches; }

	void imgCategorie();
};