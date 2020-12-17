/** 
 * ULL
 * Facultad Ingeniería y Tecnología
 * Ingeniería Informática
 * 
 * 
 * @author Evian Concepción Peña
 * @brief El programa encripta y desencripta fichero de texto introducidos por linea de comando 
 *        usando 2 opciones:
 *        El cifrado César o XOR
 * 
 * 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#include "cripto_funciones.h"


int main(int argc, char* argv[]){
  Usage(argc, argv);
  ComprobarParametros(argv);
  string nombre_fichero_entrada{argv[1]};
  string nombre_fichero_salida{argv[2]};
  string metodo{argv[3][0]};
  string contrasena{argv[4][0]};
  /** La operación ha realizar puede ser (-), 
   * desencriptar o (+), para encriptar */
  string operacion{argv[5]}; 
  string contenido_encriptado;
  ifstream input(nombre_fichero_entrada, ifstream::in);
  stringstream buffer;
    buffer << input.rdbuf();
    string contenido{buffer.str()};
  ofstream fichero_modificado(nombre_fichero_salida, ofstream::out);
  
  /** 
   *  Condicionales que dependiendo de el metodo elegido
   *  se activa uno u otro  
   * 
  */
  if (metodo == "1"){
    contenido_encriptado  = EncriptadoXor(contenido,contrasena);
    fichero_modificado << contenido_encriptado; 
  }
  else if (metodo == "2"){
    int k = stoi(contrasena);
    if(operacion == "+"){
      contenido_encriptado = EncriptadoCesar(contenido, k);
      fichero_modificado << contenido_encriptado;
    }
    else if (operacion == "-"){
      contenido_encriptado = DesencriptadoCesar(contenido, k);
      fichero_modificado << contenido_encriptado;
    }
  
  }
  //Cuantas veces se repite la vocal a
  string a;
  char *cad = new char[vocal.length() +1];
  int contador = 0;
  char caracter = 'a';
  
  strcpy(cad, a.c_srt());
  for(int i=0; i<a.lenght(); i++){
     if(cadena[i] == caracter){
       contador++;
     }
  }
  cout << "El numero de veces que se repite a es: " << contador;

  return 0;
}
