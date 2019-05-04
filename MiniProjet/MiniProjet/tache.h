#pragma once
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "temps.h"
#include "CImg.h"
using namespace cimg_library;
using namespace std;

class Tache {
	string nom_; //Nom de la tache
	Temps dateDebut_; // Date de début de la tache
	Temps dateFin_; // Date de fin de la tache 
	int duree_; // Durée de la tache
	int numero_;	// Position de la tache par rapport à la catégorie
	CImg<unsigned char> imageTache; // Image associée à la tache qui sera affichée dans calendrier
public:
	Tache(bool estChargee=false); //constructeur

	void afficherTache();  // affiche la tache (nom/date debut/duree/numéro)
	void setNom(string nom) { nom_ = nom; } // Permet de modifier le nom
	void setDuree(int duree) { duree_ = duree; }// Permet de modifier la duree
	void setDateDebut(Temps dateDebut) { dateDebut_ = dateDebut; } // Permet de modifier la date de debut
	void modifierNumero(int nouvNumero) { numero_ = nouvNumero; }// Permet de modifier le numero

	int getDuree() { return duree_; } // Permet de connaitre la duree
	int getNumero() { return numero_; }// Permet de connaitre le numero de la tache
	Temps getDebut() { return dateDebut_; } // Permet de connaitre la date de debut
	Temps getFin() { return dateFin_; } // Permet de connaitre la date de fin
	string getNom() { return nom_; } // Permet de connaitre le nom

	Temps calculDateFin() { return dateDebut_.dateFin(duree_); } //Retourne la date de fin de la tache en fonction de sa durée
	void sauver(ofstream& ofs); // Permet d'enregistrer la tache
	void charger(ifstream& ifs); // Permet de charger la tache
	

	void menumodifTache();  // Permet de modifier la tache en général

	void imgTache(int echelleX=0, int echelleY=0); //Cree l'image associée à la tache qui sera affichée dans le calendrier
	
};

