#include <iostream>
#include <windows.h>
#include "Openscad.h"

using namespace std;

int main()
{
    // On récupère l'encodage
    unsigned int default_codepage = GetConsoleOutputCP();
    // On met le bon encodage
    SetConsoleOutputCP(1252);

    Openscad myOpenscad;
    cout << myOpenscad.renvoieCommentGenerator() << endl;
    cout << myOpenscad.renvoieEchoVersion() << ";" << endl;
    cout << myOpenscad.renvoiePaveDroit(10,20,5) << ";" << endl;

    //translation
    cout << myOpenscad.renvoieTranslation(50,0,0) << endl;
    cout << "    " << myOpenscad.renvoiePaveDroit(10,20,5) << ";" << endl;
    cout << "}" << endl;

    //difference
    cout << myOpenscad.renvoieDifference() << endl;
    cout << "    " << myOpenscad.renvoiePaveDroit(10,20,5) << ";" << endl;
    cout << "    " << myOpenscad.renvoiePaveDroit(5,30,3) << ";" << endl;
    cout << "}" << endl;

    // On restaure l'encodage initial.
    SetConsoleOutputCP(default_codepage);
    return 0;
}
