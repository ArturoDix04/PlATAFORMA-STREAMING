#ifndef Pelicula_h
#define Pelicula_h
#include <string>
using namespace std;
#include <iostream>
#include "Video.h"

class Pelicula : public Video  {
    public:
        Pelicula();
        Pelicula(int id, string nombre, string genero, int duracion, double calificacion);
        void mostrar();
 } ;

Pelicula::Pelicula():Video(){
}

Pelicula::Pelicula(int id, string nombre, string genero, int duracion, double calificacion):Video(id,nombre,genero,duracion,calificacion){
}

void Pelicula::mostrar()
{
    cout << "ID: " << id << "\t";
    cout << "Nombre: " << nombre << endl;
    cout << "Duracion: " << duracion << "\t";
    cout << "Genero: " << genero << "\t";
    cout << "Calificacion: " << calificacion << endl;

}

#endif /*Pelicula.h*/