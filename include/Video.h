// ********************************************
// <Autor> Bjorn Alenjandro Mancio Cruz </Autor>
// <ID> A01634243 </ID>
// ********************************************
#ifndef VIDEO_H
#define VIDEO_H

class Video{
    protected:
        std::string id;
        std::string nombre;
        std::string genero;
        std::string duracion;
        int calificacion;
        int tipo;
    public:
        //funciones
        virtual void imprime()=0;

        //operador sobrecargado
        void operator+(int);
        //getters
        std::string getId();
        std::string getNombre();
        std::string getDuracion();
        std::string getGenero();
        int getCalificacion();
        int getTipo();
        virtual std::string getSerie()=0;
        //setters
        void setId(std::string);
        void setNombre(std::string);
        void setDuracion(std::string);
        void setGenero(std::string);
        void setCalificacion(int);
};

#endif