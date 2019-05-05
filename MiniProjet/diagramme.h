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
	void changementDates();// Permet de mettre à jour les dates de début et de fin du diagramme
	void afficherDiagramme(); 
	void afficherTacheCategorie(string nomCategorie); //Permet d'afficher toutes les taches d'une catégorie
	void insererCategorie() { Categorie nouvCategorie; listeCategorie.push_back(nouvCategorie); nombreElements += 1; } // Permet d'inserer une catégorie déja crée
	void supprimerCategorie(); //Supprime une catégorie et son contenu (nom/listeTaches etc)
	void insererTacheCategorie(string nomCategorie);  // Insere une tache dans une catégorie
	void supprimerTacheCategorie(string nomCategorie); //Supprime la tache d'une catégorie

	void modifierTache(); // Permet de modifier les caractéristiques d'une tache

	int getNbElement() { return nombreElements; } // Fonction necessaire pour mettre a jour le nb d'élements
	void setNbElement(int nbElements) { nombreElements = nbElements; } //Fonction permettant de changer le nb d'élements (taches+catégories)

	void calculDuree() { duree = dateFin -  dateDebut+1; }; // Permet de calculer la durée entre la date de début du diagramme de Gant et celle de fin en comptant le jour de début


	void refreshFrise(); // Supprime puis recrée l'image de la frise
	void refreshMenu(); // Supprime puis recrée l'image du menu
	void refreshCalendrier();// Supprime puis recrée l'image du calendrier
	void refreshDiagramme(); // Supprime puis recrée l'image du diagramme (image contenant toutes les autres et qui est affichée dans la fenetre)

	void sauver(ofstream& ofs); // sauvegarde le diagramme (fait appel à sauver de catégorie qui fait appel à sauber de tache)
	void charger(ifstream& ifs); // charge le diagramme

	CImg<unsigned char> getImgDiagramme() { return imgDiagramme; } // Renvoit l'image du diagramme de Gantt à afficher

	
};

