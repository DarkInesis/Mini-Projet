#pragma once
#include <iostream>
#include <list>
#include <string>
#include "temps.h"
#include "tache.h"

class Categorie  //Creation de la classe catégorie
{
	string nom_;
	int dureeTotale;
	Temps dateDebut;
	list<Tache> listeTaches;  // est la liste des tâches associées à une catégorie
public:
	Categorie();  // constructeur
	void modifierNom(string nom); //permet de modifier le nom de la categorie
	void afficherListeTaches(); //permet d'afficher les tâches liées à la catégorie
	void afficherCategorie(); //Affiche le nom, la durée, la date de debut de la catégorie
	void calculDuree(); // Permet de mettre à jour la durée total des taches de la catégorie
	void insererTache(); // Permet d'inserer une tâche déja crée dans la catégorie (met à jour la durée totale de la catégorie)
	void supprimerTache();
	string getNom() { return nom_; };
	~Categorie() { listeTaches.clear(); }
};