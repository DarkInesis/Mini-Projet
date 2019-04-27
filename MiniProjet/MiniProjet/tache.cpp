#include "tache.h"

Tache::Tache()
{
	cout << "Saisir nom de la tache" << endl;
	cin >> nom_;
	cout << "Saisir la date de debut (appuyez sur entree entre le jour, le mois et l'annee" << endl;
	int jour, mois, annee;
	cin >> jour;
	dateDebut_.setJour(jour);
	cin >> mois;
	dateDebut_.setMois(mois);
	cin >> annee;
	dateDebut_.setAnnee(annee);
	cout << "Saisir la duree (en jour)" << endl;
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

void Tache::sauver(ofstream& ofs)
{
	if (!ofs.is_open()) cout << "erreur ouverture" << endl;
	else
	{
		ofs << nom_ << endl;
		ofs << duree_ << endl;
		ofs << Faisable << endl;
		ofs << Fait << endl;
		ofs << numero_ << endl;
		dateDebut_.sauver(ofs);
		
	}
}
void Tache::charger(ifstream& ifs)
{
	if (!ifs.is_open()) cout << "erreur ouverture" << endl;
	else
	{
		ifs >> nom_;
		ifs >> duree_;
		ifs >> Faisable;
		ifs >> Fait;
		ifs >> numero_;
		dateDebut_.charger(ifs);
	}
}