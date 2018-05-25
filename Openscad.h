//Openscad class header
#include <string>

class Openscad
{
    static const std::string GENERATOR_NAME;
    static const std::string GENERATOR_WEB;
    static const std::string GENERATOR_VERSION;
    static const std::string CODE_OPEN_SCAD;
    static const std::string ECHO_OPENSCAD_VERSION;

public:
    static std::string renvoieCommentGenerator();
    static std::string renvoiePaveDroit(unsigned int, unsigned int, unsigned int);
    static std::string renvoieQuadrilatere(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    static std::string renvoieTranslation(int, int, int);
    static std::string renvoieEchoVersion();
    static std::string renvoieDifference();
    static std::string renvoieLinearExtrude(int);
    const std::string PRIMITIVE_CUBE = "cube";

    Openscad();


private:

};
