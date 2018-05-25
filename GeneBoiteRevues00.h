// header pour la classe du g�n�rateur de bo�tes
#include <string>

class GeneBoiteRevues00
{
public:
    GeneBoiteRevues00();

    // demande les param�tres � l'utilisateur
    void demanderParametres();

    //donne un r�capitulatif des param�tres entr�s
    void afficheRecapitulatif();

    //construit le texte openscad
    std::string construitBoite();

    //construit l'ent�te
    std::string construitEntete();

    //construit la plaque du bas;
    std::string construitPlaqueBas();

    //construit la plaque du haut;
    std::string construitPlaqueHaut();

    //construit la plaque gauche;
    std::string construitPlaqueGauche();

    //construit la plaque droite;
    std::string construitPlaqueDroite();

    //construit la plaque du fond;
    std::string construitPlaqueFond();

    //construit le quadrilat�re pour l'�videment
    std::string construitQuadrilatere();

    //construit l'extrusion pour le quadrilat�re
    std::string construitEvidement();

    //construit la plaque du bas evidee
    std::string construitPlaqueBasEvidee();

    // met le nombre de revues
    void setNombre_revues(unsigned int);
    // donne le nombre de revues
    unsigned int getNombre_revues() const;

    // met la hauteur des revues en mm
    void setHauteur_revues(unsigned int);
    // donne la hauteur des revues en mm
    unsigned int getHauteur_revues() const;

    // met la largeur des revues en mm
    void setLargeur_revues(unsigned int);
    // donne la largeur des revues en mm
    unsigned int getLargeur_revues() const;

    // met la longueur des revues en mm
    void setLongueur_revues(unsigned int);
    // donne la longueur des revues en mm
    unsigned int getLongueur_revues() const;

    // met l'espacement gauche en mm
    void setEspacement_gauche(unsigned int);
    // donne l'espacement gauche en mm
    unsigned int getEspacement_gauche() const;

    // met l'espacement haut en mm
    void setEspacement_haut(unsigned int);
    // donne l'espacement haut en mm
    unsigned int getEspacement_haut() const;

    // met l'espacement devant en mm
    void setEspacement_devant(unsigned int);
    // donne l'espacement devant en mm
    unsigned int getEspacement_devant() const;

    // met la largeur de l'ouverture bord en mm
    void setLargeur_ouverture_bord(unsigned int);
    // donne la largeur de l'ouverture bord en mm
    unsigned int getLargeur_ouverture_bord() const;

    // met la largeur de l'ouverture sous revues en mm
    void setLargeur_ouverture_sous_revues(unsigned int);
    // donne la largeur de l'ouverture sous revues en mm
    unsigned int getLargeur_ouverture_sous_revues() const;

    // met le d�passement de l'ouverture sous revues en mm
    void setDepassement_ouverture(unsigned int);
    // donne le d�passement de l'ouverture sous revues en mm
    unsigned int getDepassement_ouverture() const;

    // met l'�paisseur materiau en mm
    void setEpaisseur_materiau(unsigned int);
    // donne l'�paisseur mat�riau en mm
    unsigned int getEpaisseur_materiau() const;

    //met nom fichier
    void setNomFichier(std::string);
    //donne nom fichier
    std::string getNomFichier() const;

    //met nom dossier
    void setNomDossier(std::string);
    //donne nom dossier
    std::string getNomDossier() const;

    //donne le nom de fichier en entier
    std::string getNomFichierEntier() const;





private:

    //le nombre de revues
    unsigned int nombre_revues;

    //hauteur des revues en mm
    unsigned int hauteur_revues;

    //largeur des revues en mm
    unsigned int largeur_revues;

    //longueur des revues en mm
    unsigned int longueur_revues;

    //espacement � gauche en mm(le m�me qu'� droite)
    unsigned int espacement_gauche;

    //espacement en haut en mm
    unsigned int espacement_haut;

    //espacement devant en mm
    unsigned int espacement_devant;

    //largeur ouverture bord en mm
    unsigned int largeur_ouverture_bord;

    //largeur ouverture sous revues en mm
    unsigned int largeur_ouverture_sous_revues;

    //d�passement ouverture sous revue en mm
    unsigned int depassement_ouverture;

    //epaisseur materiau en mm
    unsigned int epaisseur_materiau;

    //largeur maxi boite en mm
    unsigned int largeur_max_boite;

    //profondeur maxi boite en mm
    unsigned int profondeur_max_boite;

    //nom du dossier o� enregistrer les fichiers (sans espace ni caract�res accentu�s)
    std::string nom_dossier_enregistrement;

    //nom du fichier
    std::string nom_fichier;
};
