#include <iostream>
#include <string>
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
#include <list>
#include "CImg.h"
#include "tache.h"
#include "categorie.h"
#include "diagramme.h"
#include "menu.h"

using namespace cimg_library;


int main()
{

	CImg<unsigned char> image;
	// Declare an image
	// Load an image file into it
	//image.load("test_kfa2_geforce_gtx_1070_hof_box_3.ppm");
	// Declare a display and dispay the image into it
	
	// Wait for the display window to close
	/*while (!disp.is_closed()) {
		disp.wait();
	}*/
	Diagramme diag1;
	menu(diag1);
}