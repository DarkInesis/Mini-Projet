#pragma once
#include<iostream>
#include <fstream>
using namespace std;
class Temps{
	int jour_;
	int mois_;
	int annee_;
public:
	Temps();
	Temps(int jour, int mois, int annee);
	void operator=(const Temps &t);
	void setJour(int jour) { jour_ = jour; }
	void setMois(int mois) { mois_ = mois; }
	void setAnnee(int annee) {annee_ = annee; }
	void afficherTemps();
	Temps dateFin(int duree, int jourParMois[13]); // Permet de calculer la date de fin
	void sauver(ofstream& ofs) { ofs << jour_ << endl; ofs << mois_ << endl; ofs << annee_ << endl; }
	void charger(ifstream& ifs) { ifs >> jour_; ifs >> mois_; ifs >> annee_; }
};

