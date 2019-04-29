#include "categorie.h"

Categorie::Categorie(bool estChargee)
{
	if (!estChargee)
	{
		cout << "Nom  de la categorie :" << endl;
		cin >> nom_;
		cout << "Date de debut (jour puis mois puis annee) :" << endl;
		int jour, mois, an;
		cin >> jour;
		cin >> mois;
		cin >> an;
		dateDebut.setJour(jour);
		dateDebut.setMois(mois);
		dateDebut.setAnnee(an);
		dureeTotale = 0; //permet de mettre à 0 la durée totale
	}
	else
	{
		nom_ = "";
		dateDebut.setJour(0);
		dateDebut.setMois(0);
		dateDebut.setAnnee(0);
		dureeTotale = 0;
	}
}


void Categorie::afficherListeTaches()
{
	list<Tache>::iterator it;
	for (it = listeTaches.begin(); it != listeTaches.end(); it++) // permet de parcourir la liste des taches
	{
		(*it).afficherTache(); // affiche la tache (nom/date debut/duree/numéro)
	}

}

void Categorie::calculDuree()
{
	list<Tache>::iterator it;
	dureeTotale = 0;
	for (it = listeTaches.begin(); it != listeTaches.end(); it++)
	{
		dureeTotale += (*it).getDuree(); // ajoute la durée de la tache à la variable dureeTotale
	}
}

void Categorie::insererTache()
{
	cout << "Entrer la position ou inserer la Tache" << endl;
	unsigned int position = 0;
	cin >> position;
	list<Tache>::iterator it; // iterateur permettant de parcourir la liste de tâche lors de la recherche de la bonne position
	list<Tache>::iterator itmodifposition; // iterateur permettant de parcourir le reste de la liste, car on souhaite augmenter de 1 la position de tous les autres taches
	 
	if (position <= listeTaches.size() && position>0)
	{
		Tache nouvTache;
		for (it = listeTaches.begin(); it != listeTaches.end(); it++)
		{
			if ((*it).getNumero() >= position)
			{
				(*it).modifierNumero((*it).getNumero() + 1);
			}
			if((*it).getNumero() == position)
			{
				listeTaches.insert(it, nouvTache);
				nouvTache.modifierNumero(position);
			}

		}
		calculDuree();

	}
	if ((listeTaches.size() == 0 || position == listeTaches.size()+1)&& position<=listeTaches.size()+1) // cas où l'on créer la premiere tache ou lorsque l'on veut mettre la tache à la fin de la liste
	{
		Tache nouvTache;
		listeTaches.push_back(nouvTache);
		nouvTache.modifierNumero(listeTaches.size());
		calculDuree();
	}
	if (position > listeTaches.size()+1)
	{
		cout << "Position superieure au nombre total de taches, pour annuler taper -1" << endl;
		cout << "veuillez saisir une position acceptable (inferieur a " << listeTaches.size()+1 << ")" << endl;
		cin >> position; // L'utilisateur rentre une position acceptable (si ce n'est pas le cas, il y a une boucle jusqu'à ce qu'il le fasse
		if (position == -1)
		{
			cout << "Ajout de la tache annule" << endl;
		}
		else {
			insererTache();  // On appelle de nouveau la fonction, ce qui permet d'inserer la tache si la position est correcte, sinon lui redemande une position
		}
	}
	changementDates();
}

void Categorie::supprimerTache()
{
	cout << "Entrer la position ou supprimer la Tache" << endl;
	unsigned int position = 0;
	cin >> position;
	
	int jourParMois[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //Contient le nombre de jour par mois (la premiere case est initialisée à -1, car on ne souhaite pas l'utiliser)
	
	if (position < listeTaches.size() && position > 0)
	{
		list<Tache>::iterator it; // iterateur permettant de parcourir la liste de tâche lors de la recherche de la bonne position
		for (it = listeTaches.begin(); it != listeTaches.end(); it++)
		{
			if ((*it).getNumero() == position)
			{
				listeTaches.erase(it); // Si on tombe sur la tache ayant le bon numéro, on la supprime
				break; // On break, c'est à dire qu'on sort de la boucle for, car à cause du erase, on a supprimer un element, la boucle for est donc buggée
			}
		}
		for (it = listeTaches.begin(); it != listeTaches.end(); it++) // On va ici modifier la position des taches étant après celle qu'on vient de supprimer
		{
			if ((*it).getNumero() > position)
			{
				(*it).modifierNumero((*it).getNumero() - 1);
			}
		}
	}
	if (position == listeTaches.size()) // On supprime la derniere tache
	{
		listeTaches.pop_back(); 
	}
	if (position<=0 || position > listeTaches.size() + 1)
	{
		cout << "Position superieure au nombre total de taches, pour annuler taper -1" << endl;
		cout << "veuillez saisir une position acceptable (inferieur a " << listeTaches.size() << ")" << endl;
		cin >> position; // L'utilisateur rentre une position acceptable (si ce n'est pas le cas, il y a une boucle jusqu'à ce qu'il le fasse
		if (position == -1)
		{
			cout << "Ajout de la tache annule" << endl;
		}
		else {
			supprimerTache();  // On appelle de nouveau la fonction, ce qui permet d'inserer la tache si la position est correcte, sinon lui redemande une position
		}
	}
	calculDuree();
	changementDates();
}

void Categorie::afficherCategorie()
{
	cout << "Nom de la categorie " << nom_ << endl;
	cout << "Duree : " << dureeTotale << endl;
	cout << "Debut : ";
	dateDebut.afficherTemps();
	cout <<"Fin : ";
	dateFin_.afficherTemps();
}

void Categorie::sauver(ofstream& ofs)
{
	ofs << nom_ << endl;
	ofs << dureeTotale << endl;
	dateDebut.sauver(ofs);
	dateFin_.sauver(ofs);
	list<Tache>::iterator it;
	ofs << listeTaches.size()<<endl;
	for (it = listeTaches.begin(); it != listeTaches.end(); it++)
	{
		(*it).sauver(ofs);
	}
}

void Categorie::charger(ifstream& ifs)
{
	ifs >> nom_;
	ifs >> dureeTotale;
	dateDebut.charger(ifs);
	dateFin_.charger(ifs);
	int tailleListeTache = 0;
	ifs >> tailleListeTache;
	listeTaches.clear(); // On vide la variable au cas où elle n'était pas vide
	Tache tacheTemp(true);
	for (int i = 0; i < tailleListeTache; i++)
	{
		tacheTemp.charger(ifs);
		listeTaches.push_back(tacheTemp);
	}
}

void Categorie::changementDates()
{
	list<Tache>::iterator it;
	it =  listeTaches.begin();
	dateDebut = (*it).getDebut();
	dateFin_ = (*it).getFin();
	for (it = listeTaches.begin(); it != listeTaches.end(); it++)
	{
		if ((*it).getDebut() < dateDebut)
		{
			dateDebut = (*it).getDebut();
		}
		if ((*it).getFin() > dateFin_)
		{
			dateFin_ = (*it).getFin();
		}
	}
}

void Categorie::imgCategorie() {
	string temp = nom_;
	char* tab = new char[temp.length() + 1];
	strcpy_s(tab, temp.length() + 1, temp.c_str());
	imageCategorie.resize(dureeTotale, 100);
	const unsigned char black[] = { 0,0,0 };
	imageCategorie.draw_text(20, 20, tab, black);
}