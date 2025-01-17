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
		(*it).afficherTache(); // affiche la tache (nom/date debut/duree/num�ro)
	}

}

void Categorie::calculDuree()
{
	list<Tache>::iterator it;
	int dureeTotale = 0; //permet de mettre � 0 la dur�e totale avant de sommer la dur�e de toutes les taches
	for (it = listeTaches.begin(); it != listeTaches.end(); it++)
	{
		dureeTotale += (*it).getDuree(); // ajoute la dur�e de la tache � la variable dureeTotale
	}
}

void Categorie::insererTache(Tache nouvTache, unsigned int position)
{
	list<Tache>::iterator it; // iterateur permettant de parcourir la liste de t�che lors de la recherche de la bonne position
	list<Tache>::iterator itmodifposition; // iterateur permettant de parcourir le reste de la liste, car on souhaite augmenter de 1 la position de tous les autres taches
	 
	if (position <= listeTaches.size() && position>0)
	{
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
	if (listeTaches.size() == 0 || position == listeTaches.size()+1) // cas o� l'on cr�er la premiere tache ou lorsque l'on veut mettre la tache � la fin de la liste
	{
		listeTaches.push_back(nouvTache);
		nouvTache.modifierNumero(listeTaches.size());
		calculDuree();
	}
	if (position > listeTaches.size()+1)
	{
		cout << "Position superieure au nombre total de taches, pour annuler taper -1" << endl;
		cout << "veuillez saisir une position acceptable (inferieur a " << listeTaches.size() << ")" << endl;
		cin >> position; // L'utilisateur rentre une position acceptable (si ce n'est pas le cas, il y a une boucle jusqu'� ce qu'il le fasse
		if (position == -1)
		{
			cout << "Ajout de la tache annule" << endl;
		}
		else {
			insererTache(nouvTache, position);  // On appelle de nouveau la fonction, ce qui permet d'inserer la tache si la position est correcte, sinon lui redemande une position
		}
	}
	
}

void Categorie::supprimerTache(unsigned int position)
{

	list<Tache>::iterator it; // iterateur permettant de parcourir la liste de t�che lors de la recherche de la bonne position
	
	if (position < listeTaches.size() && position > 0)
	{
		for (it = listeTaches.begin(); it != listeTaches.end(); it++)
		{
			if ((*it).getNumero() == position)
			{
				listeTaches.erase(it); // Si on tombe sur la tache ayant le bon num�ro, on la supprime
				break; // On break, c'est � dire qu'on sort de la boucle for, car � cause du erase, on a supprimer un element, la boucle for est donc bugg�e
			}
		}
		for (it = listeTaches.begin(); it != listeTaches.end(); it++) // On va ici modifier la position des taches �tant apr�s celle qu'on vient de supprimer
		{
			if ((*it).getNumero() > position)
			{
				(*it).modifierNumero((*it).getNumero() - 1);
			}
		}
		calculDuree();
	}
	if (position == listeTaches.size()) // cas o� l'on cr�er la premiere tache ou lorsque l'on veut mettre la tache � la fin de la liste
	{
		listeTaches.pop_back(); 
		calculDuree();
	}
	if (position<=0 || position > listeTaches.size() + 1)
	{
		cout << "Position superieure au nombre total de taches, pour annuler taper -1" << endl;
		cout << "veuillez saisir une position acceptable (inferieur a " << listeTaches.size() << ")" << endl;
		cin >> position; // L'utilisateur rentre une position acceptable (si ce n'est pas le cas, il y a une boucle jusqu'� ce qu'il le fasse
		if (position == -1)
		{
			cout << "Ajout de la tache annule" << endl;
		}
		else {
			supprimerTache(position);  // On appelle de nouveau la fonction, ce qui permet d'inserer la tache si la position est correcte, sinon lui redemande une position
		}
	}
}

void Categorie::afficherCategorie()
{
	cout << "Nom de la categorie " << nom_ << endl;
	cout << "Dur�e : " << dureeTotale << endl;
	dateDebut.afficherTemps();
}