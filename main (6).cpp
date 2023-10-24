#include <iostream>
using namespace std;
#include <fstream>
#include <iostream>
#include <string.h>

#include "Pelicula.h"
#include "Episodio.h"
#include "Serie.h"

int main() {

  int id, duracion, opcion = 10;
  double calificacion;
  string nombre, genero, nombreserie, temporada, numEpisodio;
  Video *listaVideos[500];
  Serie *listaSeries[500];
  Episodio *unEpisodio;
  int cantVideos = 0,cont=0, cantSeries=0;

  char tipoVideo;
  ifstream archvideo;
  ifstream archserie;
  archvideo.open("datosVideos.txt");
  archserie.open("datosSeries.txt");


  while (opcion != 0) {
    cout << "1) Cargar archivo de datos" << endl;
    cout << "2) Mostrar la lista de peliculas" << endl;
    cout << "3) Mostrar la lista de series con sus episodios" << endl;
    cout << "4) Mostrar los videos en general con una cierta calificación o de "
            "un cierto genero"
         << endl;
    cout << "5) Mostrar los episodios de una determinada serie con una "
            "calificación determinada"
         << endl;
    cout << "6) Mostrar las películas con cierta calificación" << endl;
    cout << "7) Califica un video" << endl;
    cout << "0) Salir" << endl;

    cin >> opcion;

    
    if (opcion == 1) {
      while (archserie >> id){
        archserie >> nombreserie;
        listaSeries[cantSeries++] = new Serie (id,nombreserie);
      }
  
      
      while (archvideo >> tipoVideo) {
        if (tipoVideo == 'p') {
      
        archvideo >> id >> nombre >> genero >> duracion >> calificacion;
      
        listaVideos[cantVideos++] = new Pelicula(id, nombre, genero, duracion,   calificacion);

        } else{

        archvideo >> id >> nombre >> genero >> duracion >> calificacion >> nombreserie >> temporada >> numEpisodio;
      
        listaVideos[cantVideos++] = new Episodio(id, nombre, genero,             duracion,calificacion,nombreserie,temporada,numEpisodio);

   int i = 0;
while (i < cantSeries) {
  if (listaSeries[i]->getTitulo() == nombreserie) {
 listaSeries[i]->agregarEpisodio((Episodio*)listaVideos[cantVideos-1]);
    
    //if //(!listaSeries[i]->agregarEpisodio(((Episodio*)listaVideos[i]))) {
     // cout <<"No se pueden agregar más episodios"<<endl;
    //}
  }
  i = i + 1; // Incrementar el valor de i
}
      
      
    }
  }
  archvideo.close();
  archserie.close();
  
    } else if (opcion == 2) {

      for (int i = 0; i < cantVideos; i++) {
      if (typeid(*listaVideos[i]) == typeid(Pelicula))
      listaVideos[i]->mostrar();
        cout << endl;
}
    

    } else if (opcion == 3) {
      //for (int i = 0; i < cantVideos; i++) {
        for (int i = 0; i < cantSeries; i++) {
      if (typeid(*listaSeries[i]) == typeid(Serie))
      listaSeries[i]->mostrar(); 
        cout <<endl;
      }

        
    } else if (opcion == 4) {
      
    double rating,calif;
    char preferencia;
    string buscagenero, busqueda;
      
    cout << "¿Quiéres buscar por calificación o género? (c/g)"<< endl;
    cin >> preferencia;
      
    if (preferencia == 'c'){
    cout << "Inserta con que calificacion quieres ver los videos"<<endl;
    cin >> calif;
          
        for (int c = 0; c < cantVideos; c++)
    {
        rating = listaVideos[c]->getCalificacion();
        if (rating == calif) {
        listaVideos[c]->mostrar();
        cout << endl;  
        }
    }
    }
    else if (preferencia == 'g'){
      cout<<"Inserta el género que deseas buscar: Accion, Drama, Musical, Ciencia_ficcion, Comedia"<<endl;
      cin >> buscagenero;

      for (int c = 0; c<cantVideos;c++){
        busqueda = listaVideos[c]->getGenero();
        if (busqueda == buscagenero){
          listaVideos[c]->mostrar();
          cout<<endl;
        }
      }
        
    }

    } else if (opcion == 5) {
        string busquedaserie,busqueda2;
        double califepi, busquedacalif;
      
        cout<<"Inserta la serie que deseas ver (S,H,F): "<<endl;
        cin >> busquedaserie;
        cout<<"Calificación de episodio: ";
        cin >> califepi;
        if (busquedaserie =="S")
          busquedaserie = "Stranger_things";
        else if (busquedaserie == "H")
          busquedaserie = "How_I_met_your_mother";
        else if (busquedaserie == "F")
          busquedaserie = "Friends";
        else
          cout<<"No se encuentra esa serie en el sistema"<<endl;
      
       for (int c = 0; c < cantVideos; c++) {
  if (typeid(*listaVideos[c]) == typeid(Episodio)) {
    Episodio* episodio = (Episodio*)(listaVideos[c]);
    if (episodio->getNombreserie() == busquedaserie && episodio->getCalificacion() == califepi) {
      episodio->mostrar();
      cout << endl;
    }
  }
}
    } else if (opcion == 6) {

      double peliculaCalificacion,calif;
    cout << "Inserta con que calificacion quieres ver la pelicula"<<endl;
    cin >> calif;
          
        for (int c = 0; c < cantVideos; c++)
    {
          peliculaCalificacion = listaVideos[c]->getCalificacion();
        if (peliculaCalificacion == calif && typeid(*listaVideos[c]) == typeid(Pelicula)) {
           listaVideos[c]->mostrar();
        cout << endl;  
        }
    }
      

    } else if (opcion == 7) {

      int idVideo;
  double nuevaCalificacion;

  cout << "Ingresa el ID del video que deseas calificar: ";
  cin >> idVideo;

  bool encontrado = false;
  for (int c = 0; c < cantVideos; c++) {
    if (listaVideos[c]->getId() == idVideo) {
      encontrado = true;
      cout << "Ingresa la nueva calificación para el video: ";
      cin >> nuevaCalificacion;
      listaVideos[c]->setCalificacion(nuevaCalificacion);
      cout << "Calificación actualizada con éxito." << endl;
      break;
    }
  }

  if (!encontrado) {
    cout << "No se encontró ningún video con el ID especificado." << endl;
  }



      
    }
  }
  return 0;
}