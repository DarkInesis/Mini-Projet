#include "tache.h"
#include "categorie.h"
#include "temps.h"
using namespace cimg_library;
using namespace std;

void Tache::imgTache() {
	string temp = nom_;
	char * tab = new char[temp.length() + 1];
	strcpy_s(tab, temp.length() + 1, temp.c_str());
	imageTache.resize(duree_, 100);
	const unsigned char black[] = { 0,0,0 };
	imageTache.draw_text(20,20,tab,black);
}

void Categorie::imgCategorie() {
	string temp = nom_;
	char * tab = new char[temp.length() + 1];
	strcpy_s(tab, temp.length() + 1, temp.c_str());
	imageCategorie.resize(dureeTotale, 100);
	const unsigned char black[] = { 0,0,0 };
	imageCategorie.draw_text(20, 20, tab, black);
}

int Temps::operator-(const Temps &t) { // t est la plus grande AUTEUR AMINE 
	int jourParMois[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int duree = 0;
	int duree1 = 0;
	int duree2 = 0;
	duree1 += annee_ * 365;
	duree2 += t.annee_ * 365;
	for (int i = 0; i <= 12; i++) {
		if (i <= mois_) {
			duree1 += jourParMois[i];
		}
		if (i <= t.mois_) {
			duree2 += jourParMois[i];
		}
	}
	duree1 += jour_;
	duree2 += t.jour_;
	duree = duree1 - duree2;
	return duree;
}
