// ********************************************
// <Autor> Vicente Javier Viera Guízar </Autor>
// <ID> A01639784 </ID>
// <version> 1.12.20.7 </version>
// ********************************************
#include <iostream>
#include "Pelicula.h"

//declaraciones:

//contrucores
Pelicula::Pelicula(std::string id,std::string nombre,std::string duracion,std::string genero,int calificacion){
    this->id=id;
    this->nombre=nombre;
    this->genero=genero;
    this->calificacion=0;
    this->tipo=0;
    setDuracion(duracion);
}

Pelicula::Pelicula():Pelicula("0a0a0a0a0","Cerapio La Lagartija de Alicanto","23","Drama",0){}

//imprimir datos de la pelicula
void Pelicula::imprime(){
    std::cout<<"Nombre: "<<this->nombre<<std::endl;
    std::cout<<"Genero: "<<this->genero<<std::endl;
    std::cout<<"Duracion: "<<this->duracion<<std::endl;
    std::cout<<"Calificacion: "<<this->calificacion<<std::endl;
    std::cout<<"ID: "<<this->id<<std::endl;
}

//regresa 0 por que no es serie
std::string Pelicula::getSerie(){
    return "0";
}