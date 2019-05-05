#include "tache.h"

Tache::Tache(bool estChargee)
{
	if (!estChargee)
	{
		cout << "Saisir nom de la tache" << endl;
		// Vide le tampon du clavier.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, nom_);
		cout << "Saisir la date de debut (appuyez sur entree entre le jour, le mois et l'annee)" << endl;
		int jour, mois, annee;
		jour = saisieEntier();
		mois = saisieEntier();
		annee=saisieEntier();
		Temps tempsTemp(jour, mois, annee);
		dateDebut_ = tempsTemp;
		cout << "Saisir la duree (en jour)" << endl;
		duree_ = saisieEntier();
		numero_ = 1;
		dateFin_ = calculDateFin();
	}
	else
	{
		nom_ = "";
		dateDebut_.setAnnee(0);
		dateDebut_.setMois(0);
		dateDebut_.setJour(0);
		duree_ = 0;

		numero_ = 0;
		dateFin_ = dateDebut_.dateFin(duree_);
	}
	imgTache();
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
		ofs << numero_ << endl;
		dateDebut_.sauver(ofs);
		dateFin_.sauver(ofs);
	}
}
void Tache::charger(ifstream& ifs)
{
	if (!ifs.is_open()) cout << "erreur ouverture" << endl;
	else
	{	
		// Vide le tampon du clavier.
		ifs.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(ifs, nom_);
		ifs >> duree_;

		ifs >> numero_;
		dateDebut_.charger(ifs);
		dateFin_.charger(ifs);
	}
}

void Tache::menumodifTache()
{
	cout << "Que voulez vous modifier ? " << endl;
	cout << "1) Nom" << endl;
	cout << "2) Date debut" << endl;
	cout << "3) Duree" << endl;
	int choix;
	cin >> choix;
	switch (choix)
	{
	case 1:
		if (true)
		{
			
			cin >> nom_;
		}
		break;
	case 2:
		if (true)
		{
			cout << "Entrer la date (Jour puis mois puis annee)" << endl;
			int jour, mois, annee;
			cin >> jour >> mois >> annee;
			dateDebut_.setAnnee(annee);
			dateDebut_.setMois(mois);
			dateDebut_.setJour(jour);
			dateFin_ = calculDateFin();
		}
		break;
	case 3:
		if (true)
		{
			cin >> duree_;
		}
		break;
	default:
		break;
	}

}

void Tache::imgTache(int echelleX,int echelleY) {
	const unsigned char black[] = { 0,0,0 }, blue[] = { 0,0,255 };
	string temp = nom_;
	char* tab = new char[temp.length() + 1];
	strcpy_s(tab, temp.length() + 1, temp.c_str());
	imageTache.resize(duree_*echelleX, echelleY);
	imageTache.draw_rectangle(0, 0, imageTache.width(), imageTache.height(), blue);
	imageTache.draw_text(20, 20, tab, black);
}