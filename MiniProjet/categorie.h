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
	string nom_;// Nom de la cat�gorie
	int dureeTotale; //Dur�e de la cat�gorie
	Temps dateDebut; //Date debut de la cat�gorie
	Temps dateFin_;//Date fin de la cat�gorie
	list<Tache> listeTaches;  // est la liste des t�ches associ�es � une cat�gorie
	CImg<unsigned char> imageCategorie; // est l'image de la cat�gorie qui sera affich� dans le calendrier
public:
	Categorie(bool estChargee=false);  // constructeur

	void modifierNom(string nom) {nom_ = nom; } //permet de modifier le nom de la categorie

	void afficherListeTaches(); //permet d'afficher les t�ches li�es � la cat�gorie
	void afficherCategorie(); //Affiche le nom, la dur�e, la date de debut de la cat�gorie

	void insererTache(); // Permet d'inserer une t�che d�ja cr�e dans la cat�gorie (met � jour la dur�e totale de la cat�gorie)
	void supprimerTache(); //Permet de supprimer une tache en s�lectionnant la cat�gorie
	void changementDates(); // Mets a jour la date de d�but et la date de fin da la cat�gorie	

	string getNom() { return nom_; }; // Retourne le nom de la cat�gorie
	int getDuree() { return dureeTotale; }// Retourne la dur�e de la cat�gorie
	Temps getDebut() { return dateDebut; }// Retourne la date de d�but de la cat�gorie
	Temps getFin() { return dateFin_; }// Retourne la date de fin de la cat�gorie
	list<Tache> getListeTache() { return listeTaches; }// Retourne la liste de tache associ�e � la cat�gorie
	
	void sauver(ofstream& ofs);	// Sauvegarde la cat�gorie
	void charger(ifstream& ifs);// Charge la cat�gorie
	
	
	~Categorie() { listeTaches.clear(); } // Destructeur

	void imgCategorie(int echelleX = 0, int echelleY = 0);//Cree l'image associ�e � la cat�gorie qui sera affich�e dans le calendrier
};