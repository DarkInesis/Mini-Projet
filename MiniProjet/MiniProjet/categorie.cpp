#include "categorie.h"

Categorie::Categorie()
{
	cout << "Nom  de la categorie :" << endl;
	cin >> nom_;
	cout << "Date de debut (jour puis mois puis annee) :" << endl;
	int jour, mois, an;
	cin >>jour;
	cin >> mois;
	cin >> an;
	dateDebut.setJour(jour);
	dateDebut.setMois(mois);
	dateDebut.setAnnee(an);
	dureeTotale = 0; //permet de mettre à 0 la durée totale
}

void Categorie::modifierNom(string nom) 
{
	nom_ = nom;
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
	
	int jourParMois[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //Contient le nombre de jour par mois (la premiere case est initialisée à -1, car on ne souhaite pas l'utiliser)
	list<Tache>::iterator it; // iterateur permettant de parcourir la liste de tâche lors de la recherche de la bonne position
	list<Tache>::iterator itmodifposition; // iterateur permettant de parcourir le reste de la liste, car on souhaite augmenter de 1 la position de tous les autres taches
	 
	if (position <= listeTaches.size() && position>0)
	{
		Tache nouvTache;
		for (it = listeTaches.begin(); it != listeTaches.end(); it++)
		{
			if ((*it).getNumero() == position)
			{
				(*it).modifierNumero(position + 1);
				listeTaches.insert(it, nouvTache);
				nouvTache.modifierNumero(position);
			}
			if ((*it).getNumero() > position+1)
			{
				(*it).modifierNumero((*it).getNumero() + 1);
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
	dateFin_ = dateDebut.dateFin(dureeTotale, jourParMois);
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
	dateFin_ = dateDebut.dateFin(dureeTotale, jourParMois);
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
	Tache tacheTemp;
	for (int i = 0; i < tailleListeTache; i++)
	{
		tacheTemp.charger(ifs);
		listeTaches.push_back(tacheTemp);
	}
}