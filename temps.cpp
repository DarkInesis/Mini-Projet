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
