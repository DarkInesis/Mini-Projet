#include "diagramme.h"
#include <fstream>

using namespace std;
bool testReponse(string reponse)
{
	if (reponse == "y" || reponse == "Y" || reponse == "o" || reponse == "O")
	{
		return true;
	}
	else
	{
		return false;
	}
}

Diagramme::Diagramme()
{
	list<Categorie> listeCategorie;
	Temps dateDebut_;
	Temps dateFin_;
}

void Diagramme::changementDates() // Permet de mettre à jour la date de debut et de fin du diagramme
{
	list<Categorie>::iterator it;
	it = listeCategorie.begin();
	dateDebut = (*it).getDebut();
	dateFin = (*it).getFin();
	for (it = listeCategorie.begin(); it != listeCategorie.end(); it++)
	{
		if ((*it).getDebut() < dateDebut)
		{
			dateDebut = (*it).getDebut();
		}
		if ((*it).getFin() > dateFin)
		{
			dateFin = (*it).getFin();
		}
	}
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
	list<Categorie>::iterator itCategorie; // permet de parcourir la liste des catégorie
	for (itCategorie = listeCategorie.begin(); itCategorie != listeCategorie.end(); itCategorie++)
	{
		if ((*itCategorie).getNom() == nomCategorie)
		{
			break; // On arrete de parcourir la liste lorsque l'on a trouvé le bon nom.
		}
	}
	if (itCategorie == listeCategorie.end()) // Cas ou le nom ne se trouve pas dans la liste
	{
		cout << "Nom entre invalide" << endl;
		system("pause");
		system("cls");
	}
	// A partir d'ici, itCategorie correspond au pointeur vers la catégorie souhaitée
	else {
		(*itCategorie).afficherListeTaches(); // On affiche toute la liste des taches appartenant à la catégorie rentrée
	}
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
	}
	if ( itCategorie == listeCategorie.end()) // Cas ou le nom ne se trouve pas dans la liste
	{
		cout << "Nom entre invalide" << endl;
		system("pause");
		system("cls");
	}
	changementDates();
}


void Diagramme::insererTacheCategorie(string nomCategorie)
{
	list<Categorie>::iterator iteratorCategorie;
	for (iteratorCategorie = listeCategorie.begin(); iteratorCategorie != listeCategorie.end(); iteratorCategorie++)
	{
		if ((*iteratorCategorie).getNom() == nomCategorie)
		{
			break; // On arrete de parcourir la liste lorsque l'on a trouvé le bon nom.
		}
		
	}
	if (iteratorCategorie == listeCategorie.end()) // Cas ou le nom ne se trouve pas dans la liste
	{
		cout << "Nom entre invalide" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		(*iteratorCategorie).insererTache();
	}
}
void Diagramme::supprimerTacheCategorie(string nomCategorie)
{
	list<Categorie>::iterator iteratorCategorie;
	for (iteratorCategorie = listeCategorie.begin(); iteratorCategorie != listeCategorie.end(); iteratorCategorie++)
	{
		if ((*iteratorCategorie).getNom() == nomCategorie)
		{
			break; // On arrete de parcourir la liste lorsque l'on a trouvé le bon nom.
		}
		
	}
	if (iteratorCategorie == listeCategorie.end()) // Cas ou le nom ne se trouve pas dans la liste
	{
		cout << "Nom entre invalide" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		(*iteratorCategorie).supprimerTache();
	}
}

void Diagramme::sauver(ofstream& ofs)
{
	list<Categorie>::iterator it;
	ofs << listeCategorie.size() << endl;
	for (it = listeCategorie.begin(); it != listeCategorie.end(); it++)
	{
		(*it).sauver(ofs);
	}
}
void Diagramme::charger(ifstream& ifs)
{
	int tailleListeCategorie = 0;
	ifs >> tailleListeCategorie;
	Categorie categorieTemp(true);
	for (int i = 0; i < tailleListeCategorie; i++)
	{
		categorieTemp.charger(ifs);
		listeCategorie.push_back(categorieTemp);
	}
}

void Diagramme::modifierTache()
{
		cout << "Entrez le nom de la categorie ou vous voulez modifier la tache" << endl;
		string nomCategorie;
		cin >> nomCategorie;
		list<Categorie>::iterator itCategorie; // permet de parcourir la liste des catégorie
		for (itCategorie = listeCategorie.begin(); itCategorie != listeCategorie.end(); itCategorie++)
		{
			if ((*itCategorie).getNom() == nomCategorie)
			{
				cout << "Entrer le nom de la tache à modifier " << endl;
				string nomTacheModif;
				cin >> nomTacheModif;
				list<Tache> ListeTacheTemp = (*itCategorie).getListeTache();
				list<Tache>::iterator itTache;

				for (itTache = ListeTacheTemp.begin(); itTache != ListeTacheTemp.end(); itTache++)
				{
					if (nomTacheModif == (*itTache).getNom())
					{
						cout << "Voulez-vous modifier la tache"<< nomTacheModif <<" (y/n)"<< endl;
						string reponse;
						cin >> reponse;
						if (testReponse(reponse))
						{
							(*itTache).menumodifTache();
							(*itCategorie).changementDates();
							(*itCategorie).calculDuree();
						}
						
						break;
					}
					if (itTache == ListeTacheTemp.end())
					{
						cout << "Tache inexistante" << endl;
					}
				}
					
			}
		}
		if (itCategorie == listeCategorie.end()) // Cas ou le nom ne se trouve pas dans la liste
		{
			cout << "Nom entre invalide" << endl;
			system("pause");
			system("cls");
		}
		changementDates();
}

