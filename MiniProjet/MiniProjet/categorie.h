#pragma once
#include <iostream>
#include <list>
#include <string>
#include "temps.h"
#include "tache.h"

class Categorie  //Creation de la classe cat�gorie
{
	string nom_;
	int dureeTotale;
	Temps dateDebut;
	list<Tache> listeTaches;  // est la liste des t�ches associ�es � une cat�gorie
public:
	Categorie();  // constructeur
	void modifierNom(string nom); //permet de modifier le nom de la categorie
	void afficherListeTaches(); //permet d'afficher les t�ches li�es � la cat�gorie
	void afficherCategorie(); //Affiche le nom, la dur�e, la date de debut de la cat�gorie
	void calculDuree(); // Permet de mettre � jour la dur�e total des taches de la cat�gorie
	void insererTache(); // Permet d'inserer une t�che d�ja cr�e dans la cat�gorie (met � jour la dur�e totale de la cat�gorie)
	void supprimerTache();
	string getNom() { return nom_; };
	~Categorie() { listeTaches.clear(); }
};