// ********************************************
// <Autor> Bjorn Alenjandro Mancio Cruz </Autor>
// <ID> A01634243 </ID>
// ********************************************
#ifndef SERIE_H
#define SERIE_H
#include "Capitulo.h"

class Serie{
    public:
        std::string nombre;//funciona como id
        Capitulo* capitulos;
        int numeroCaps;//contador de capitulos 
    public:
        //construtores
        Serie();
        Serie(std::string,Capitulo);
        //getters
        Capitulo* getCapitulos();
        std::string getSNombre();
        //funciones
        void addCapitulo(Capitulo);
        //imprime capitulos con una calificacion dada
        void imprimeCapitulos(int);
};

#endif