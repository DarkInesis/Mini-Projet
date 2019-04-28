#include "temps.h"
Temps::Temps()
{
	jour_ = 0;
	mois_ = 0;
	annee_ = 0;
}

Temps::Temps(int jour, int mois, int annee)
{
	jour_ = jour;
	mois_ = mois;
	annee_ = annee;
}

void Temps::operator=(const Temps &t)
{
	jour_ = t.jour_;
	mois_ = t.mois_;
	annee_ = t.annee_;
}

void Temps::afficherTemps()
{
	std::cout << jour_ << "/" << mois_ << "/" << annee_ << std::endl;
}

Temps Temps::dateFin(int duree)
{
	int jourParMois[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //Contient le nombre de jour par mois (la premiere case est initialisée à -1, car on ne souhaite pas l'utiliser)
	Temps date;
	int jourfin, moisfin, anneefin;
	jourfin= duree+jour_;
	moisfin = mois_;
	anneefin = annee_;
	while (jourfin> jourParMois[moisfin])
	{
		jourfin -= jourParMois[moisfin];
		moisfin += 1;
		if (moisfin == 13)
		{
			moisfin = 1;
			anneefin += 1;
		}
	}
	date.setJour(jourfin);
	date.setMois(moisfin);
	date.setAnnee(anneefin);
	return(date);
}