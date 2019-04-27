#include "diagramme.h"
#include <fstream>
Diagramme::Diagramme()
{
	list<Categorie> listeCategorie;
}
void Diagramme::afficherDiagramme()
{
	list<Categorie>::iterator itCategorie; // permet de parcourir la liste des catégorie
	for (itCategorie = listeCategorie.begin(); itCategorie != listeCategorie.end(); itCategorie++)
	{
		(*itCategorie).afficherCategorie();
	}
}


void Diagramme::afficherTacheCategorie(string nomCategorie)
{
	list<Categorie>::iterator iterateur;
	iterateur=getIteratorCategorie(nomCategorie);
	// A partir d'ici, itCategorie correspond au pointeur vers la catégorie souhaitée
	(*iterateur).afficherListeTaches(); // On affiche toute la liste des taches appartenant à la catégorie rentrée
}
void Diagramme::supprimerCategorie()
{
	cout << "Entrer le nom de la categorie a supprimer" << endl;
	string nomCategorie;
	cin>>nomCategorie;
	list<Categorie>::iterator itCategorie; // permet de parcourir la liste des catégorie
	for (itCategorie = listeCategorie.begin(); itCategorie != listeCategorie.end(); itCategorie++)
	{
		if ((*itCategorie).getNom() == nomCategorie)
		{
			listeCategorie.erase(itCategorie);
			break;
		}
		if ((*itCategorie).getNom() != nomCategorie && itCategorie == listeCategorie.end()) // Cas ou le nom ne se trouve pas dans la liste
		{
			cout << "Nom entre invalide" << endl;
		}
	}
}

list<Categorie>::iterator Diagramme::getIteratorCategorie(string nomCategorie)
{
	list<Categorie>::iterator itCategorie; // permet de parcourir la liste des catégorie
	for (itCategorie = listeCategorie.begin(); itCategorie != listeCategorie.end(); itCategorie++)
	{
		if ((*itCategorie).getNom() == nomCategorie)
		{
			break;
		}
		if ((*itCategorie).getNom() != nomCategorie && itCategorie == listeCategorie.end()) // Cas ou le nom ne se trouve pas dans la liste
		{
			cout << "Nom entre invalide" << endl;
		}
	}
	return itCategorie;
}

void Diagramme::sauver(ofstream& ofs)
{
	list<Categorie>::iterator it;
	for (it = listeCategorie.begin(); it != listeCategorie.end(); it++)
	{
		ofs << listeCategorie.size()<<endl;
		(*it).sauver(ofs);
	}
}
void Diagramme::charger(ifstream& ifs)
{
	int tailleListeCategorie = 0;
	ifs >> tailleListeCategorie;
	Categorie categorieTemp;
	for (int i = 0; i < tailleListeCategorie; i++)
	{
		categorieTemp.charger(ifs);
		listeCategorie.push_back(categorieTemp);
	}
}