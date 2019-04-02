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
	void operator+(const Temps &t);
	void afficherTemps();
};