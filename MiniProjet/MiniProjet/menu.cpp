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
	cout << "7) Modifier tache" << endl;
	cout << "8) Quitter" << endl;
	cout << "9) Charger" << endl;
}

void menu(Diagramme diagr, CImgDisplay &disp)
{
	diagr.refreshDiagramme();
	disp.display(diagr.getImgDiagramme());
	afficherMenu();
	int choix = 0;
	choix = saisieEntier();
	string nomCategorie="";
	string reponsefermeture;
	string nomFichierCharge;
	switch (choix)
	{
	case 1:
		system("cls");
		diagr.afficherDiagramme();
		system("pause");
		menu(diagr, disp);
		break;
	case 2 :
		system("cls");
		cout << "Entrer le nom de la categorie a afficher" << endl;
		// Vide le tampon du clavier.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, nomCategorie);
		diagr.afficherTacheCategorie(nomCategorie);
		system("pause");
		menu(diagr, disp);
		break;
	case 3 :
		system("cls");
		diagr.insererCategorie();
		system("pause");
		menu(diagr, disp);
		break;
	case 4 :
		system("cls");
		cout << "Entrer le nom de la categorie ou ajouter la tache" << endl;
		// Vide le tampon du clavier.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, nomCategorie);
		diagr.insererTacheCategorie(nomCategorie);
		system("pause");
		menu(diagr, disp);
		break;
	case 5 :
		system("cls");
		diagr.supprimerCategorie();
		system("pause");
		menu(diagr, disp);
		break;
	case 6 : 
		system("cls");
		cout << "Entrer le nom de la categorie ou enlever la tache" << endl;
		// Vide le tampon du clavier.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, nomCategorie);
		diagr.supprimerTacheCategorie(nomCategorie);
		menu(diagr, disp);
		break;
	case 7 :
		diagr.modifierTache();
		break;
	case 8 :
		cout << "Voulez-vous sauvegarder votre fichier ? (y/n)" << endl;
		cin >> reponsefermeture;
		
		if (reponsefermeture == "y" || reponsefermeture =="Y"|| reponsefermeture =="o"|| reponsefermeture =="O")
		
		{
			string chemin = "Sauvegarde/";
			cout << "Entrer le nom du fichier de sauvegarde" << endl;
			string nomSauvegarde;
			cin >> nomSauvegarde;
			nomSauvegarde += ".txt";
			chemin += nomSauvegarde;
			ofstream fichierSauvegarde(chemin);
			diagr.sauver(fichierSauvegarde);
			break;
		}
		else
			if (reponsefermeture != "n" && reponsefermeture != "N")
			{
				cout << "Erreur : touche non attribuee" << endl;
				menu(diagr, disp);
				break;
			}
			else
			{
				break;
			}
	case 9 :
		cout << "Entrer le nom du fichier a charger" << endl;
		cin >> nomFichierCharge;
		nomFichierCharge += ".txt";
		if (true)
		{
			string chemin = "Sauvegarde/";
			chemin += nomFichierCharge;
			ifstream fichierCharger(chemin);
			if (!fichierCharger.is_open())
			{
				cout << "erreur chargement" << endl;
			}
			diagr.charger(fichierCharger);
		}
		menu(diagr, disp);
		break;
	default:
		cout << "Nombre rentre invalide, recommencez" << endl;
		system("pause");
		menu(diagr, disp);
		break;
	}

}