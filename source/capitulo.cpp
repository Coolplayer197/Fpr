// ********************************************
// <Autor> Bjorn Alenjandro Mancio Cruz </Autor>
// <ID> A01634243 </ID>
// ********************************************
#include <iostream>
#include <ctype.h>
#include <string>
#include "Capitulo.h"

Capitulo::Capitulo(std::string id,std::string nombre,std::string duracion,std::string genero,std::string serie,std::string nEpisodio,int calificacion){
    this->id=id;
    this->nombre=nombre;
    this->genero=genero;
    this->calificacion=0;
    this->serie=serie;
    this->tipo=1;
    setNEpisodio(nEpisodio);
    setDuracion(duracion);
}

Capitulo::Capitulo():Capitulo("0","The Hermes Bird","23","thriller","Hell Sing","12",0){}


//setters
void Capitulo::setNEpisodio(std::string nCap){
    int i=0;
    while(i<nCap.size()){
        //verifico que sea un numero
        if(!isdigit(nCap[i])){
            std::cout<<"ingrese unicamente numeros para los episodios:"<<std::endl;
            getline(std::cin,nCap);
            i=-1;
        }
        i++;
    }
    this->nEpisodio=nCap;
}

//getters
std::string Capitulo::getNEpisodio(){
    return this->nEpisodio;
}

std::string Capitulo::getSerie(){
    return this->serie;
}

void Capitulo::imprime(){
    std::cout<<"Nombre: "<<this->nombre<<std::endl;
    std::cout<<"Serie: "<<this->serie<<std::endl;
    std::cout<<"Numero de capitulo: "<<this->nEpisodio<<std::endl;
    std::cout<<"Genero: "<<this->genero<<std::endl;
    std::cout<<"Duracion: "<<this->duracion<<std::endl;
    std::cout<<"Calificacion: "<<this->calificacion<<std::endl;
    std::cout<<"ID: "<<this->id<<std::endl;
}