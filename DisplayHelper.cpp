#include "DisplayHelper.hpp"
using namespace std;

void DisplayHelper::limpiarPantalla(){
  system ("cls");
}

void DisplayHelper::mostrarBienvenida(){
  cout<< "    SISTEMA DE PELICULAS   "<< endl;
}
void DisplayHelper::mostrarMenuPrincipal(){
  cout<< "  MENU PRINCIPAL: "<<endl;
  cout<<"1. Mostrar sección Películas\n";
  cout<<"2. Favoritos\n";
  cout<<"3. Buscar por título\n";
  cout<<"4. Filtrar por género\n";
  cout<<"5. Cerrar Sesión\n";
  cout<<"\n";
  
}
void DisplayHelper::mostrarMensaje(const char *msg){
  cout<< msg <<endl;
  
}
void DisplayHelper::mostrarError(const char *error){
  cout<<"ERROR: "<<  error << endl;
  
}
void DisplayHelper::pausar(){
  cout<< "Presiona ENTER para continuar ...";
  cin.ignore(1000, '\n');
  cin.get();
  
  
}
