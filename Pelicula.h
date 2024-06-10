// ********************************************
// <Autor> Vicente Javier Viera Guízar </Autor>
// <ID> A01639784 </ID>
// <version> 1.12.20.7 </version>
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