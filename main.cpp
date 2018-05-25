#include <iostream>
//Pour le système pause
#include <cstdlib>
#include <windows.h>
#include "GeneBoiteRevues00.h"
//#include "Openscad.h"
using namespace std;

int main()
{
    // On récupère l'encodage pour avoir les accents dans la console
    unsigned int default_codepage = GetConsoleOutputCP();
    // On met le bon encodage
    SetConsoleOutputCP(1252);

    // Création du concepteur de boite
    GeneBoiteRevues00 geneBoiteRevues00;

    //geneBoiteRevues00.demanderParametres();

    //affiche le récapitulatif
    cout << "=========================" << endl;
    cout << "Entrée des paramètres" << endl;
    cout << "=========================" << endl;
    geneBoiteRevues00.afficheRecapitulatif();

    //créer le programme openscad
    cout << "\n=========================" << endl;
    cout << "Programme openscad" << endl;
    cout << "=========================" << endl;
    cout << geneBoiteRevues00.construitBoite() << endl;
    /*ShellExecute(NULL,  // Handle de la fenêtre parent
                 "open", // Action à effectuer
                 "C:\\Program Files\\OpenSCAD\\openscad.exe", // Fichier
                 chaineNomFichier.c_str(), // Paramètres
                 "", // Répertoire par défaut
                 SW_SHOWDEFAULT // Manière d'afficher
                 );*/

    //restaure l'encodage initial
    SetConsoleOutputCP(default_codepage);
    system("PAUSE");
    return 0;
}
