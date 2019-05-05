#pragma once
#include "categorie.h"
#include <list>
#include "CImg.h"
class Diagramme
{
	list<Categorie> listeCategorie;
	Temps dateDebut;
	Temps dateFin;
	int duree=0;
	int echelle=0;
	int nombreElements=0;

	CImg<unsigned char> imgDiagramme;

	CImg<unsigned char> imgMenu;
	int positionMenu[2] = { 0,0 };
	CImg <unsigned char> imgFrise;
	int positionFrise[2] = { imgMenu.height(), 0 };
	CImg<unsigned char> imgCalendrier;
	int positionCalendrier[2] = { positionFrise[0], imgFrise.height() };

public:
	Diagramme();
	void changementDates();// Permet de mettre � jour les dates de d�but et de fin du diagramme
	void afficherDiagramme(); 
	void afficherTacheCategorie(string nomCategorie); //Permet d'afficher toutes les taches d'une cat�gorie
	void insererCategorie() { Categorie nouvCategorie; listeCategorie.push_back(nouvCategorie); nombreElements += 1; } // Permet d'inserer une cat�gorie d�ja cr�e
	void supprimerCategorie(); //Supprime une cat�gorie et son contenu (nom/listeTaches etc)
	void insererTacheCategorie(string nomCategorie);  // Insere une tache dans une cat�gorie
	void supprimerTacheCategorie(string nomCategorie); //Supprime la tache d'une cat�gorie

	void modifierTache(); // Permet de modifier les caract�ristiques d'une tache

	int getNbElement() { return nombreElements; } // Fonction necessaire pour mettre a jour le nb d'�lements
	void setNbElement(int nbElements) { nombreElements = nbElements; } //Fonction permettant de changer le nb d'�lements (taches+cat�gories)

	void calculDuree() { duree = dateFin -  dateDebut+1; }; // Permet de calculer la dur�e entre la date de d�but du diagramme de Gant et celle de fin en comptant le jour de d�but


	void refreshFrise(); // Supprime puis recr�e l'image de la frise
	void refreshMenu(); // Supprime puis recr�e l'image du menu
	void refreshCalendrier();// Supprime puis recr�e l'image du calendrier
	void refreshDiagramme(); // Supprime puis recr�e l'image du diagramme (image contenant toutes les autres et qui est affich�e dans la fenetre)

	void sauver(ofstream& ofs); // sauvegarde le diagramme (fait appel � sauver de cat�gorie qui fait appel � sauber de tache)
	void charger(ifstream& ifs); // charge le diagramme

	CImg<unsigned char> getImgDiagramme() { return imgDiagramme; } // Renvoit l'image du diagramme de Gantt � afficher

	
};

