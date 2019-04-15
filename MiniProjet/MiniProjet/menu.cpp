#include "menu.h"

using namespace std;


void afficherMenu()
{
	cout << "Menu : " << endl;
	cout << "1) Afficher categories" << endl;
	cout << "2) Afficher  les taches d'une categorie" << endl;
	cout << "3) Ajouter categorie" << endl;
	cout << "4) Ajouter une tache a une categorie" << endl;
	cout << "5) Suprimer une categorie" << endl;
	cout << "6) Suprimer une tache" << endl;
	cout << "7) Quitter" << endl;
}

void menu(Diagramme diagr)
{
	afficherMenu();
	int choix = 0;
	cin >> choix;
	string nomCategorie="";
	list<Categorie>::iterator iteratorCategorie;
	switch (choix)
	{
	case 1:
		system("cls");
		diagr.afficherDiagramme();
		system("pause");
		menu(diagr);
		break;
	case 2 :
		system("cls");
		cout << "Entrer le nom de la categorie a afficher" << endl;
		cin >> nomCategorie;
		diagr.afficherTacheCategorie(nomCategorie);
		system("pause");
		menu(diagr);
		break;
	case 3 :
		system("cls");
		diagr.insererCategorie();
		system("pause");
		menu(diagr);
		break;
	case 4 :
		system("cls");
		cout << "Entrer le nom de la categorie ou ajouter la tache" << endl;
		cin >> nomCategorie;
		iteratorCategorie=diagr.getIteratorCategorie(nomCategorie);
		(*iteratorCategorie).insererTache();
		system("pause");
		menu(diagr);
		break;
	case 5 :
		system("cls");
		diagr.supprimerCategorie();
		system("pause");
		menu(diagr);
		break;
	case 6 : 
		system("cls");
		cout << "Entrer le nom de la categorie ou enlever la tache" << endl;
		cin >> nomCategorie;
		iteratorCategorie = diagr.getIteratorCategorie(nomCategorie);
		(*iteratorCategorie).supprimerTache();
		system("pause");
		menu(diagr);
		break;
	case 7 :
		break;
	default:
		cout << "Nombre rentre invalide, recommencez" << endl;
		system("pause");
		menu(diagr);
		break;
	}

}