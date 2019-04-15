#pragma once
#include<iostream>
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
};