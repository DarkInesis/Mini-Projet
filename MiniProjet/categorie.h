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
	string nom_;// Nom de la catégorie
	int dureeTotale; //Durée de la catégorie
	Temps dateDebut; //Date debut de la catégorie
	Temps dateFin_;//Date fin de la catégorie
	list<Tache> listeTaches;  // est la liste des tâches associées à une catégorie
	CImg<unsigned char> imageCategorie; // est l'image de la catégorie qui sera affiché dans le calendrier
public:
	Categorie(bool estChargee=false);  // constructeur

	void modifierNom(string nom) {nom_ = nom; } //permet de modifier le nom de la categorie

	void afficherListeTaches(); //permet d'afficher les tâches liées à la catégorie
	void afficherCategorie(); //Affiche le nom, la durée, la date de debut de la catégorie

	void insererTache(); // Permet d'inserer une tâche déja crée dans la catégorie (met à jour la durée totale de la catégorie)
	void supprimerTache(); //Permet de supprimer une tache en sélectionnant la catégorie
	void changementDates(); // Mets a jour la date de début et la date de fin da la catégorie	

	string getNom() { return nom_; }; // Retourne le nom de la catégorie
	int getDuree() { return dureeTotale; }// Retourne la durée de la catégorie
	Temps getDebut() { return dateDebut; }// Retourne la date de début de la catégorie
	Temps getFin() { return dateFin_; }// Retourne la date de fin de la catégorie
	list<Tache> getListeTache() { return listeTaches; }// Retourne la liste de tache associée à la catégorie
	
	void sauver(ofstream& ofs);	// Sauvegarde la catégorie
	void charger(ifstream& ifs);// Charge la catégorie
	
	
	~Categorie() { listeTaches.clear(); } // Destructeur

	void imgCategorie(int echelleX = 0, int echelleY = 0);//Cree l'image associée à la catégorie qui sera affichée dans le calendrier
};