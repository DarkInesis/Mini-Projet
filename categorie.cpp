#include "categorie.h"

Categorie::Categorie(string nom, Temps debut)
{
	nom_ = nom;
	dateDebut = debut;
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

	if (position <= listeTaches.size()) // Cas o� la position est valide
	{
		for (it = listeTaches.begin(); it != listeTaches.end(); it++)
		{
			if ((*it).getNumero() == position) // on pointe vers la t�che ayant la position o� l'on souhaite inserer la nouvelle tache
			{
				listeTaches.insert(it, nouvTache); // Insersion de la tache � sa bonne place
				nouvTache.modifierNumero(position); // Permet d'associer le bon num�ro � la tache ajout�e
				for (itmodifposition = it++; itmodifposition != listeTaches.end(); itmodifposition++) // Boucle sur toutes les t�ches apr�s celle ins�r�e
				{
					(*itmodifposition).modifierNumero((*itmodifposition).getNumero() + 1); // Permet de decaler la position de 1 de toutes les taches qui sont apr�s celle ins�r�e 
				}
			}
		}
		if (listeTaches.size() == 0) // Cas ou la liste des tache est vide
		{
			listeTaches.push_front(nouvTache); // insert le premier �l�ment
			nouvTache.modifierNumero(1);
		}
		calculDuree(); // Permet de mettre � jour la dur�e total de la cat�gorie
	}
	else // Prise en compte des cas d'erreur (position sup�rieure au nombre total de taches
	{
		cout << "Position sup�rieure au nombre total de taches" << endl;
		cout << "veuillez saisir une position acceptable (inf�rieur � " << listeTaches.size() << ")" << endl;
		cin >> position; // L'utilisateur rentre une position acceptable (si ce n'est pas le cas, il y a une boucle jusqu'� ce qu'il le fasse
		insererTache(nouvTache, position);  // On appelle de nouveau la fonction, ce qui permet d'inserer la tache si la position est correcte, sinon lui redemande une position
	}
}

void Categorie::supprimerTache(int num)
{

}