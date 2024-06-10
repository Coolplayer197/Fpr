// ********************************************
// <Autor> Vicente Javier Viera Guízar </Autor>
// <ID> A01639784 </ID>
// <version> 1.12.20.7 </version>
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