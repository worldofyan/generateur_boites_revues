//Openscad class implementation
#include <iostream>
#include <string>
#include "Openscad.h"

using namespace std;
    const std::string Openscad::GENERATOR_NAME = "Générateur de boîtes de revues";
    const std::string Openscad::CODE_OPEN_SCAD = "Code pour OpenScad 2015.03-2";
    const std::string Openscad::GENERATOR_WEB = "hardhackers.com";
    const std::string Openscad::GENERATOR_VERSION = "1";
    const std::string Openscad::ECHO_OPENSCAD_VERSION = "version=version()";

    Openscad::Openscad()
    {

    }
    string Openscad::renvoieEchoVersion()
    {
        string texte = "echo(" + Openscad::ECHO_OPENSCAD_VERSION + ")";
        return texte;
    }

    string Openscad::renvoieCommentGenerator()
    {
        string texte = "//" + Openscad::GENERATOR_NAME + " : version " + Openscad::GENERATOR_VERSION + "\n";
        string texte2 = "//Par : " + Openscad::GENERATOR_WEB + "\n";
        string texte3 = "//" + Openscad::CODE_OPEN_SCAD;
        return texte + texte2 + texte3;
    }

    string Openscad::renvoiePaveDroit(unsigned int largeur, unsigned int profondeur, unsigned int hauteur)
    {
        string texte = "cube([" + to_string(largeur) + "," + to_string(profondeur) + "," + to_string(hauteur) + "])";
        return texte;
    }

    string Openscad::renvoieQuadrilatere(
                                         unsigned int point1x, unsigned int point1y,
                                         unsigned int point2x, unsigned int point2y,
                                         unsigned int point3x, unsigned int point3y,
                                         unsigned int point4x, unsigned int point4y)
    {
        string texte =
        " polygon([[" +
        to_string(point1x) + "," + to_string(point1y) + "],[" +
        to_string(point2x) + "," + to_string(point2y) + "],[" +
        to_string(point3x) + "," + to_string(point3y) + "],[" +
        to_string(point4x) + "," + to_string(point4y) +
        "]])";
        return texte;
    }

    string Openscad::renvoieDifference()
    {
        string texte = "difference(){";
        return texte;
    }

    string Openscad::renvoieTranslation(int x, int y, int z)
    {
        string texte = "translate([" + to_string(x) + "," + to_string(y) + "," + to_string(z) + "])\n{";
        return texte;
    }

    string Openscad::renvoieLinearExtrude(int height)
    {
        string texte = "linear_extrude(height=" + to_string(height) + "){";
        return texte;
    }
