// ********************************************
// <Autor> Bjorn Alenjandro Mancio Cruz </Autor>
// <ID> A01634243 </ID>
// ********************************************
#include <vector>
#include <iostream>
#include <string>
#include <ctype.h>
#include <fstream>
#include <stdlib.h>
#include "Netflix.h"
#include "Video.h"
#include "Pelicula.h"
#include "Capitulo.h"

using namespace std;

void Netflix::imprimeMenu(){
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"+ Presione 1 para cargar archivo........................................+"<<endl;
    cout<<"+ Presione 2 para mostrar todos los videos con cierta calificacion......+"<<endl;
    cout<<"+ Presione 3 para mostrar capitulos de una serie con una calificacion...+"<<endl;
    cout<<"+ Presione 4 para mostrar peliculas con cierta calificacion.............+"<<endl;
    cout<<"+ Presione 5 para calificar un video....................................+"<<endl;
    cout<<"+ Presione 0 para salir :'(.............................................+"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"Seleccione una opcion:"<<endl;
}

bool Netflix::valifnum0to5(string s){
    bool b;
    //verifico que su longitud no sea mayor a 1
    if(s.size()>1){
        return false;
    }else{
        //verifico que sea un numero
        int x;
        x=s[0];

        if(x>47 && x<58){
            b=true;
        }else{
            b=false;
        }
    }
    return b;
}

