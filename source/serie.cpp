// ********************************************
// <Autor> Bjorn Alenjandro Mancio Cruz </Autor>
// <ID> A01634243 </ID>
// ********************************************
#include <iostream>
#include "Serie.h"
#include "Capitulo.h"

//constructores
Serie::Serie(){
    this->nombre="";
    this->capitulos=new Capitulo[2];
    this->numeroCaps=0;
}

Serie::Serie(std::string nombre,Capitulo c){
    this->nombre=nombre;
    this->capitulos=new Capitulo[2];
    this->numeroCaps=0;
    this->capitulos[numeroCaps]=c;
}

//getters
Capitulo* Serie::getCapitulos(){
    return this->capitulos;
}

std::string Serie::getSNombre(){
    return this->nombre;
}

//setters
void Serie::addCapitulo(Capitulo c){
    std::cout<<"entre";
    this->numeroCaps++;
    this->capitulos[numeroCaps]=c;
    std::cout<<"sali";
}

void Serie::imprimeCapitulos(int calificacion){
    int tamano=sizeof(this->capitulos)/sizeof(this->capitulos[0]);
    for(int i=0;i<tamano;i++){
        if(this->capitulos[i].getCalificacion()==calificacion){
            this->capitulos[i].imprime();
            std::cout<<"---------------------------------------------------------"<<std::endl;
        }
    }
}