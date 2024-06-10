// ********************************************
// <Autor> Bjorn Alenjandro Mancio Cruz </Autor>
// <ID> A01634243 </ID>
// ********************************************
#include <iostream>
#include <ctype.h>
#include <string>
#include "Video.h"

//declaraciones
//geters:
std::string Video::getId(){
    return this->id;
}

std::string Video::getDuracion(){
    return this->duracion;
}

int Video::getCalificacion(){
    return this->calificacion;
}

std::string Video::getNombre(){
    return this->nombre;
}

std::string Video::getGenero(){
    return this->genero;
}

int Video::getTipo(){
    return this->tipo;
}

//setters
void Video::setId(std::string id){
    this->id=id;
}

void Video::setNombre(std::string nombre){
    this->nombre=nombre;
}

void Video::setDuracion(std::string duracion){
    int i=0;
    while(i<duracion.size()){
        //verifico que sea un numero
        if(!isdigit(duracion[i])){
            std::cout<<"ingrese unicamente numeros mayores que 0 para la duracion:"<<std::endl;
            getline(std::cin,duracion);
            i=-1;
        }

        //verifico que sea mayor que 0
        if(duracion[0]=='0'){
            std::cout<<"ingrese unicamente numeros mayores que 0 para la duracion:"<<std::endl;
            getline(std::cin,duracion);
            i=-1;
        }
        i++;  
    }
    this->duracion=duracion;
}

void Video::setGenero(std::string genero){
    this->genero=genero;
}

void Video::setCalificacion(int calificacion){
    this->calificacion=calificacion;
}

//operador sobrecargado
void Video::operator+(int x){
    setCalificacion(x);
}