void Netflix::ponlePlay(){
    //declaro variables que necesitare
    fstream archivo;
    vector<Video*> videos;
    string opcion;
    string calificacion;
    int cal;
    bool verificador=false;
    //declaro las variables en donde guardare la informacion
    string dato;
    string datos[6];

    //comienzo el programa
    while(true){
        //imprimo el menu y pido la opcion que quiera seleccionar
        imprimeMenu();
        cin>>opcion;

        //verifico que sean valores dentro del rango
        while(!valifnum0to5(opcion)){
            cout<<"Por favor ingrese solo los numeros de las opciones:"<<endl;
            cin>>opcion;
        }

        switch(opcion[0]){
            case '0':
                cout<<"gracias por usar el programa XD";
                exit(0);
                break;
            case '1':
                archivo.open("formatoArchivo.txt",ios::in);

                //verifico si pudo abrir el archivo correctamente
                if(archivo.fail()){
                    cout<<"Error"<<endl;
                    cout<<"error al cargar el archivo."<<endl;
                    cout<<"puede que no haya incluido el archivo en fichero, tenga otro nombre"<<endl;
                    cout<<"o sea otro tipo de archivo.";
                    break;
                }else{
                    getline(archivo,dato);
                    getline(archivo,dato);
                    while(getline(archivo,dato,',')){
                        //verifico que tipo de dato es
                        //caso de que sea pelicula
                        if(dato=="p"){
                            //guardo mis datos
                            for(int i=0;i<3;i++){
                                getline(archivo,dato,',');
                                datos[i]=dato;
                            }
                            getline(archivo,dato);
                            datos[3]=dato;
                            //agrego la pelicula a videos
                            Pelicula* p=new Pelicula(datos[0],datos[1],datos[2],datos[3],0);
                            videos.push_back(p);
                            //caso de que sea capitulo
                        }else if(dato=="c"){
                            //guardo mis datos
                            for(int i=0;i<5;i++){
                                getline(archivo,dato,',');
                                datos[i]=dato;
                            }
                            getline(archivo,dato);
                            datos[5]=dato;
                            //agrego la serie a videos
                            Capitulo* c=new Capitulo(datos[0],datos[1],datos[2],datos[3],datos[4],datos[5],0);
                            videos.push_back(c);
                        }
                    }
                    system("CLS");
                    cout<<"---------------------------"<<endl;
                    cout<<"datos cargados exitosamente"<<endl;
                    cout<<"---------------------------"<<endl;
                    cout<<endl;
                }
                break;
            case '2':
                verificador=false;
                //pido los datos al usuario
                cout<<"Escriba la calificacion de los videos:"<<endl;
                cin>>calificacion;

                //verifico que sean valores dentro del rango
                while(!valifnum0to5(calificacion)){
                    cout<<"Por favor ingrese solo los numeros del 0 al 5:"<<endl;
                    cin>>calificacion;
                }

                system("CLS");
                //convierto la calificacion validada en int
                cal=stoi(calificacion);

                //verifico si hay datos
                if(!videos.empty()){
                    //imprimo los datos
                    for(int i=0;i<videos.size();i++){
                        if(videos[i]->getCalificacion()==cal){
                            verificador=true;
                            videos[i]->imprime();
                            cout<<"------------------------------"<<endl;
                        }
                    }

                    //verifico si existen videos con la calificacion seleccionada
                    if(verificador==false){
                        system("CLS");
                        cout<<"-------------------------------------------------"<<endl;
                        cout<<"No se encontro ningun video con esa calificacion."<<endl;
                        cout<<"-------------------------------------------------"<<endl;
                        cout<<endl;
                    }
                }else{
                    system("CLS");
                    cout<<"---------------------------------------------------------------"<<endl;
                    cout<<"No se encontro ningun video. asegurese de cargar datos primero."<<endl;
                    cout<<"---------------------------------------------------------------"<<endl;
                    cout<<endl;
                }
                break;
            case '3':
                verificador=false;
                //verifico si el arreglo esta vacio
                if(!videos.empty()){
                    //pido la serie y las imprimo
                    cout<<"seleccione una serie:"<<endl;
                    cout<<endl;

                    for(int i=0;i<videos.size();i++){
                        if(videos[i]->getTipo()==1){
                            verificador=true;
                            cout<<videos[i]->getSerie()<<endl;
                            cout<<"------------------------------"<<endl;
                        }
                    }

                    //notifico si no hay series
                    if(verificador==false){
                        system("CLS");
                        cout<<"------------------------------------------------------"<<endl;
                        cout<<"No se encontro ninguna serie.Agregue series al archivo"<<endl;
                        cout<<"------------------------------------------------------"<<endl;
                        cout<<endl;
                        break;
                    }

                    //pido la serie y la calificaion
                    cin.ignore();
                    cout<<"escriba el nombre de la serie:"<<endl;
                    getline(cin,opcion);
                    cout<<"escriba la calificacion:"<<endl;
                    cin>>calificacion;

                    //valido la calificacion
                    while(!valifnum0to5(calificacion)){
                        cout<<"Por favor ingrese solo los numeros del 0 al 5:"<<endl;
                        cin>>calificacion;
                    }

                    //convierto calificacion a int
                    cal=stoi(calificacion);
                    verificador=false;

                    //hago la consulta
                    //verifico que haya una serie con ese nombre y que tenga la calificasion
                    for(int i=0;i<videos.size();i++){
                        if(videos[i]->getTipo()==1){
                            if(videos[i]->getSerie()==opcion && videos[i]->getCalificacion()==cal){
                                verificador=true;
                                cout<<"------------------------------------------------------"<<endl;
                                videos[i]->imprime();
                                cout<<endl;
                            }
                        }
                    }
                        
                    if(verificador==false){
                        system("CLS");
                        cout<<"----------------------------------------------------------------"<<endl;
                        cout<<"No existe alguna serie con esa calificacion o no exise la serie."<<endl;
                        cout<<"----------------------------------------------------------------"<<endl;
                        cout<<endl;
                    }

                }else{
                    system("CLS");
                    cout<<"---------------------------------------------------------------"<<endl;
                    cout<<"No se encontro ningun video. asegurese de cargar datos primero."<<endl;
                    cout<<"---------------------------------------------------------------"<<endl;
                    cout<<endl;
                }
                break;
            case '4':
                verificador=false;
                //verifico si el arreglo esta vacio
                if(!videos.empty()){
                    cout<<"escriba la calificacion de las peliculas:"<<endl;
                    cin>>calificacion;

                    //valido la calificacion
                    while(!valifnum0to5(calificacion)){
                        cout<<"Por favor ingrese solo los numeros del 0 al 5:"<<endl;
                        cin>>calificacion;
                    }

                    system("CLS");
                    cal=stoi(calificacion);      

                    for(int i=0;i<videos.size();i++){
                        if(videos[i]->getTipo()==0 && videos[i]->getCalificacion()==cal){
                            verificador=true;
                            videos[i]->imprime();
                            cout<<"-------------------------------------------------------"<<endl;
                        }
                    }

                    //notifico si no hay peliculas con esa calificacion
                    if(verificador==false){
                        system("CLS");
                        cout<<"---------------------------------------------------------------"<<endl;
                        cout<<"No existen peliculas, o peliculas con esa calificacion."<<endl;
                        cout<<"---------------------------------------------------------------"<<endl;
                        cout<<endl;
                    }              
                }else{
                    system("CLS");
                    cout<<"---------------------------------------------------------------"<<endl;
                    cout<<"No se encontro ningun video. asegurese de cargar datos primero."<<endl;
                    cout<<"---------------------------------------------------------------"<<endl;
                    cout<<endl;
                }
                break;
            case '5':
                verificador=false;
                //verifico si el arreglo esta vacio
                if(!videos.empty()){
                    cout<<"seleccione un video:"<<endl;

                    //imprimo todos los videos
                    for(int i=0;i<videos.size();i++){
                        videos[i]->imprime();
                        cout<<"---------------------------------"<<endl;
                    }

                    //pido la calificacion y el titulo a calificar
                    cout<<"Escriba el nombre del video a calificar.Puede ser el nombre de una pelicula o el nombre del episodio de una seire:"<<endl;
                    cin.ignore();
                    getline(cin,opcion);
                    cout<<"Escriba la calificacion para el titulo:"<<endl;
                    cin>>calificacion;

                    //valido calificacion y la transformo a int
                    while(!valifnum0to5(calificacion)){
                        cout<<"Por favor ingrese solo los numeros del 0 al 5:"<<endl;
                        cin>>calificacion;
                    }
                    cal=stoi(calificacion);

                    //hago la consulta y realizo la operacion
                    for(int i=0;i<videos.size();i++){
                        if(videos[i]->getNombre()==opcion){
                            verificador=true;
                            *videos[i]+cal;
                            break;
                        }
                    }

                    //notifico si no hay videos con ese titulo 
                    if(verificador==false){
                        system("CLS");
                        cout<<"---------------------------------------------------------------"<<endl;
                        cout<<"No existen videos con ese titulo."<<endl;
                        cout<<"---------------------------------------------------------------"<<endl;
                        cout<<endl;
                    }else{
                        system("CLS");
                        cout<<"--------------------------------"<<endl;
                        cout<<"Video calificado exitosamenteXD."<<endl;
                        cout<<"--------------------------------"<<endl;
                        cout<<endl;
                    }
                }else{
                    system("CLS");
                    cout<<"---------------------------------------------------------------"<<endl;
                    cout<<"No se encontro ningun video. asegurese de cargar datos primero."<<endl;
                    cout<<"---------------------------------------------------------------"<<endl;
                    cout<<endl;
                }
                break;        
        }  
    }
}