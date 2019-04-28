#pragma once
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "temps.h"

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
public:
	Tache(bool estChargee=false); //constructeur
	~Tache() { delete[] tacheSuivante_; } // destructeur
	void afficherTache();  // affiche la tache (nom/date debut/duree/numéro)
	int getDuree() { return duree_; } 
	int getNumero() { return numero_; }
	void modifierNumero(int nouvNumero) { numero_ = nouvNumero; }
	void finTache() { (*tacheSuivante_).Faisable = true; Fait = true; } // lors de la fin de tâche, met à jour l'état fait et rend faisable la prochaine tache
	void sauver(ofstream& ofs);
	void charger(ifstream& ifs);
};

