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
	imgCalendrier(0, 0, 1, 3);
	imgDiagramme(1920, 1080, 1, 3);
	imgFrise(0, 0, 1, 3);
	imgMenu(0, 0, 1, 3);
}

void Diagramme::changementDates() // Permet de mettre � jour la date de debut et de fin du diagramme
{
	list<Categorie>::iterator it;
	if (!listeCategorie.empty())
	{
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
}
void Diagramme::afficherDiagramme()
{
	list<Categorie>::iterator itCategorie; // permet de parcourir la liste des cat�gorie
	for (itCategorie = listeCategorie.begin(); itCategorie != listeCategorie.end(); itCategorie++)
	{
		(*itCategorie).afficherCategorie();
	}
}
void Diagramme::afficherTacheCategorie(string nomCategorie)
{
	bool estValide = false;
	list<Categorie>::iterator itCategorie; // permet de parcourir la liste des cat�gorie
	for (itCategorie = listeCategorie.begin(); itCategorie != listeCategorie.end(); itCategorie++)
	{
		if ((*itCategorie).getNom() == nomCategorie)
		{
			estValide = true;
			break; // On arrete de parcourir la liste lorsque l'on a trouv� le bon nom.
		}
	}
	if (!estValide) // Cas ou le nom ne se trouve pas dans la liste
	{
		cout << "Nom entre invalide" << endl;
	}
	// A partir d'ici, itCategorie correspond au pointeur vers la cat�gorie souhait�e
	else {
		(*itCategorie).afficherListeTaches(); // On affiche toute la liste des taches appartenant � la cat�gorie rentr�e
	}
}


void Diagramme::supprimerCategorie()
{
	cout << "Entrer le nom de la categorie a supprimer" << endl;
	string nomCategorie;
	cin>>nomCategorie;
	list<Categorie>::iterator itCategorie; // permet de parcourir la liste des cat�gorie
	bool aSupprimee = false;
	for (itCategorie = listeCategorie.begin(); itCategorie != listeCategorie.end(); itCategorie++)
	{
		if ((*itCategorie).getNom() == nomCategorie)
		{
			itCategorie=listeCategorie.erase(itCategorie);
			setNbElement(nombreElements - 1);
			aSupprimee = true;
			break;
		}
	}
	if ( itCategorie == listeCategorie.end() && aSupprimee==false) // Cas ou le nom ne se trouve pas dans la liste
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
			break; // On arrete de parcourir la liste lorsque l'on a trouv� le bon nom.
		}
		
	}
	if (iteratorCategorie == listeCategorie.end()) // Cas ou le nom ne se trouve pas dans la liste
	{
		cout << "Nom entre invalide" << endl;
	}
	else
	{
		(*iteratorCategorie).insererTache();
		setNbElement(nombreElements + 1);
	}
}
void Diagramme::supprimerTacheCategorie(string nomCategorie)
{
	list<Categorie>::iterator iteratorCategorie;
	
	for (iteratorCategorie = listeCategorie.begin(); iteratorCategorie != listeCategorie.end(); iteratorCategorie++)
	{
		if ((*iteratorCategorie).getNom() == nomCategorie)
		{
			break; // On arrete de parcourir la liste lorsque l'on a trouv� le bon nom.
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
		if (!(*iteratorCategorie).getListeTache().empty())
		{
			(*iteratorCategorie).supprimerTache();
			setNbElement(nombreElements - 1);
		}
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
		// Vide le tampon du clavier.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, nomCategorie);
		list<Categorie>::iterator itCategorie; // permet de parcourir la liste des cat�gorie
		for (itCategorie = listeCategorie.begin(); itCategorie != listeCategorie.end(); itCategorie++)
		{
			if ((*itCategorie).getNom() == nomCategorie)
			{
				cout << "Entrer le nom de la tache � modifier " << endl;
				string nomTacheModif;
				// Vide le tampon du clavier.
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, nomTacheModif);
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

void Diagramme::refreshFrise()
{
	const unsigned char blue[] = { 0,0,255 }, white[] = { 255,255,255 }, black[] = { 0,0,0 };

	calculDuree();
	
	float largeur = 0.8 * imgDiagramme.width();
	int hauteur = 0.1 * imgDiagramme.height();
	if (duree != 0)
	{
		echelle = largeur / duree;
	}
	else
	{
		echelle = 0;
	}

	imgFrise.clear();
	imgFrise(largeur, hauteur,1,3);
	imgFrise.draw_rectangle(0, 0,largeur, hauteur,blue);
	int positionTrait;
	for (int i = 0; i < duree; i++)
	{
		positionTrait = i * echelle;
		imgFrise.draw_line(positionTrait, 0, positionTrait, hauteur, black);
	}
}

void Diagramme::refreshMenu()
{
	const unsigned char blue[] = { 0,0,255 }, white[] = { 255,255,255 }, black[] = { 0,0,0 }, red[] = { 255,0,0 };
	float largeur = 0.2 * imgDiagramme.width();
	int hauteur = imgDiagramme.height();
	imgMenu.clear(); 
	imgMenu(largeur, hauteur,1,3);
	imgMenu.draw_rectangle(0, 0, largeur, hauteur, white);
	imgMenu.draw_text(0, 0, "Diagramme de Gantt", imgFrise.height(), black);
	int tailleParElement = 0;
	if (nombreElements != 0)
	{
		tailleParElement = (imgDiagramme.height() - imgFrise.height()) / nombreElements;
	}

	int positionYElement = imgFrise.height();
	list<Categorie>::iterator itCategorie;
	list<Tache>::iterator itTache;
	string temp;
	for (itCategorie = listeCategorie.begin(); itCategorie != listeCategorie.end(); itCategorie++) //On parcourt la liste de cat�gorie
	{
		//On affiche le nom de la cat�gorie
		temp = (*itCategorie).getNom(); // tempstocke le nom de la cat�gorie actuelle
		char* tab = new char[temp.length() + 1]; // creation d'un tableau de caractere qui pourront etre ecrit dans le menu
		strcpy_s(tab, temp.length() + 1, temp.c_str()); // Permet de copier 

		imgMenu.draw_text(0, positionYElement ,tab , tailleParElement, red); // Ecrit sur le menu le nom de la cat�gorie

		positionYElement += tailleParElement; // On se d�place de la taille d'un �l�ment vers le bas, pour �crire le prochain element
		if (!(*itCategorie).getListeTache().empty())
		{
			for (itTache = (*itCategorie).getListeTache().begin(); itTache != (*itCategorie).getListeTache().end(); itTache++) // On parcout la liste des taches pour chaque cat�gorie
			{
				temp = (*itTache).getNom(); // tempstocke le nom de la cat�gorie actuelle
				char* tab = new char[temp.length() + 1]; // creation d'un tableau de caractere qui pourront etre ecrit dans le menu
				strcpy_s(tab, temp.length() + 1, temp.c_str()); // Permet de copier 

				imgMenu.draw_text(0, positionYElement, tab, tailleParElement, blue); // Ecrit sur le menu le nom de la tache

				positionYElement += tailleParElement; // On se d�place de la taille d'un �l�ment vers le bas, pour �crire le prochain element

			}
		}

	}
}

void Diagramme::refreshDiagramme()
{

	imgDiagramme.clear();
	imgDiagramme(1920, 1080, 1, 3);
	//refreshCalendrier();
	refreshFrise();
	refreshMenu();

	imgDiagramme.draw_image(0, 0, imgMenu);
	imgDiagramme.draw_image(positionFrise[0], positionFrise[1], imgFrise);
	//imgDiagramme.draw_image(positionCalendrier[0], positionCalendrier[1], imgCalendrier);
}