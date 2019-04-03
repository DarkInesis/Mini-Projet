#include "tache.h"
#include "temps.h"

Tache::Tache()
{
	cout << "Saisir nom" << endl;
	cin >> nom_;
	cout << "Saisir la date de début (appuyez sur entrée entre le jour, le mois et l'année" << endl;
	int jour, mois, annee;
	cin >> jour;
	dateDebut_.setJour(jour);
	cin >> mois;
	dateDebut_.setMois(mois);
	cin >> annee;
	dateDebut_.setAnnee(annee);
	cout << "Saisir la durée (en jour)" << endl;
	cin >> duree_;
	Faisable = false;
	Fait = false;
	numero_ = 1;
}

void Tache::afficherTache()    // Affiche le nom de la tache, sa date de début et sa durée (format JJ/MM/AA)
{
	cout << "Nom : " << nom_ << endl;
	cout << "Date debut : ";
	dateDebut_.afficherTemps();
	cout << "duree : " << duree_ << endl;
	cout << "Numero : " << numero_ << endl;
}