#ifndef Video_h
#define Video_h
#include <string>
using namespace std;
#include <iostream>

class Video{
  public:
  Video();
  Video(int id, string nombre, string genero, int duracion, double calificacion);

  void setId (int id) { this->id = id; };
  int getId() { return id; };
  void setNombre(double nombre) { this->nombre = nombre; };
  string getNombre() { return nombre; };
  void setDuracion(double duracion) { this->duracion = duracion; };
  double getDuracion() { return duracion; };
  void setGenero(double genero) { this->genero = genero; };
  string getGenero() { return genero; };
  void setCalificacion(double calificacion) { this->calificacion = calificacion; };
  double getCalificacion() { return calificacion; };
  virtual void mostrar()=0;

  protected:
  int id,duracion;
  string nombre, genero;
  double calificacion;
};

Video::Video(){
      id=0;
      duracion=0;
      nombre="";
      genero="";
      calificacion=0;
}
Video::Video(int id, string nombre, string genero, int duracion, double calificacion)
{
    this->id = id;
    this->nombre = nombre;
    this->duracion = duracion;
    this->genero = genero;
    this->calificacion = calificacion;

}

#endif /*Video.h*/
