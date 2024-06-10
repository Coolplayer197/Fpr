// ********************************************
// <Autor> Bjorn Alenjandro Mancio Cruz </Autor>
// <ID> A01634243 </ID>
// ********************************************
#ifndef PELICULA_H
#define PELICULA_H
#include "Video.h"

class Pelicula:public Video{
    public:
        //contructores
        Pelicula();
        Pelicula(std::string,std::string,std::string,std::string,int);
        //funciones
        void imprime();
        std::string getSerie();
};

#endif