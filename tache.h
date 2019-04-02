#pragma once
#include <iostream>
#include <string>
#include <list>

#include "temps.h"

using namespace std;

class Tache {
	string nom_;
	Temps dateDebut_;
	Temps duree_;
	Tache* tacheSuivante_;
	bool Faisable;
	bool Fait;
	int numero_;
public:
	Tache(string nom, Temps dateDebut, Temps duree); //cr�ateur
	~Tache() { delete[] tacheSuivante_; } // destructeur
	void afficherTache();  // affiche la tache (nom/date debut/duree/num�ro)
	Temps getDuree() { return duree_; } 
	int getNumero() { return numero_; }
	void modifierNumero(int nouvNumero) { numero_ = nouvNumero; }
	void finTache() { (*tacheSuivante_).Faisable = true; Fait = true; } // lors de la fin de t�che, met � jour l'�tat fait et rend faisable la prochaine tache
};

