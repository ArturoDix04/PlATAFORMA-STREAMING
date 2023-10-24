#ifndef Serie_h
#define Serie_h
#include <string>
using namespace std;
#include <iostream>
#include "Episodio.h"

class Serie {
  public:
  Serie();
  Serie(int id, string titulo);
  void setTitulo (string  titulo) { this->titulo = titulo; };
  string  getTitulo() { return titulo; };
  void setId(double id) { this->id = id; };
  int getId() { return id; };
  bool agregarEpisodio (Episodio *episodio);
  void mostrar();
  

  private:
  int id, cantEpisodios;
  string titulo;
  Episodio *listaEpisodios[50];
  Episodio *episodios;

};

Serie:: Serie (){
  id = 0;
  titulo = "";
  cantEpisodios = 0;
}

Serie::Serie(int id , string titulo){
  this->id= id;
  this-> titulo= titulo;
  cantEpisodios = 0;
  
}

bool Serie::agregarEpisodio(Episodio *episodio){
  if (cantEpisodios < 50){
    listaEpisodios[cantEpisodios++]= episodio;
    return true;
  }
  else{
    return false;
  }
}


void Serie::mostrar()
{
    cout << "Titulo de la serie : " << titulo << "\t";
    for (int i=0; i< cantEpisodios  ; i++){
      listaEpisodios[i]->mostrar();
    }
}

/*
void Serie::mostrarSeries(double calificacion)
{
    cout << "Titulo de la serie : " << titulo << "\t";
    cout << "' con calificación " << calificacion << ":" << endl;
   
  for ( int i=0; i< cantEpisodios  ; i++) {
      if ( episodios->getCalificacion() == calificacion) {
        listaEpisodios[i]->mostrar();
      }
    }
}
*/

#endif /*Serie.h*/
