// ********************************************
// <Autor> Bjorn Alenjandro Mancio Cruz </Autor>
// <ID> A01634243 </ID>
// ********************************************
#ifndef CAPITULO_H
#define CAPITULO_H
#include "Video.h"
#include <iostream>

class Capitulo:public Video{
    private:
        std::string nEpisodio;
        std::string serie;
    public:
        //constructores
        Capitulo();
        Capitulo(std::string,std::string,std::string,std::string,std::string,std::string,int);
        //funciones
        void imprime();
        //getters
        std::string getNEpisodio();
        std::string getSerie();
        //settersepisodio
        void setNEpisodio(std::string);
};

#endif