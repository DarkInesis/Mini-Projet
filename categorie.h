#pragma once
#include <iostream>
#include <list>
#include <string>
#include "temps.h"
#include "tache.h"

class Categorie  //Creation de la classe cat�gorie
{
	string nom_;
	Temps dureeTotale;
	Temps dateDebut;
	list<Tache> listeTaches;  // est la liste des t�ches associ�es � une cat�gorie
public:
	Categorie(string nom, Temps debut);  // createur
	void modifierNom(string nom); //permet de modifier le nom de la categorie
	void afficherListeTaches(); //permet d'afficher les t�ches li�es � la cat�gorie
	void calculDuree(); // Permet de mettre � jour la dur�e total des taches de la cat�gorie
	void insererTache(Tache nouvTache, unsigned int numero); // Permet d'inserer une t�che d�ja cr�e dans la cat�gorie (met � jour la dur�e totale de la cat�gorie)
};