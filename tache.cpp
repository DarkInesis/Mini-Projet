#include "tache.h"
#include "temps.h"

Tache::Tache(string nom, Temps dateDebut, Temps duree)
{

	nom_ = nom;
	dateDebut_=dateDebut;
	duree_=duree;
	Faisable = false;
	Fait = false;
	numero_ = 1;
}

void Tache::afficherTache()    // Affiche le nom de la tache, sa date de début et sa durée (format JJ/MM/AA)
{
	cout << "Nom : " << nom_ << endl;
	cout << "Date debut : ";
	dateDebut_.afficherTemps();
	cout << "duree : ";
	duree_.afficherTemps();
	cout << "Numero : " << numero_ << endl;
}