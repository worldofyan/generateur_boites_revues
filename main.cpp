#include <iostream>
//Pour le syst�me pause
#include <cstdlib>
#include <windows.h>
#include "GeneBoiteRevues00.h"
//#include "Openscad.h"
using namespace std;

int main()
{
    // On r�cup�re l'encodage pour avoir les accents dans la console
    unsigned int default_codepage = GetConsoleOutputCP();
    // On met le bon encodage
    SetConsoleOutputCP(1252);

    // Cr�ation du concepteur de boite
    GeneBoiteRevues00 geneBoiteRevues00;

    //geneBoiteRevues00.demanderParametres();

    //affiche le r�capitulatif
    cout << "=========================" << endl;
    cout << "Entr�e des param�tres" << endl;
    cout << "=========================" << endl;
    geneBoiteRevues00.afficheRecapitulatif();

    //cr�er le programme openscad
    cout << "\n=========================" << endl;
    cout << "Programme openscad" << endl;
    cout << "=========================" << endl;
    cout << geneBoiteRevues00.construitBoite() << endl;
    /*ShellExecute(NULL,  // Handle de la fen�tre parent
                 "open", // Action � effectuer
                 "C:\\Program Files\\OpenSCAD\\openscad.exe", // Fichier
                 chaineNomFichier.c_str(), // Param�tres
                 "", // R�pertoire par d�faut
                 SW_SHOWDEFAULT // Mani�re d'afficher
                 );*/

    //restaure l'encodage initial
    SetConsoleOutputCP(default_codepage);
    system("PAUSE");
    return 0;
}
