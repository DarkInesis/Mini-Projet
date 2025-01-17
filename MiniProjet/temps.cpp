#include "temps.h"
Temps::Temps()
{
	jour_ = 0;
	mois_ = 0;
	annee_ = 0;
}

Temps::Temps(int jour, int mois, int annee)
{
	int jourParMois[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (mois > 12 || mois<=0)
	{
		cout << "mois entre incorrect" << endl;
		cout << "Veuillez saisir un mois inferieur a " << 12 << endl;
		mois =saisieEntier();
	}
	mois_ = mois;
	while (jour > jourParMois[mois] || jour<=0)
	{
		cout << "Jour entre incorrect" << endl;
		cout << "Veuillez saisir un jour inferieur a " << jourParMois[mois] << endl;
		jour = saisieEntier();
	}
	jour_ = jour;
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
string Temps::convertirString()
{
	return (to_string(jour_)+"/"+ to_string(mois_) +"/"+ to_string(annee_));
}

Temps Temps::dateFin(int duree)
{
	int jourParMois[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //Contient le nombre de jour par mois (la premiere case est initialis�e � -1, car on ne souhaite pas l'utiliser)
	Temps date;
	int jourfin, moisfin, anneefin;
	jourfin= jour_+duree -1 ;// On compte le jour de d�but comme un jour
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

bool Temps::operator>(const Temps& t)
{
	int jourT = t.jour_, moisT = t.mois_, anneeT = t.annee_;
	if (anneeT < annee_)
	{
		return true;
	}
	else
	{
		if (moisT < mois_)
		{
			return true;
		}
		else
		{
			if (jourT < jour_)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool Temps::operator<(const Temps& t)
{
	int jourT = t.jour_, moisT = t.mois_, anneeT = t.annee_;
	if (anneeT > annee_)
	{
		return true;
	}
	else
	{
		if (moisT > mois_)
		{
			return true;
		}
		else
		{
			if (jourT > jour_)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

int Temps::operator-(const Temps& t) { // t est la plus grande AUTEUR AMINE 
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

int saisieEntier()
{
	int reponse;
	while (!(cin >> reponse))
	{
		cout << "Erreur de saisie" << endl << "Recommencez" << endl;
		if (!cin.eof())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			cin.clear();
		}
	}
	return reponse;
}