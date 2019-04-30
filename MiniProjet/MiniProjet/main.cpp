#include <iostream>
#include <string>
#include <list>
#include "CImg.h"

#include "tache.h"
#include "categorie.h"
#include "diagramme.h"
#include "menu.h"

using namespace cimg_library;


int main()
{
	// Declare a display
	Diagramme diag1;
	CImgDisplay disp(diag1.getImgDiagramme());
	disp.resize();
	// Wait for the display window to close
	/*while (!disp.is_closed()) {
		disp.wait();
	}*/
	
	menu(diag1, disp);
}