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
	string nom_;
	Temps dateDebut_;
	Temps dateFin_;
	int duree_;
	Tache* tacheSuivante_;
	bool Faisable;
	bool Fait;
	int numero_;
	CImg<unsigned char> imageTache;
public:
	Tache(bool estChargee=false); //constructeur
	~Tache() { delete[] tacheSuivante_; } // destructeur
	void afficherTache();  // affiche la tache (nom/date debut/duree/numéro)
	void setNom(string nom) { nom_ = nom; }
	void setDuree(int duree) { duree_ = duree; }
	void setDateDebut(Temps dateDebut) { dateDebut_ = dateDebut; }
	int getDuree() { return duree_; } 
	int getNumero() { return numero_; }
	void modifierNumero(int nouvNumero) { numero_ = nouvNumero; }
	Temps calculDateFin() { return dateDebut_.dateFin(duree_); }
	void sauver(ofstream& ofs);
	void charger(ifstream& ifs);
	Temps getDebut() { return dateDebut_; }
	Temps getFin() { return dateFin_; }
	string getNom() { return nom_; }

	void menumodifTache();

	void imgTache();
	
};

