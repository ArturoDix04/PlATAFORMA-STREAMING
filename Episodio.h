#ifndef Episodio_h
#define Episodio_h
#include <string>
using namespace std;
#include <iostream>
#include "Video.h"

class Episodio: public Video{
    public:
        Episodio();
        Episodio(int id, string nombre, string genero, int duracion, double calificacion, string nombreserie, string numEpisodio, string temporada);
        void mostrar();
 void setNombreserie (string nombreserie) { this->nombreserie = nombreserie; };
  string getNombreserie() { return nombreserie; };
  void setTemporada(string temporada) { this->temporada = temporada; };
  string getTemporada() { return temporada; };

  void setNumepisodio(string numEpisodio) { this->numEpisodio = numEpisodio; };
  string getNumepisodio() { return numEpisodio; };

    private:
        string nombreserie,temporada,numEpisodio;

 
 } ;



 Episodio::Episodio():Video(){
     this->nombreserie = "";
     this->temporada= "";
     this->numEpisodio= "";
}

Episodio::Episodio(int id, string nombre, string genero, int duracion, double calificacion, string nombreserie, string numEpisdio, string temporada):Video(id,nombre,genero,duracion,calificacion){
  
    this->nombreserie = nombreserie;
    this->temporada= temporada;
  
    this-> numEpisodio= numEpisdio;
}

void Episodio::mostrar()
{
    cout << "ID: " << id << "\t";
    cout << "Nombre: " << nombre << endl;
    cout << "Duracion: " << duracion << "\t";
    cout << "Genero: " << genero << "\t";
    cout << "Calificacion: " << calificacion << endl;
    cout << "Nombre serie: " << nombreserie <<endl;
  cout <<"Episodio: "<<numEpisodio<<endl;
    cout << "Temporada: "<<temporada<<endl;
    

}

#endif /*Episodio.h*/