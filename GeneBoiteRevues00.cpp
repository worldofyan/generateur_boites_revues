//implementation pour le generateur de revues
//
#include <iostream>
#include "Openscad.h"
#include "GeneBoiteRevues00.h"

using namespace std;

    GeneBoiteRevues00::GeneBoiteRevues00():
        nombre_revues{10},
        hauteur_revues{60},
        largeur_revues{200},
        longueur_revues{300},
        espacement_gauche{5},
        espacement_haut{20},
        espacement_devant{15},
        largeur_ouverture_bord{120},
        largeur_ouverture_sous_revues{100},
        depassement_ouverture{20},
        epaisseur_materiau{12},
        nom_dossier_enregistrement{"c:\\temp"},
        nom_fichier{"boite.scad"}


    {

    }

    void GeneBoiteRevues00::demanderParametres()
    {
        cout << "Entrer le nombre de revues : ";
        unsigned int nombre_revues_local;
        cin >> nombre_revues_local;
        setNombre_revues(nombre_revues_local);

        cout << "Entrer la hauteur des " << nombre_revues << " revues en mm : ";
        unsigned int hauteur_revues_local;
        cin >> hauteur_revues_local;
        setHauteur_revues(hauteur_revues_local);

        cout << "Entrer la largeur des revues en mm : ";
        unsigned int largeur_revues_local;
        cin >> largeur_revues_local;
        setLargeur_revues(largeur_revues_local);

        cout << "Entrer la longueur des revues en mm : ";
        unsigned int longueur_revues_local;
        cin >> longueur_revues_local;
        setLongueur_revues(longueur_revues_local);

        cout << "Entrer l'espace à gauche des revues en mm : ";
        unsigned int espacement_gauche_local;
        cin >> espacement_gauche_local;
        setEspacement_gauche(espacement_gauche_local);

        cout << "Entrer l'espace en haut des revues en mm : ";
        unsigned int espacement_haut_local;
        cin >> espacement_haut_local;
        setEspacement_haut(espacement_haut_local);

        cout << "Entrer l'espace devant les revues en mm : ";
        unsigned int espacement_devant_local;
        cin >> espacement_devant_local;
        setEspacement_devant(espacement_devant_local);

        cout << "Entrer la largeur de l'ouverture le long du bord en mm : ";
        unsigned int largeur_ouverture_bord_local;
        cin >> largeur_ouverture_bord_local;
        setLargeur_ouverture_bord(largeur_ouverture_bord_local);

        cout << "Entrer la largeur de l'ouverture sous les revues en mm : ";
        unsigned int largeur_ouverture_sous_revues_local;
        cin >> largeur_ouverture_sous_revues_local;
        setLargeur_ouverture_sous_revues(largeur_ouverture_sous_revues_local);

        cout << "Entrer le dépassement de l'ouverture sous les revues en mm : ";
        unsigned int depassement_ouverture_local;
        cin >> depassement_ouverture_local;
        setDepassement_ouverture(depassement_ouverture_local);

        cout << "Entrer l'épaisseur du matériau en mm : ";
        unsigned int epaisseur_materiau_local;
        cin >> epaisseur_materiau_local;
        setEpaisseur_materiau(epaisseur_materiau_local);

        cout << "Entrer le nom du dossier ou enregistrer le fichier (ex : \"c:\\temp\")";
        string nom_dossier_enregistrement_local;
        cin >> nom_dossier_enregistrement_local;
        setNomDossier(nom_dossier_enregistrement_local);

        cout << "Entrer le nom du fichier max 100 caractères (ex \"boite.scad\")";
        string nom_fichier_local;
        cin >> nom_fichier_local;
        setNomFichier(nom_fichier_local);

    }

    void GeneBoiteRevues00::afficheRecapitulatif()
    {
        //récapitulatif
        cout << "\n=========================" << endl;
        cout << "Récapitulatif" << endl;
        cout << "=========================" << endl;
        cout << "Nombre de revues : " << nombre_revues << endl;
        cout << "Hauteur des " << nombre_revues << " revues : " << hauteur_revues << endl;
        cout << "Largeur des revues : " << largeur_revues << endl;
        cout << "Longueur des revues : " << longueur_revues << endl;
        cout << "Espacement gauche : " << espacement_gauche << endl;
        cout << "Espacement haut : " << espacement_haut << endl;
        cout << "Espacement devant : " << espacement_devant << endl;
        cout << "Largeur ouverture bord : " << largeur_ouverture_bord << endl;
        cout << "Largeur ouverture sous revues : " << largeur_ouverture_sous_revues << endl;
        cout << "Dépassement de l'ouverture sous les revues : " << depassement_ouverture << endl;
        cout << "Epaisseur du matériau : " << epaisseur_materiau << endl;
        cout << "Le fichier sera enregistré sous le nom : \"" << getNomFichierEntier() << "\""<< endl;
    }

    string GeneBoiteRevues00::construitBoite()
    {
        string entete = construitEntete() + "\n\n";
        string commentPlaqueBas = "//Plaque du bas\n";
        //string paveBas = construitPlaqueBas() + ";\n\n";
        string plaqueBasEvidee = construitPlaqueBasEvidee() + "\n\n";
        string commentPlaqueHaut = "//Plaque du haut\n";
        string plaqueHaut = construitPlaqueHaut()+ "\n\n";
        string commentPlaqueGauche = "//Plaque de gauche\n";
        string plaqueGauche = construitPlaqueGauche() + "\n\n";
        string commentPlaqueDroite = "//Plaque de droite\n";
        string plaqueDroite = construitPlaqueDroite() + "\n\n";
        string commentPlaqueFond = "//Plaque du fond\n";
        string plaqueFond = construitPlaqueFond() + "\n\n";
        string versionOpenscad = Openscad::renvoieEchoVersion() + ";\n\n";

        return versionOpenscad + entete + commentPlaqueBas + plaqueBasEvidee + commentPlaqueHaut + plaqueHaut +
        commentPlaqueGauche + plaqueGauche + commentPlaqueDroite + plaqueDroite +
        commentPlaqueFond + plaqueFond ;
    }

    string GeneBoiteRevues00::construitEntete()
    {
        string texte = Openscad::renvoieCommentGenerator();
        return texte;
    }

    string GeneBoiteRevues00::construitPlaqueBas()
    {
        unsigned int largeurPave = largeur_revues + 2*espacement_gauche + 2*epaisseur_materiau;
        unsigned int profondeurPave = longueur_revues + epaisseur_materiau + espacement_devant;
        string texte = Openscad::renvoiePaveDroit( largeurPave, profondeurPave, epaisseur_materiau);
        return "color(\"red\") " + texte;
    }

    string GeneBoiteRevues00::construitPlaqueBasEvidee()
    {
        string texte =
        Openscad::renvoieDifference() + "\n" +
        "    " + construitPlaqueBas() +";\n" +
        "    " + Openscad::renvoieLinearExtrude(epaisseur_materiau) + "\n" +
        "        " + construitQuadrilatere() + "\n" +
        "    }\n" +
        "}";
        return texte;
    }

    string GeneBoiteRevues00::construitPlaqueHaut()
    {
        string texte = construitPlaqueBas()+";";
        int hauteurTranslation = epaisseur_materiau + hauteur_revues + espacement_haut;
        string texteTranslation = Openscad::renvoieTranslation(0,0,hauteurTranslation);
        return texteTranslation + "\n" + "    " + texte + "\n" + "}";
    }

    string GeneBoiteRevues00::construitPlaqueGauche()
    {
        unsigned int profondeurPave = longueur_revues + epaisseur_materiau + espacement_devant;
        unsigned int hauteurPave = hauteur_revues + espacement_haut;
        string texte = Openscad::renvoiePaveDroit( epaisseur_materiau, profondeurPave, hauteurPave) + ";";
        string texteTranslation = Openscad::renvoieTranslation(0,0,epaisseur_materiau);
        return texteTranslation + "\n" + "    " + texte + "\n" + "}";
    }

    string GeneBoiteRevues00::construitPlaqueDroite()
    {
        unsigned int profondeurPave = longueur_revues + epaisseur_materiau + espacement_devant;
        unsigned int hauteurPave = hauteur_revues + espacement_haut;
        string texte = Openscad::renvoiePaveDroit( epaisseur_materiau, profondeurPave, hauteurPave) + ";";
        string texteTranslation = Openscad::renvoieTranslation(epaisseur_materiau + 2*espacement_gauche + largeur_revues, 0, epaisseur_materiau);
        return texteTranslation + "\n" + "    " + texte + "\n" + "}";
    }

    string GeneBoiteRevues00::construitPlaqueFond()
    {
        unsigned int largeurPave = largeur_revues + 2*espacement_gauche;
        unsigned int hauteurPave = hauteur_revues + espacement_haut;
        string texte = Openscad::renvoiePaveDroit( largeurPave, epaisseur_materiau, hauteurPave) + ";";
        string texteTranslation = Openscad::renvoieTranslation(epaisseur_materiau, espacement_devant + longueur_revues, epaisseur_materiau);
        return texteTranslation + "\n" + "    " + "color(\"blue\") " + texte + "\n" + "}";
    }

    string GeneBoiteRevues00::construitQuadrilatere()
    {
        unsigned int pointMilieu = (2*epaisseur_materiau + largeur_revues + 2*espacement_gauche)/2;
        unsigned int point1x = pointMilieu - largeur_ouverture_bord/2;
        unsigned int point1y = 0;
        unsigned int point2x = pointMilieu + largeur_ouverture_bord/2;
        unsigned int point2y = point1y;
        unsigned int point3x = pointMilieu + largeur_ouverture_sous_revues/2;
        unsigned int point3y = espacement_devant + depassement_ouverture;
        unsigned int point4x = pointMilieu -largeur_ouverture_sous_revues/2;
        unsigned int point4y = point3y;
        return Openscad::renvoieQuadrilatere(point1x, point1y, point2x, point2y, point3x, point3y, point4x, point4y) + ";";
    }

    string GeneBoiteRevues00::construitEvidement()
    {
        return Openscad::renvoieLinearExtrude(epaisseur_materiau) + "\n    " + construitQuadrilatere() + "\n}";
    }

    void GeneBoiteRevues00::setNombre_revues(unsigned int nombre)
    {
        if ( nombre > 100 )
        {
            cerr << "Le nombre dépasse le maxi autorisé : mis à 100" << endl;
            nombre_revues = 100;
        }
        else
            nombre_revues = nombre;
    }
    unsigned int GeneBoiteRevues00::getNombre_revues() const
    {
        return nombre_revues;
    }

    // met la hauteur des revues en mm
    void GeneBoiteRevues00::setHauteur_revues(unsigned int hauteur)
    {
        if ( hauteur > 1000 )
        {
            cerr << "Le nombre dépasse le maxi autorisé : mis à 1000" << endl;
            hauteur_revues = 1000;
        }

        else
            hauteur_revues = hauteur;
    }
    // donne la hauteur des revues en mm
    unsigned int GeneBoiteRevues00::getHauteur_revues() const
    {
        return hauteur_revues;
    }

    // met la largeur des revues en mm
    void GeneBoiteRevues00::setLargeur_revues(unsigned int largeur)
    {
        if ( largeur > 1000 )
        {
            cerr << "Le nombre dépasse le maxi autorisé : mis à 1000" << endl;
            largeur_revues = 1000;
        }

        else
            largeur_revues = largeur;
    }
    // donne la largeur des revues en mm
    unsigned int GeneBoiteRevues00::getLargeur_revues() const
    {
        return largeur_revues;
    }

    // met la longueur des revues en mm
    void GeneBoiteRevues00::setLongueur_revues(unsigned int longueur)
    {
        if ( longueur > 2000 )
        {
            cerr << "Le nombre dépasse le maxi autorisé : mis à 2000" << endl;
            longueur_revues = 1000;
        }

        else
            longueur_revues = longueur;
    }
    // donne la largeur des revues en mm
    unsigned int GeneBoiteRevues00::getLongueur_revues() const
    {
        return longueur_revues;
    }

    // met l'espacement haut en mm
    void GeneBoiteRevues00::setEspacement_gauche(unsigned int espacement)
    {
        if ( espacement > 100 )
        {
            cerr << "Le nombre dépasse le maxi autorisé : mis à 100" << endl;
            espacement_gauche = 100;
        }

        else
            espacement_gauche = espacement;
    }
    // donne la largeur des revues en mm
    unsigned int GeneBoiteRevues00::getEspacement_gauche() const
    {
        return espacement_gauche;
    }

    // met l'espacement haut en mm
    void GeneBoiteRevues00::setEspacement_haut(unsigned int espacement)
    {
        if ( espacement > 100 )
        {
            cerr << "Le nombre dépasse le maxi autorisé : mis à 100" << endl;
            espacement_haut = 100;
        }

        else
            espacement_haut = espacement;
    }
    // donne l'espacement haut en mm
    unsigned int GeneBoiteRevues00::getEspacement_haut() const
    {
        return espacement_haut;
    }

    // met l'espacement devant en mm
    void GeneBoiteRevues00::setEspacement_devant(unsigned int espacement)
    {
        if ( espacement > 100 )
        {
            cerr << "Le nombre dépasse le maxi autorisé : mis à 100" << endl;
            espacement_devant = 100;
        }

        else
            espacement_devant = espacement;
    }
    // donne l'espacement haut en mm
    unsigned int GeneBoiteRevues00::getEspacement_devant() const
    {
        return espacement_devant;
    }

    // met la largeur de l'ouverture bord en mm
    void GeneBoiteRevues00::setLargeur_ouverture_bord(unsigned int ouverture)
    {
        if ( ouverture > 1000 )
        {
            cerr << "Le nombre dépasse le maxi autorisé : mis à 1000" << endl;
            largeur_ouverture_bord = 1000;
        }
        else
            largeur_ouverture_bord = ouverture;
    }
    // donne la largeur de l'ouverture bord en mm
    unsigned int GeneBoiteRevues00::getLargeur_ouverture_bord() const
    {
        return largeur_ouverture_bord;
    }

    // met la largeur de l'ouverture sous revues en mm
    void GeneBoiteRevues00::setLargeur_ouverture_sous_revues(unsigned int ouverture)
    {
        if ( ouverture > 1000 )
        {
            cerr << "Le nombre dépasse le maxi autorisé : mis à 1000" << endl;
            largeur_ouverture_sous_revues = 1000;
        }
        else
            largeur_ouverture_sous_revues = ouverture;
    }
    // donne la largeur de l'ouverture sous revues en mm
    unsigned int GeneBoiteRevues00::getLargeur_ouverture_sous_revues() const
    {
        return largeur_ouverture_sous_revues;
    }

    // met le dépassement de l'ouverture sous revues en mm
    void GeneBoiteRevues00::setDepassement_ouverture(unsigned int depassement)
    {
        if ( depassement > 100 )
        {
            cerr << "Le nombre dépasse le maxi autorisé : mis à 100" << endl;
            depassement_ouverture = 100;
        }
        else
            depassement_ouverture = depassement;
    }
    // donne le dépassement de l'ouverture sous revues en mm
    unsigned int GeneBoiteRevues00::getDepassement_ouverture() const
    {
        return depassement_ouverture;
    }

    // met l'épaisseur du matériau en mm
    void GeneBoiteRevues00::setEpaisseur_materiau(unsigned int nombre)
    {
        if ( nombre > 100 )
        {
            cerr << "Le nombre dépasse le maxi autorisé : mis à 100" << endl;
            epaisseur_materiau = 100;
        }
        else
            epaisseur_materiau = nombre;
    }

    // donne l'épaisseur du matériau en mm
    unsigned int GeneBoiteRevues00::getEpaisseur_materiau() const
    {
        return epaisseur_materiau;
    }

    //met le nom de fichier
    void GeneBoiteRevues00::setNomFichier(string aNomFichier)
    {
        if (aNomFichier.size() >=100)
        {
            cerr << "Le nombre de caractères dépasse le nombre autorisé, mis à \"boite.scad\"" << endl;
            nom_fichier = "boite.scad";
        }

        else nom_fichier = aNomFichier;
    }

    // donne le nom du fichier
    string GeneBoiteRevues00::getNomFichier() const
    {
        return nom_fichier;
    }

    //met le nom du dossier
    void GeneBoiteRevues00::setNomDossier(string aNomDossier)
    {
        if (aNomDossier.size() >=100)
        {
            cerr << "Le nbr de caractères dépasse le nombre autorisé, mis à \"c:\\temp\"";
            nom_dossier_enregistrement = "c:\\temp";
        }

        else nom_dossier_enregistrement = aNomDossier;
    }

    // donne le nom du dossier
    string GeneBoiteRevues00::getNomDossier() const
    {
        return nom_dossier_enregistrement;
    }

    // donne le nom de fichier en entier
    string GeneBoiteRevues00::getNomFichierEntier() const
    {
        return nom_dossier_enregistrement + "\\" + nom_fichier;
    }
